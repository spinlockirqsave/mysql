/*
 * @file    GameActTypesDbQuery.cpp
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Concrete query: fetch/extract all the log lines for a date time value passed as a string parameter and a given AccountID (passed as string parameter as well). Log lines will be returned a single string having them separated by ";" character. The log lines must be generated by replacing the place-holders in GameActionsTypes.GameActionLogText with the "paramaters" read from GameActionsLog.GameActionParameters.
 */


#include "GameActTypesDbQuery.h"


CGameActTypesDbQuery::CGameActTypesDbQuery(MYSQL *con) : con_(con)
{
    if (con == NULL)
    {
        throw CGameActTypesDbQueryInitException();
    }
}

std::string CGameActTypesDbQuery::executeQuery(const std::string& dt, const std::string& accountId)
{
    std::string result;
    MYSQL_RES *mysql_result;
    std::stringstream ss;

    if (mysql_query(con_, "SELECT * FROM GameActionsTypes`"))
    {
        ss << "Database command execution failed with error [" << mysql_error(con_) <<  "]";
        throw CGameActTypesDbQueryExecuteQueryException(ss.str().c_str());
    }
    
    mysql_result = mysql_store_result(con_);
    if (mysql_result == NULL)
    {
        ss << "Database command execution failed with error [" << mysql_error(con_) << "]";
        throw CGameActTypesDbQueryExecuteQueryException(ss.str().c_str());
    }

    int num_fields = mysql_num_fields(mysql_result);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(mysql_result))) 
    {
        for (int i = 0; i < num_fields; i++)
        {
            result += (row[i] ? row[i] : "");
        }
    }

    mysql_free_result(mysql_result);
    return result;
}
