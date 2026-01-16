#include "DbConnection.hpp"

DbConnection::DbConnection(const std::string &database, const std::string &username, const std::string &password)
{
    _connection = PQsetdbLogin(
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        database.c_str(),
        username.c_str(),
        password.c_str());

    if (PQstatus(_connection) != CONNECTION_OK)
    {
        PQfinish(_connection);
        throw std::runtime_error("Database connection failed");
    }

    std::cout << "Connected to PostgreSQL successfully." << std::endl;
}

PGresult *DbConnection::Execute(const std::string &sql)
{
    PGresult *res = PQexec(_connection, sql.c_str());

    if (!res)
        throw std::runtime_error("PQexec returned null");

    ExecStatusType status = PQresultStatus(res);

    if (status != PGRES_TUPLES_OK && status != PGRES_COMMAND_OK)
    {
        std::string error = PQerrorMessage(_connection);
        PQclear(res);
        throw std::runtime_error("Postgres error: " + error);
    }

    return res;
}