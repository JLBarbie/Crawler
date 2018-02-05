#include "crawler.h"
#include "clipp.hpp"

using namespace clipp;

bool isValid(bool interactive, std::string infile) {
    if (interactive && infile != "")
      return false;
    else if (!interactive && infile == "")
      return false;
    return true;
}

int main(int argc, char **argv)
{
    bool help     = false;
    bool quiet    = false;
    bool version  = false;
    bool interactive   = false;
    std::string infile = "";

    auto cli = (
        option("-h", "--help").set(help).doc("Print this help message."),
        option("-v", "--version").call([]{std::cout << "Crawler version 0.0.1\n"; exit(0);}).doc("show version"),
        option("-i", "--interactive").set(interactive).doc("Use the interactive mode"),
        option("-q", "--quiet").set(quiet).doc("Silent output"),
        option("-f", "--file") & value("config file", infile)
    );

    // Generate Usage
    if(!parse(argc, argv, cli) || help || !isValid(interactive, infile)) {
        std::cout << make_man_page(cli, argv[0]);
        return (0);
    }

    Crawler *crawler = new Crawler(quiet);
    if (interactive) {
      crawler->setInteractive(interactive);
    } else {
      crawler->setConfig(infile);
    }

    return crawler->run();
}
