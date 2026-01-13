#include <iostream>
#include <libpq-fe.h>
#include <string>
#include <sstream>
#include <limits>

int main()
{

    int port;
    std::string username;
    std::string password;

    std::cout << "Port number: ";
    std::cin >> port;

    // Discard leftover newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Username: ";
    std::getline(std::cin, username);

    std::cout << "Password: ";
    std::getline(std::cin, password);

    PGconn* conn = PQsetdbLogin(
        "localhost",
        std::to_string(port).c_str(),
        nullptr,
        nullptr,
        "postgres",
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