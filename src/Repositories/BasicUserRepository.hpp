#pragma once
#include "IUserRepository.hpp"
#include "GenericUserRepository.hpp"

class BasicUserRepository : public GenericUserRepository {};

BasicUserRepository::BasicUserRepository()
{
    _queryWhereClause = "WHERE subscriptionType = 'Basic'";
}

BasicUserRepository::insertUser(const User &user) override
{
    if (user.getSubscriptionType() != "Basic")
    {
        throw std::invalid_argument("Cannot insert non-basic user in BasicUserRepository");
    }
    GenericUserRepository::insertUser(user);
}

BasicUserRepository::updateUser(const User &user) override
{
    if (user.getSubscriptionType() != "Basic")
    {
        throw std::invalid_argument("Cannot update non-basic user in BasicUserRepository");
    }
    GenericUserRepository::updateUser(user);
}