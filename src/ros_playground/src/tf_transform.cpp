#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "tf_transform");
    ros::NodeHandle nh;
    ros::Rate rate(10.0);
    tf::TransformBroadcaster broadcaster;
    float angle = 0.0f;
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    ROS_INFO("tf_transform node started");
    while (nh.ok()) {
        x = 0.3 * cos(angle);
        y = 0.3 * sin(angle);
        z = 0.2;

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::createQuaternionFromRPY(0.0, 0.0, angle), tf::Vector3(x, y, z)),
                ros::Time::now(), "tf1", "tf3"));
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(x, y, z*2)),
                ros::Time::now(), "tf1", "tf4"));

        rate.sleep();
        angle += 0.01;
    }
}