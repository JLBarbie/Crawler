#ifndef HTML_HPP
# define HTML_HPP

#include "Document.hpp"

#include <iostream>
#include <sstream>

#include <curl/curl.h>
#include <curlcpp/curl_easy.h>
#include <curlcpp/curl_exception.h>

namespace WebParser {
    class HTML
    {
    public:
        HTML();
        HTML(char *url);
        ~HTML();

        void run();
        Document *getDocument();
        bool loadUrl(std::string);

        HTML& operator=(const HTML& other) = default;
        HTML& operator=(HTML&& other) = default;

    private:
        bool isURL(std::string);
        Document *dom;
    };
}

#endif
