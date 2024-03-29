#ifndef _ROS_SERVICE_ProcessFile_h
#define _ROS_SERVICE_ProcessFile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace grid_map_msgs
{

static const char PROCESSFILE[] = "grid_map_msgs/ProcessFile";

  class ProcessFileRequest : public ros::Msg
  {
    public:
      typedef const char* _file_path_type;
      _file_path_type file_path;
      typedef const char* _topic_name_type;
      _topic_name_type topic_name;

    ProcessFileRequest():
      file_path(""),
      topic_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      uint32_t length_topic_name = strlen(this->topic_name);
      varToArr(outbuffer + offset, length_topic_name);
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
      uint32_t length_topic_name;
      arrToVar(length_topic_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
     return offset;
    }

    virtual const char * getType() override { return PROCESSFILE; };
    virtual const char * getMD5() override { return "d33bd97bc9ab242541cf320304eff29e"; };

  };

  class ProcessFileResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ProcessFileResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return PROCESSFILE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ProcessFile {
    public:
    typedef ProcessFileRequest Request;
    typedef ProcessFileResponse Response;
  };

}
#endif
