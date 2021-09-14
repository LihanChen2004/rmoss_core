// Copyright 2021 RoboMaster-OSS
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RM_BASE__ROBOT_BASE_EXAMPLE_HPP_
#define RM_BASE__ROBOT_BASE_EXAMPLE_HPP_

#include <thread>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "rm_base/transporter_interface.hpp"
#include "rm_base/fixed_packet_tool.hpp"
#include "rmoss_interfaces/msg/gimbal_cmd.hpp"


namespace rm_base
{

class RobotBaseExample
{
public:
  RobotBaseExample(rclcpp::Node::SharedPtr node, TransporterInterface::SharedPtr transporter);
  ~RobotBaseExample() {}

public:
  void listen_loop();

private:
  void gimbal_cmd_cb(const rmoss_interfaces::msg::GimbalCmd::SharedPtr msg);

private:
  rclcpp::Node::SharedPtr node_;
  std::unique_ptr<std::thread> listen_thread_;
  // tool
  TransporterInterface::SharedPtr transporter_;
  FixedPacketTool<16>::SharedPtr packet_tool_;
  // sub
  rclcpp::Subscription<rmoss_interfaces::msg::GimbalCmd>::SharedPtr cmd_gimbal_sub_;
};

}  // namespace rm_base

#endif  // RM_BASE__ROBOT_BASE_EXAMPLE_HPP_
