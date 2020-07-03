#include "Log.h"

void Log::info(std::string format, ...) {

    #ifndef LOG_DEBUG
        return;
    #endif

    std::string infoString = "[INFO] " + format + "\n";

    va_list args;
    va_start(args, format);

    vprintf(infoString.c_str(), args);

    va_end(args);
}

void Log::error(std::string format, ...) {

    va_list args;
    va_start(args, format);

    int category = SDL_LOG_CATEGORY_APPLICATION;
    SDL_LogError(category, format.c_str(), args);

    va_end(args);
}

int Log::getExpectedArgCount(std::string& formatString) {

    const char character = '%';
    int count = 0;

    for (size_t pos = 0; (pos = formatString.find(character, pos)) != std::string::npos; ++pos) {
		++count;
	}

    return count;
}
