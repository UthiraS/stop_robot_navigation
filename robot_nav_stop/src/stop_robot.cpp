#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp/time.hpp"


class NavigationClient : public rclcpp::Node
{
public:
  using NavigateToPoseAction = nav2_msgs::action::NavigateToPose;
  using GoalHandleNavigateToPose = rclcpp_action::ClientGoalHandle<NavigateToPoseAction>;
  rclcpp_action::Client<NavigateToPoseAction>::SharedPtr action_client_;

  explicit NavigationClient() : Node("navigation_goal_sender")
  {
    // Create the action client
    this->action_client_ = rclcpp_action::create_client<NavigateToPoseAction>(this, "navigate_to_pose");
  }

  void cancelAllGoals()
  {
    // Check if the action server is available
    RCLCPP_INFO(get_logger(), "Waiting for the action server...");
    if (!this->action_client_->wait_for_action_server())
    {
      RCLCPP_INFO(get_logger(), "Action server not available");
      return;
    }
    RCLCPP_INFO(get_logger(), "Action server is available");

    // Send the cancel goal request
    auto cancel_future = action_client_->async_cancel_all_goals();
    auto cancel_result = cancel_future.wait_for(std::chrono::seconds(5));

    if (cancel_result == std::future_status::ready)
    {
       RCLCPP_INFO(get_logger(), "Failed to send cancel goal request");
    }
    else
    {
      RCLCPP_INFO(get_logger(), "Cancel goal request sent successfully");
    }
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<NavigationClient>();
  node->cancelAllGoals();
  rclcpp::spin_some(node->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}
