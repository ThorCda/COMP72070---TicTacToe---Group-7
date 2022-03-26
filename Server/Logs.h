#pragma once

#include <fstream>
#include <iostream>
#include <ctime>

 class Logs {


public:
   static  const  char* error_file;
      static  const  char* game_file;
    static const   char* conn_file;

public:
    static void write(int error_code);
    static void init();

};
