#ifndef ROS_CONTROLLER1_DM__VISIBILITY_CONTROL_H_
#define ROS_CONTROLLER1_DM__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROS_CONTROLLER1_DM_EXPORT __attribute__ ((dllexport))
    #define ROS_CONTROLLER1_DM_IMPORT __attribute__ ((dllimport))
  #else
    #define ROS_CONTROLLER1_DM_EXPORT __declspec(dllexport)
    #define ROS_CONTROLLER1_DM_IMPORT __declspec(dllimport)
  #endif
  #ifdef ROS_CONTROLLER1_DM_BUILDING_LIBRARY
    #define ROS_CONTROLLER1_DM_PUBLIC ROS_CONTROLLER1_DM_EXPORT
  #else
    #define ROS_CONTROLLER1_DM_PUBLIC ROS_CONTROLLER1_DM_IMPORT
  #endif
  #define ROS_CONTROLLER1_DM_PUBLIC_TYPE ROS_CONTROLLER1_DM_PUBLIC
  #define ROS_CONTROLLER1_DM_LOCAL
#else
  #define ROS_CONTROLLER1_DM_EXPORT __attribute__ ((visibility("default")))
  #define ROS_CONTROLLER1_DM_IMPORT
  #if __GNUC__ >= 4
    #define ROS_CONTROLLER1_DM_PUBLIC __attribute__ ((visibility("default")))
    #define ROS_CONTROLLER1_DM_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define ROS_CONTROLLER1_DM_PUBLIC
    #define ROS_CONTROLLER1_DM_LOCAL
  #endif
  #define ROS_CONTROLLER1_DM_PUBLIC_TYPE
#endif
#endif  // ROS_CONTROLLER1_DM__VISIBILITY_CONTROL_H_
// Generated 12-Nov-2024 09:50:16
// Copyright 2019-2020 The MathWorks, Inc.
