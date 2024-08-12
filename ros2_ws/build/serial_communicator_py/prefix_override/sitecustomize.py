import sys
if sys.prefix == '/Users/fergusproctor/miniforge3/envs/ros_env':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/Users/fergusproctor/dev/SLAM-robot/ros2_ws/install/serial_communicator_py'
