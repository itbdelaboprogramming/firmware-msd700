#ifndef _ROS_ros_msd700_msgs_HardwareState_h
#define _ROS_ros_msd700_msgs_HardwareState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_msd700_msgs
{

  class HardwareState : public ros::Msg
  {
    public:
      uint32_t ch_ultrasonic_distances_length;
      typedef float _ch_ultrasonic_distances_type;
      _ch_ultrasonic_distances_type st_ch_ultrasonic_distances;
      _ch_ultrasonic_distances_type * ch_ultrasonic_distances;
      typedef int32_t _right_motor_pulse_delta_type;
      _right_motor_pulse_delta_type right_motor_pulse_delta;
      typedef int32_t _left_motor_pulse_delta_type;
      _left_motor_pulse_delta_type left_motor_pulse_delta;

    HardwareState():
      ch_ultrasonic_distances_length(0), st_ch_ultrasonic_distances(), ch_ultrasonic_distances(nullptr),
      right_motor_pulse_delta(0),
      left_motor_pulse_delta(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ch_ultrasonic_distances_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ch_ultrasonic_distances_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ch_ultrasonic_distances_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ch_ultrasonic_distances_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distances_length);
      for( uint32_t i = 0; i < ch_ultrasonic_distances_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ch_ultrasonic_distancesi;
      u_ch_ultrasonic_distancesi.real = this->ch_ultrasonic_distances[i];
      *(outbuffer + offset + 0) = (u_ch_ultrasonic_distancesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ch_ultrasonic_distancesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ch_ultrasonic_distancesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ch_ultrasonic_distancesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ch_ultrasonic_distances[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_right_motor_pulse_delta;
      u_right_motor_pulse_delta.real = this->right_motor_pulse_delta;
      *(outbuffer + offset + 0) = (u_right_motor_pulse_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_motor_pulse_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_motor_pulse_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_motor_pulse_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_motor_pulse_delta);
      union {
        int32_t real;
        uint32_t base;
      } u_left_motor_pulse_delta;
      u_left_motor_pulse_delta.real = this->left_motor_pulse_delta;
      *(outbuffer + offset + 0) = (u_left_motor_pulse_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_motor_pulse_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_motor_pulse_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_motor_pulse_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_motor_pulse_delta);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t ch_ultrasonic_distances_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ch_ultrasonic_distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ch_ultrasonic_distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ch_ultrasonic_distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ch_ultrasonic_distances_length);
      if(ch_ultrasonic_distances_lengthT > ch_ultrasonic_distances_length)
        this->ch_ultrasonic_distances = (float*)realloc(this->ch_ultrasonic_distances, ch_ultrasonic_distances_lengthT * sizeof(float));
      ch_ultrasonic_distances_length = ch_ultrasonic_distances_lengthT;
      for( uint32_t i = 0; i < ch_ultrasonic_distances_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ch_ultrasonic_distances;
      u_st_ch_ultrasonic_distances.base = 0;
      u_st_ch_ultrasonic_distances.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ch_ultrasonic_distances.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ch_ultrasonic_distances.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ch_ultrasonic_distances.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ch_ultrasonic_distances = u_st_ch_ultrasonic_distances.real;
      offset += sizeof(this->st_ch_ultrasonic_distances);
        memcpy( &(this->ch_ultrasonic_distances[i]), &(this->st_ch_ultrasonic_distances), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_right_motor_pulse_delta;
      u_right_motor_pulse_delta.base = 0;
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_motor_pulse_delta = u_right_motor_pulse_delta.real;
      offset += sizeof(this->right_motor_pulse_delta);
      union {
        int32_t real;
        uint32_t base;
      } u_left_motor_pulse_delta;
      u_left_motor_pulse_delta.base = 0;
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_motor_pulse_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_motor_pulse_delta = u_left_motor_pulse_delta.real;
      offset += sizeof(this->left_motor_pulse_delta);
     return offset;
    }

    virtual const char * getType() override { return "ros_msd700_msgs/HardwareState"; };
    virtual const char * getMD5() override { return "175a063e8d408168abc6b783eb7af198"; };

  };

}
#endif
