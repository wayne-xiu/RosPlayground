#include "ros/ros.h"
#include "ros_playground/rgb_led.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "rgb_led_pub");
    ros::NodeHandle n;
    ros::Publisher rgb_led_pub = n.advertise<ros_playground::rgb_led>("rgb_led", 1000);
    ros::Rate loop_rate(10);

    int count = 0;
    ROS_INFO("rgb_led_pub: starting to publish");
    while (ros::ok()) {
        ros_playground::rgb_led msg;
        msg.ID = count % 255;
        msg.RGB[0] = 0;
        msg.RGB[1] = 0;
        msg.RGB[2] = msg.ID;

        rgb_led_pub.publish(msg);
        loop_rate.sleep();
        ++count;
    }

    return 0;
}
