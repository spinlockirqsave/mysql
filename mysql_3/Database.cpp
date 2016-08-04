/*
 * @file    Database.cpp
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Singleton for handling of mysql connection.
 */


#include "Database.h"


CDatabase::CDatabase(std::string host, std::string user, std::string pass, std::string database, uint16_t port, std::string unix_socket, uint8_t client_flag) : host_(host), user_(user), pass_(pass), database_(database), port_(port), unix_socket_(unix_socket), client_flag_(client_flag)
{
    con_ = mysql_init(NULL);
    if (con_ == NULL)
    {
        std::cerr << mysql_error(con_) << std::endl;
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(con_,
                host_.empty() ? NULL : host_.c_str(),
                user_.empty() ? NULL : user_.c_str(),
                pass_.empty() ? NULL : pass_.c_str(),
                database_.empty() ? NULL : database_.c_str(),
                port_,
                unix_socket_.empty() ? NULL : unix_socket_.c_str(),
                client_flag) == NULL) 
    {
        std::cerr << mysql_error(con_) << std::endl;
        mysql_close(con_);
        exit(EXIT_FAILURE);
    }
    std::cerr << "Database connection opened\n";
}

CDatabase::~CDatabase()
{
    if (con_ == NULL) {
        std::cerr << "Database connection alrady closed\n";
        return;
    }
    mysql_close(con_);
    std::cerr << "Database connection closed\n";
}

bool CDatabase::executeQuery(const std::string cmd) const
{
    if (con_ == NULL || cmd.empty()) {
        return false;
    }

    if (mysql_query(con_, cmd.c_str())) 
    {
        return false;
    }
    return true;
}

std::string CDatabase::errorMessage() const
{
    if (con_ == NULL) {
        return "";
    }
    return mysql_error(con_);
}

MYSQL* CDatabase::getConnection() const
{
    return con_;
}
