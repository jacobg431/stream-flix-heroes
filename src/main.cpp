#include <iostream>
#include <libpq-fe.h>


int main()
{
const char* conninfo = "host=localhost port=5432 dbname=cpp_demo user=postgres password=YOUR_PASSWORD";


PGconn* conn = PQconnectdb(conninfo);


if (PQstatus(conn) != CONNECTION_OK)
{
std::cerr << "Connection failed: " << PQerrorMessage(conn);
PQfinish(conn);
return 1;
}


PGresult* res = PQexec(conn, "SELECT id, name FROM users");


if (PQresultStatus(res) != PGRES_TUPLES_OK)
{
std::cerr << "Query failed: " << PQerrorMessage(conn);
PQclear(res);
PQfinish(conn);
return 1;
}


int rows = PQntuples(res);
for (int i = 0; i < rows; ++i)
{
std::cout << "ID: " << PQgetvalue(res, i, 0)
<< ", Name: " << PQgetvalue(res, i, 1) << '\n';
}


PQclear(res);
PQfinish(conn);
return 0;
}