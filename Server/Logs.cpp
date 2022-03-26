// ifstream is used for reading files
    // We'll read from a file called Sample.txt
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <ctime>
#include "Logs.h"
#include <string>

const char* Logs::error_file = "error_logs.txt";
const char* Logs::game_file = "game_log.txt";
const  char* Logs::conn_file = "conn_log.txt";


    /// <summary>
    /// Write an error code to the log file
    /// </summary>
    /// <param name="error_code">Integer of the errror code.</param>
    void Logs::write(int error_code)
    {
        

        //String error = getErrorCode(errorCode);
       const char* error = "Hello";

        std::ofstream outf{ Logs::error_file };

        if (!outf)
        {

            std::cerr << "Critical Error! Cannot open error_log.txt. \n";
            exit(1);
        }

        time_t now = time(0);

        std::cout << ctime(&now) << "\tError code: " << error_code << " Error: " << error << '\n';
        outf << ctime(&now) << "\tError code: " << error_code << " Error: " << error << '\n';

        outf.close();
    }


