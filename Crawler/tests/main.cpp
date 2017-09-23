#include "HTML.hpp"
#include <iostream>

void crawler_test() {
    WebParser::HTML *crawler = new WebParser::HTML("http://webscraper.io/test-sites/e-commerce/allinone"); // ou WebParser(String url)
    crawler->run();
}

int main(int argc, char const *argv[]) {
//    crawler_init();
    crawler_test();
}

void usage() {
    std::cout << "Crawler" << std::endl;
}

//void crawler_init() {
//    WebParser::HTML *crawler = new WebParser::HTML(); // ou WebParser(String url)

//    crawler->loadConfig("../config.json");
//    crawler->setUrl("...");
//    crawler->setOutput("Output::file"); // CSV
//    // crawler->setOutput("Output::database");
//    // crawler->setOutput("Output::noOutput");
//    // crawler->setOutput("Output::debug");
    
//    WebParser::Database *db = new WebParser::Database();
//    db->setPassword();
//    db->setUsername();
//    db->setDatabase();
//    /// OU
////    db->connect(..., ..., ..., ...);

//    db->generateTable();        /// generate Table (data)

//    crawler->setDatabase(db);   /// set Database for crawler

//    crawler->run();             /// Run main loop
//    return 0;
//}



/// TODO
/// MultiThread
/// crawler Table
/// Debug
/// user-Agent
/// Sleeper
/// Partial (url substring) ?? REGEX ??
/// config checker (like nginx -t)
///
