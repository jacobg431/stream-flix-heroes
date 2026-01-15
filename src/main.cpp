#include <iostream>
#include <libpq-fe.h>
#include <string>
#include <sstream>
#include <limits>


void ReadAllUsers(); 



int main()
{

    int port;
    std::string username;
    std::string password;
    std::string database;

    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    std::cout << "Database: ";
    std::getline(std::cin, database);

    PGconn* conn = PQsetdbLogin(
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        database.c_str(),
        username.c_str(),
        password.c_str()
    );

    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cerr << "Connection failed: " << PQerrorMessage(conn);
        PQfinish(conn);
        return 1;
    }

    std::cout << "Connected to PostgreSQL successfully." << std::endl;

    PQfinish(conn);
    return 0;

}


void ReadAllUsers(){
    
}