/*
 * @file    main.cpp
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Example program using CGameActTypesDbQuery.
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

    try
    {
        query = new CGameActTypesDbQuery(CDatabase::db_.getConnection());
        res = query->executeQuery("2015-03-18 14:31:00", "1521741739113", "#", "::", ";");
        std::cerr << "Query result:\n[" << res << "]\n";
    } catch (std::exception &e)
    {
        std::cerr << "Exception catched [" << e.what() << "]\n";
        exit(EXIT_FAILURE);
    }

    delete query;
    exit(EXIT_SUCCESS);
}
