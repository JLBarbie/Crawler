#ifndef DATABASE_H
#define DATABASE_H

#include <map>

struct DBInfo {
    std::string username;
    std::string password;
    std::string host;
    std::string dbname;
};

class Database
{
public:
    Database();
    ~Database();

    dropTable();
    createTable();
    deleteTable();
    setInfos(std::string, std::string, std::string, std::string);

private:
    std::map<std::string, DB::Table> tables;
    DBInfo connection;
};

#endif // DATABASE_H
