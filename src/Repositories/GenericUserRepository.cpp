#include "GenericUserRepository.hpp"
#include "../Database/DbConnection.hpp"

GenericUserRepository::GenericUserRepository(DbConnection &dbConnection) : _dbConnection(dbConnection)
{
    _queryWhereClause = std::string("");
}

User GenericUserRepository::selectUserById(int id) const
{
    std::string query = std::string("")
                        + "SELECT FirstName, LastName, UserId, Email, SubscriptionType, DateJoined "
                        + "FROM Users "
                        + "WHERE UserId = " + std::to_string(id) + " " 
                        + _queryWhereClause + ";";
                        
    PGresult *result = _dbConnection.Execute(query);

    // (Only one column for each userId)
    std::string firstName = PQgetvalue(result, 0, 0);
    std::string lastName = PQgetvalue(result, 0, 1);
    int userId = std::stoi(PQgetvalue(result, 0, 2));
    std::string email = PQgetvalue(result, 0, 3);
    std::string subscriptionType = PQgetvalue(result, 0, 4);

    User user(firstName, lastName, userId, email, subscriptionType);

    return user;
}

User GenericUserRepository::selectUserByName(const std::string &firstName, const std::string &lastName) const
{
    std::string query = std::string("")
                        + "SELECT \"UserId\", \"Email\", \"SubscriptionType\", \"DateJoined\" "
                        + "FROM \"Users\" " 
                        + "WHERE \"FirstName\" = '" + firstName + "' "
                        + "AND \"LastName\" = '" + lastName + "' "
                        + _queryWhereClause + ";";

    std::cout << "Debug: Executed query to select user by name: " << query << std::endl;

    PGresult *result = _dbConnection.Execute(query);

    int userId = std::stoi(PQgetvalue(result, 0, 0));

    std::cout << "Debug: Retrieved userId " << userId << " for name " << firstName << " " << lastName << std::endl;

    std::string email = PQgetvalue(result, 0, 1);
    std::string subscriptionType = PQgetvalue(result, 0, 2);
    std::string dateJoined = PQgetvalue(result, 0, 3);
    
    User user(firstName, lastName, userId, email, subscriptionType);

    PQclear(result);

    return user;
}

std::vector<User> GenericUserRepository::selectMultipleUsers(int amount, int offset) const
{
    std::string query = std::string("")
                        + "SELECT FirstName, LastName, UserId, Email, SubscriptionType, DateJoined "
                        + "FROM Users " + _queryWhereClause + " "
                        + "LIMIT " + std::to_string(amount) + " "
                        + "OFFSET " + std::to_string(offset) + ";";

    PGresult *result = _dbConnection.Execute(query);

    std::vector<User> users;
    int rows = PQntuples(result);

    for (int i = 0; i < rows; ++i)
    {
        std::string firstName = PQgetvalue(result, i, 0);
        std::string lastName = PQgetvalue(result, i, 1);
        int userId = std::stoi(PQgetvalue(result, i, 2));
        std::string email = PQgetvalue(result, i, 3);
        std::string subscriptionType = PQgetvalue(result, i, 4);
        std::string dateJoined = PQgetvalue(result, i, 5);
        User user(firstName, lastName, userId, email, subscriptionType);
        users.push_back(user);
    }

    return users;
}

void GenericUserRepository::insertUser(const User &user)
{
    std::string query = std::string("")
                        + "INSERT INTO Users (FirstName, LastName, UserId, Email, SubscriptionType, DateJoined) "
                        + "VALUES ('" + user.getFirstName() 
                        + "', '" + user.getLastName() 
                        + "', " + std::to_string(user.getId())
                        + ", '" + user.getEmail()
                        + "', '" + user.getSubscriptionType() + "', NOW());";

    _dbConnection.Execute(query);
}

void GenericUserRepository::updateUser(const User &user)
{
    std::string query = std::string("") 
                        + "UPDATE Users SET " 
                        + "FirstName = '" + user.getFirstName() + "', " 
                        + "LastName = '" + user.getLastName() + "', "
                        + "Email = '" + user.getEmail() + "', " 
                        + "SubscriptionType = '" + user.getSubscriptionType() + "' " + "WHERE UserId = " + std::to_string(user.getId()) + ";";

    _dbConnection.Execute(query);
}

int GenericUserRepository::countUsers() const
{
    std::string query = std::string("") + "SELECT COUNT(*) FROM Users " + _queryWhereClause + ";";
    PGresult *result = _dbConnection.Execute(query);

    int counts = std::stoi(PQgetvalue(result, 0, 0));

    return counts;
}
