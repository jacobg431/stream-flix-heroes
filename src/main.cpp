#include <iostream>
#include <libpq-fe.h>


int main()
{
const char* conninfo = "host=localhost port=5432 dbname=postgres user=postgres";


PGconn* conn = PQconnectdb(conninfo);


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