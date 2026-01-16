#pragma once
#include "IUserRepository.hpp"
#include "../Database/DbConnection.hpp"

class GenericUserRepository : public IUserRepository
{
public:
    GenericUserRepository(DbConnection &dbConnection);

    User selectUserById(int id) const override;

    User selectUserByName(const std::string &firstName, const std::string &lastName) const override;

    std::vector<User> selectMultipleUsers(int amount, int offset) const override;

    void insertUser(const User &user) override;

    void updateUser(const User &user) override;

    int countUsers() const override;

private:
    std::string _subscriptionType;
    DbConnection &_dbConnection;
};
