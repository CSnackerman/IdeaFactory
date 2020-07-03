#ifndef LOG_H
#define LOG_H

#define LOG_DEBUG

#include <cstdio>
#include <cstdarg>
#include <string>

#include <SDL2/SDL_log.h>

struct Log {
    static void info(std::string format, ...);
    static void error(std::string format, ...);

protected:
    int getExpectedArgCount(std::string& formatString);
};

#endif