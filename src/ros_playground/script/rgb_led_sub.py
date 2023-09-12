#! /usr/bin/env python3

import rospy
from ros_playground.msg import rgb_led

def callback(data):
    loginfo = "LED ID is: " + str(data.ID) + " R=" + str(data.RGB[0]) + " G=" + str(data.RGB[1]) + " B=" + str(data.RGB[2])
    rospy.loginfo(loginfo)

def rgb_led_subscribe():
    rospy.init_node('rgb_listener', anonymous=True)
    rospy.loginfo('Start subscribe rbg_led topic')
    rospy.Subscriber("rgb_led", rgb_led, callback)
    rospy.spin()

if __name__ == '__main__':
    rgb_led_subscribe()