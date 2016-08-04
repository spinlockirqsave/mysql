/*
 * @file    Database.h
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Singleton for handling of mysql connection.
 */

#ifndef CDATABASE_H
#define CDATABASE_H


#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>

#include <my_global.h>
#include <mysql.h>


class CDatabase
{
    public:
        bool executeQuery(const std::string cmd) const;
        std::string errorMessage() const;
        MYSQL* getConnection() const;
        static const CDatabase db_;

    private:
        CDatabase(std::string host, std::string user, std::string pass,
                std::string database, uint16_t port, std::string unix_socket, uint8_t client_flag);
        CDatabase(CDatabase const &other);
        CDatabase& operator=(CDatabase const &other);
        ~CDatabase();
        
        MYSQL *con_;
        std::string host_, user_, pass_, database_;
        uint16_t port_;
        std::string unix_socket_;
        uint8_t client_flag_;
};


#endif  /* CDATABASE_H */
