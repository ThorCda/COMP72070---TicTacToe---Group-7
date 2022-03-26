#pragma once

#include <fstream>
#include <iostream>
#include <ctime>

enum ACTION_TYPE
{
    not_defined, send, receive
};
 class Logs {


public:
   static  const  char* error_file;
      static  const  char* game_file;
    static const   char* conn_file;

public:
    static void write(int system_state, int error_code);
    static void write(bool connectin_status, int action_type, char* buffer);

};
