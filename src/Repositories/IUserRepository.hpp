#pragma once
#include "../Models/User.hpp"
#include "../Models/Movie.hpp"

class IUserRepository
{
public:
    virtual ~IUserRepository() = default;

    virtual User selectUserById(int id) const = 0;

    virtual User selectUserByName(const std::string &firstName, const std::string &lastName) const = 0;

    virtual std::vector<User> selectMultipleUsers(int amount, int offset) const = 0;

    virtual void insertUser(const User &user) = 0;

    virtual void updateUser(const User &user) = 0;

    virtual int countUsers() const = 0;

protected:
    std::string _queryWhereClause;
};