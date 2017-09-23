#ifndef TIDYHTML_H
#define TIDYHTML_H

#include <tidy.h>
#include <buffio.h>
#include <iostream>

class TidyHTML
{
public:
    TidyHTML();
    std::string clean(const char* input);
};

#endif // TIDYHTML_H
