#include <iostream>
#include <libpq-fe.h>
#include <string>
#include <sstream>
#include <limits>
#include "Database/DbConnection.hpp"
#include "Services/StreamflixService.hpp"
#include "Repositories/GenericUserRepository.hpp"
#include "Repositories/GenericMovieRepository.hpp"
#include "Models/Movie.hpp"

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

    DbConnection dbConnection(username, password, database);
    GenericMovieRepository movieRepository(dbConnection);
    GenericUserRepository userRepository(dbConnection);

    StreamflixService service(userRepository, movieRepository);

    std::cout << "Connected to database successfully." << std::endl;

    User user = service.getUserByName("Alice", "Johnson");

    std::cout << "User Retrieved: " << user.getName() << ", Email: " << user.getEmail() << std::endl;

    return 0;
}