# stop_robot_navigation
Repository to navigate a robot in nav2 ros and create a C++ node to stop the robot. 

## Project Goal
1. Navigate a TurtleBot using Rviz using Nav2.
2. Write a C++ node that stops the robot navigation. 


### Prerequisites
- **ROS2**: Ensure you have ROS2 installed. Follow the [official ROS2 documentation](https://docs.ros.org/en/foxy/Installation.html) for installation instructions.
- **Nav2**
- **Gazebo**
  

### Installation
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/UthiraS/stop_robot_navigation.git
   cd stop_robot_navigation

2. **Build the package**
   ```sh
    colcon build


### Instructions   

1. **Set Environment Variables for Gazebo**
   ```sh
   export TURTLEBOT3_MODEL=waffle
   export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models

2. **Launch the ROS2 Navigation Stack**
   ```sh
   ros2 launch nav2_bringup tb3_simulation_launch.py headless:=False

3. **Set the initial pose by clicking the “2D Pose Estimate” button in RViz**
4. **click the “Navigaton2 Goal” button and choose a destination**
Once the robot starts navigating,

5. **Stop the robot**
   ```sh
   ros2 run robot_nav_stop stop_robot
   



<video width="320" height="240" controls>
  <source src="path/to/your/video.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>

   

