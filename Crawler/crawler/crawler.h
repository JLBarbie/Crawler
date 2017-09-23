#ifndef CRAWLER_H
#define CRAWLER_H

#include <map>

class Database {};

struct UrlCurrent
{
    std::string url_check;
    size_t url_id;
};

class Crawler
{
public:
    Crawler();
    int run();

private:
    int spider(size_t padding = 0);

private:
    std::map<std::string, std::string> config;
    Database *db;
};

#endif // CRAWLER_H
