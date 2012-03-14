/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _MOVEIT_VISUALIZER_H_
#define _MOVEIT_VISUALIZER_H_

#include <ros/ros.h>
#include <moveit_visualization_ros/interactive_object_visualization_qt_wrapper.h>
#include <moveit_visualization_ros/interactive_object_visualization_widget.h>
#include <moveit_visualization_ros/planning_group_selection_menu.h>
#include <moveit_visualization_ros/planning_scene_file_menu.h>
#include <moveit_visualization_ros/planning_visualization_qt_wrapper.h>
#include <moveit_visualization_ros/kinematic_state_joint_state_publisher.h>
#include <trajectory_execution_ros/trajectory_execution_monitor_ros.h>

#include <OGRE/OgreLogManager.h>
#include <rviz/visualization_panel.h>
#include <rviz/visualization_manager.h>

namespace moveit_visualization_ros {

class MoveItVisualizer {

public:

  MoveItVisualizer();

  ~MoveItVisualizer();

  virtual void updatePlanningScene(planning_scene::PlanningSceneConstPtr planning_scene);

  void updateToCurrentState();

  bool doneWithExecution();

  void executeLastTrajectory();

protected:

  void updateSceneCallback();

  void publisherFunction();

  bool first_update_;

  ros::Publisher vis_marker_array_publisher_;
  ros::Publisher vis_marker_publisher_;

  rviz::VisualizationPanel* rviz_frame_;
  QWidget* main_window_;
  PlanningGroupSelectionMenu* planning_group_selection_menu_;  

  planning_scene::PlanningSceneConstPtr current_diff_;

  boost::shared_ptr<interactive_markers::InteractiveMarkerServer> interactive_marker_server_;
  boost::shared_ptr<KinematicStateJointStatePublisher> joint_state_publisher_;
  boost::shared_ptr<planning_scene_monitor::PlanningSceneMonitor> planning_scene_monitor_;
  boost::shared_ptr<PlanningVisualizationQtWrapper> pv_;
  boost::shared_ptr<InteractiveObjectVisualizationQtWrapper> iov_;
  boost::shared_ptr<trajectory_execution::TrajectoryExecutionMonitor> trajectory_execution_monitor_;
  boost::shared_ptr<kinematics_plugin_loader::KinematicsPluginLoader> kinematics_plugin_loader_;


};

}

#endif