#include "HTML.hpp"

using curl::curl_easy;
using curl::curl_ios;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;

using namespace WebParser;

HTML::HTML() {}

//DOM *htmlDom
//HTML::HTML(std::string url) {}

HTML::HTML(char *url) {
    dom = new Document();
    // Create a stringstream object
    std::ostringstream str;
    // Create a curl_ios object, passing the stream object.
    curl_ios<std::ostringstream> writer(str);

    // Pass the writer to the easy constructor and watch the content returned in that variable!
    curl_easy easy(writer);
    // Add some option to the easy handle
    easy.add<CURLOPT_URL>(url);
    easy.add<CURLOPT_FOLLOWLOCATION>(1L);
    try {
        // Execute the request.
        easy.perform();
    } catch (curl_easy_exception error) {
        // If you want to get the entire error stack we can do:
        curlcpp_traceback errors = error.get_traceback();
        // Otherwise we could print the stack like this:
        error.print_traceback();
    }
    // Let's print the stream content.
    std::cout << str.str() << std::endl;
}

void HTML::run() {

}
