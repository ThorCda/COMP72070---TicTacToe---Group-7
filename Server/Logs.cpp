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
    /// <param name="error_code">Error Code: Integer of the errror code.</param>
    /// <param name="system_state">System State: Current state of the system.</param>
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

        outf << ctime(&now) << "\tError code: " << error_code << " Error Desc: " << error << " System State: "<< system_state <<'\n';

        outf.close();
    }

    /// <summary>
    /// Writes to the connection logs 
    /// </summary>
    /// <param name="connection_status">Connestion Status: True if connected</param>
    /// <param name="action_type">Action Types: Defines what send or receive call is used (enum)</param>
    /// <param name="buffer">Buffer: Serialized buffer of data</param>
    void Logs::write(bool connection_status, ACTION_TYPE action_type, char* buffer)
    {

        std::ofstream outf{ Logs::conn_file };

        if (!outf)
        {

            std::cerr << "Critical Error! Cannot open conn_file.txt. \n";
            exit(1);
        }

        time_t now = time(0);

        outf << ctime(&now) << "\tConnection Status: " << connection_status << " Action: " << action_type << "\n\tBuffer: " << buffer << '\n';

        outf.close();
    }

    /// <summary>
    /// Writes to the game log files.
    /// </summary>
    /// <param name="gameID">GameID: ID of the game</param>
    /// <param name="move">Move: Integer of the move</param>
    /// <param name="username">:Username: Username of the player</param>
    /// <param name="status">Status: Match status (enum)</param>
    void Logs::write(int gameID, int move, char* username, MATCH_STATUS status) {
        std::ofstream outf{ Logs::game_file };

        if (!outf)
        {

            std::cerr << "Critical Error! Cannot open game_file.txt. \n";
            exit(1);
        }

        time_t now = time(0);

        outf << ctime(&now) << "\tGameID: " << gameID << " Move: " << move << " Username: " << username << " Status: " << status << '\n';

        outf.close();
    }

    void Logs::read(FILE_TYPE type) {

        const char* file;

        switch (type)
        {
        case 0:
            file = Logs::error_file;
            break;
        case 1:
            file = Logs::conn_file;
            break;
        case 2:
            file = Logs::game_file;
            break;

        default:
            return;
            break;
        }
        
        std::ifstream inf{ file };

        if (!inf)
        {
            std::cerr << "Error! Issue reading file.\n";
           
        }

        while (inf)
        {
            std::string strInput;
            std::getline(inf, strInput);
            std::cout << strInput << '\n';
        }

        inf.close();

    }

    

