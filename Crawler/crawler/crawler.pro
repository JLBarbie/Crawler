TEMPLATE = app

TARGET = crawler

LIBS += -lcurlcpp -lcurl -ltidy

SOURCES +=  main.cpp \
            crawler.cpp \
    tidyhtml.cpp

HEADERS +=  crawler.h \
    tidyhtml.h
