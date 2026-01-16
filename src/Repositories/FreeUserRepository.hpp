#pragma once
#include "IUserRepository.hpp"
#include "GenericUserRepository.hpp"

class FreeUserRepository : public GenericUserRepository {};

FreeUserRepository::FreeUserRepository()
{
    _queryWhereClause = "WHERE subscriptionType = 'Free'";
}

FreeUserRepository::insertUser(const User &user) override
{
    if (user.getSubscriptionType() != "Free")
    {
        throw std::invalid_argument("Cannot insert non-free user in FreeUserRepository");
    }
    GenericUserRepository::insertUser(user);
}

FreeUserRepository::updateUser(const User &user) override
{
    if (user.getSubscriptionType() != "Free")
    {
        throw std::invalid_argument("Cannot update non-free user in FreeUserRepository");
    }
    GenericUserRepository::updateUser(user);
}