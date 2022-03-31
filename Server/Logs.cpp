#define _CRT_SECURE_NO_WARNINGS

#include "Logs.h"

const char* Logs::error_file = "_error_logs.txt";
const char* Logs::game_file = "_game_log.txt";
const  char* Logs::conn_file = "_conn_log.txt";


    /// <summary>
    /// Write an error code to the log file
    /// </summary>
    /// <param name="error_code">Error Code: Integer of the errror code.</param>
    /// <param name="system_state">System State: Current state of the system.</param>
    void Logs::write(int system_state, ERROR_CODE error_code)
    {
        
        std::string error = Logs::lookUpError(error_code);
       

        std::ofstream outf(Logs::error_file, std::ios::app);


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

        std::ofstream outf(Logs::conn_file, std::ios::app);


        if (!outf)
        {

            std::cerr << "Critical Error! Cannot open conn_file.txt. \n";
            exit(1);
        }

        time_t now = time(0);

        std::string type = Logs::lookUpActionType(action_type);       

        outf << ctime(&now) << "\tConnection Status: " << connection_status << " Action: " << type << "\n\tBuffer: ";
        if (buffer != NULL) {
            outf.write(buffer, strlen(buffer));
            
        }
        
        outf << '\n';

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
        std::ofstream outf(Logs::game_file, std::ios::app);

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
        case 1:
            file = Logs::error_file;
            break;
        case 2:
            file = Logs::conn_file;
            break;
        case 3:
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

    /// <summary>
    /// Generates the the error description
    /// </summary>
    /// <param name="error_code"Error Code: Integer of the error code.></param>
    /// <returns>A string of the description of error code.</returns>
    std::string Logs::lookUpError(ERROR_CODE error_code) {
        switch (error_code)
        {
        case 0:
            return "Error in logging in";
        case 1:
            return "Error in creating the account";
        case 2:
            return "Quit Error";
        case 3:
            return "Connecting error";
        case 4:

            return "Error with the move";
        case 5:
            return "Error with the avatar image";


        default:return "Function not defined...";
            break;
        }

        
    }

    std::string Logs::lookUpActionType(ACTION_TYPE action_type) {
        switch (action_type)
        {
        case 0:
            return "Action not defined";
        case 1:
            return "Sending the buffer";
        case 2:
            return "Receving the buffer";
        case 3:
            return "Connected socket";
        case 4:

            return "Disconnected socket";
        case 5:
            return "Sending the photo";
        default: return "Function not defined...";
            break;
        }

       

    }

