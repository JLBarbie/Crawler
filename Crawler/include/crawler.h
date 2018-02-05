#ifndef CRAWLER_H
#define CRAWLER_H

#include <list>
#include <iostream>
#include "config.hpp"

class Database {};

struct UrlContainer
{
    std::list<std::string> unchecked;
    std::list<std::string> checked;
};

class Crawler
{
    enum Verbosity {
        DEBUG, INFO, WARNING, FATAL
    };

public:
    Crawler(bool quiet);
    int run();

    // TODO REVOIR LES METHODES
    void searchLink(std::string page);
    void searchBySelector(std::string page);
    void searchOnTable(std::string page);

    // Accessors
    void setInteractive(bool interactive);
    void setQuiet(bool quiet);
    void setConfig(std::string config);

    void getItems(); // TODO : renommer la methode

    void printInfo(Verbosity, std::string msg);

private:
    std::string getCurrentURL();
    void spider();

private:
    UrlContainer _urls;

    bool _verbose;
    bool _interactive;

    INI::File ft;

    Database *db;
};

#endif // CRAWLER_H
