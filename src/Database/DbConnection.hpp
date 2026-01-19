#pragma once
#include <string>
#include <stdexcept>
#include <libpq-fe.h>
#include <iostream>

class DbConnection
{
public:
    explicit DbConnection(const std::string &database, const std::string &username, const std::string &password);

    PGresult* Execute(const std::string &sql);

    void ExecCommand(const std::string &sql);

private:
    PGconn* _connection;

};