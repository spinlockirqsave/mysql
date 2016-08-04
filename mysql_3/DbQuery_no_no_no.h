/*
 * @file    DbQuery.h
 * @author  Piotr Gregor <piotrek.gregor gmail com>
 * @brief   Abstract base class for derivation of database queries.
 */


class MYSQL;

class CDbQuery
{
    public:
        explicit CDbQuery(MYSQL *con);
        virtual std::string executeQuery(const std::string cmd) = 0;
        virtual ~CDbQuery() {}
};
