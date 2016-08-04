/*
 * @file    main.cpp
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Usage of mysql.
 */


#include <iostream>
#include <string>
#include <stdint.h>


#include "Database.h"
#include "GameActTypesDbQuery.h"


const CDatabase CDatabase::db_("localhost", "root", "root", "test1", 0, std::string(), 0);

int main(int argc, char **argv)
{
    CGameActTypesDbQuery *query;
    std::string res;

    /*if (CDatabase::db_.executeQuery("SELECT * FROM GameActionsTypes") == false)
    {
        std::cerr << "Database command failed with error [" << CDatabase::db_.errorMessage() << "]\n";
        exit(EXIT_FAILURE);
    }
    std::cerr << "Database query OK\n";*/
    try
    {
        query = new CGameActTypesDbQuery(CDatabase::db_.getConnection());
        res = query->executeQuery("x", "y");
        std::cerr << "Query result:\n" << res << std::endl;
    } catch (std::exception &e)
    {
        std::cerr << "Exception catched [" << e.what() << "]\n";
        exit(EXIT_FAILURE);
    }

    delete query;
    exit(EXIT_SUCCESS);
}
