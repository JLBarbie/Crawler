#include "crawler.h"
#include <curl/curl.h>
/**
 * NEED: C++20 avec les lib networking
 * TODO: Database
 * TODO: Multithreading
 * TODO: Partial
 */

/// Write callback for cUrl
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

/*!
   \brief "Constructor"
   \param "Boolean for verbosity"
*/
Crawler::Crawler(bool quiet) :
    _verbose(!quiet),
    _interactive(false)
{
    printInfo(INFO, "Verbosity enabled");
}

/*!
   \brief "Run the crawler"
   \return "Return"
*/
int Crawler::run()
{
    printInfo(INFO, "Start Crawler");

    int i = 0;
    while (_urls.unchecked.size() > 0 && i < 10)
    {
        spider();
        std::cout << "ON PARSE MAGLE"<< std::endl;
        i++;
    }
    return 0;
}

/*!
   \brief "Description"
   \param "Param description"
   \return "Return of the function"
*/
void Crawler::spider()
{
    std::string currentURL = getCurrentURL();

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, currentURL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        std::cout << readBuffer << std::endl;
        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    // try {

    // CDocument doc;
    // doc.parse(page.c_str());
}


/*!
   \brief "Recupere les liens dans une page"
   \param "Param description"
   \return "Return of the function"
*/
void Crawler::searchLink(std::string page) {
//    links = page.css("a").map { |link| link["href"].to_s }.uniq.sort.delete_if(&:empty?)
//    links.delete_if { |link| !link.start_with?(@config["url"], "/") }
//    links.each { |link| @db.push(link) }
}

void Crawler::searchBySelector(std::string page) {
//  data = {};
//  $config["items"].each do |key, value| {
//        if value.start_with?("input") {
//            data[key] = page.value(value).text;
//        } else if key.start_with?("dc-") {
//            if (page.css(value)[0]) {
//                data[key] = page.css(value)[0]["data-content"];
//            }
//        } else {
//            data[key] = page.css(value).text;
//        }
//    }
//    unless (data.empty?) {
//        @db.putsData(data);
//    }
}

void Crawler::searchOnTable(std::string page)
{
//    page.search("table").each do |table|
//    {
//        table.search("tr").each do |row|
//        {
//            row.search("td").each do |td|
//            {
//                @fd.print "" + td.text.strip + ", "
//            }
//            @fd.print ";\n"
//        }
//    }
}

std::string Crawler::getCurrentURL()
{
    // Recuperation et suppression du premiere element
   std::string currentURL = _urls.unchecked.front();
   _urls.unchecked.pop_front();

   if (!currentURL.empty()) {
       printInfo(DEBUG, currentURL);
   }
   return currentURL;
}

/*!
   \brief "Description"
   \param "Param description"
   \pre "Pre-conditions"
   \post "Post-conditions"
   \return "Return of the function"
*/
// Set interactivity
void Crawler::setInteractive(bool interactive)
{
    if (interactive)
    {
        printInfo(INFO, "Mode interactif");
    }
}

// Parse config from TOML
/*!
   \brief "Description"
   \param "Param description"
   \return "Return of the function"
*/
void Crawler::setConfig(std::string infile)
{
    printInfo(INFO, "Load config");

    INI::File ft;
	// Loading from file
	if (!ft.Load(infile))
	{
        printInfo(FATAL , "Config file not found");
        exit(-1);
	}
    std::string baseURL = ft.GetSection("crawler")->GetValue("website").AsString();
    _urls.unchecked.push_back(baseURL);
}

/*!
   \brief "Description"
   \param "Param description"
   \return "Return of the function"
*/
void Crawler::getItems()
{
    INI::Section* sect = ft.GetSection("items");

    for (INI::Section::values_iter it2 = sect->ValuesBegin(); it2 != sect->ValuesEnd(); ++it2)
    std::cout << "Entry name: "    << it2->first
              << ", Entry value: " << it2->second.AsString()
              << std::endl;
}

/*!
   \brief "Print information"
   \param "Param description"
   \return "Return of the function"
*/
void Crawler::printInfo(Verbosity vb, std::string msg)
{
    if (!_verbose)
        return;

    switch (vb) {
        case DEBUG:
            std::cout << "\033[35mDEBUG\033[0m : " << msg << std::endl;
            break;
        case INFO:
            std::cout << "\033[34mINFO\033[0m : "  << msg << std::endl;
            break;
        case WARNING:
            std::cout << "\033[33mWARNING\033[0m : " << msg << std::endl;
            break;
        case FATAL:
            std::cerr << "\033[31mFATAL\033[0m : " << msg << std::endl;
            break;
        default:
            break;
    }
}
