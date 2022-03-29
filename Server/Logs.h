#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>


 class Logs {

      static const char* error_file;
      static const char* game_file;
      static const char* conn_file;

 private:
     static std::string lookUpError(int error_code);

public:
    static void write(int system_state, ERROR_CODE error_code);
    static void write(bool connectin_status, ACTION_TYPE action_type, char* buffer);
    static void write(int gameID, int move, char* username, MATCH_STATUS status);
    static void read(FILE_TYPE type);

};
