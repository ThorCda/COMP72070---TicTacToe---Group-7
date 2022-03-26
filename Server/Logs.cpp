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
    /// <param name="system_state">Current state of the system.</param>
    void Logs::write(int system_state, int error_code)
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
        outf << ctime(&now) << "\tError code: " << error_code << " Error Desc: " << error << " System State: "<< system_state <<'\n';

        outf.close();
    }

    /// <summary>
    /// Writes connection logs 
    /// </summary>
    /// <param name="connection_status">True if the client is connected</param>
    /// <param name="action_type">not_defined or buf_send or buf_recevice</param>
    /// <param name="buffer">Buffer of data</param>
    void Logs::write(bool connection_status, ACTION_TYPE action_type, char* buffer)
    {

        std::ofstream outf{ Logs::conn_file };

        if (!outf)
        {

            std::cerr << "Critical Error! Cannot open conn_file.txt. \n";
            exit(1);
        }

        time_t now = time(0);

        std::cout << ctime(&now) << "\tConnection Status: " << connection_status << " Action: " << action_type << "\n\tBuffer: " << buffer << '\n';
        outf << ctime(&now) << "\tConnection Status: " << connection_status << " Action: " << action_type << "\n\tBuffer: " << buffer << '\n';

        outf.close();
    }

    void Logs::write(int gameID, int move, char* username, MATCH_STATUS status) {
        std::ofstream outf{ Logs::game_file };

        if (!outf)
        {

            std::cerr << "Critical Error! Cannot open game_file.txt. \n";
            exit(1);
        }

        time_t now = time(0);

        std::cout << ctime(&now) << "\tGameID: " << gameID << " Move: " << move << " Username: " << username << " Status: " << status << '\n';
        outf << ctime(&now) << "\tGameID: " << gameID << " Move: " << move << " Username: " << username << " Status: " << status << '\n';

        outf.close();
    }

    

