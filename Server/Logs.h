#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

enum ACTION_TYPE
{
    type_not_defined, buf_send, buf_receive
};

enum MATCH_STATUS
{
     status_not_defined, playing, ended
};

enum FILE_TYPE
{
    error_log, game_log, conn_log
};
 class Logs {


public:
      static const char* error_file;
      static const char* game_file;
      static const char* conn_file;

public:
    static void write(int system_state, int error_code);
    static void write(bool connectin_status, ACTION_TYPE action_type, char* buffer);
    static void write(int gameID, int move, char* username, MATCH_STATUS status);
    static void read(FILE_TYPE type);

};