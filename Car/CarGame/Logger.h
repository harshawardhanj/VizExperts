#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

#define LOG(INFO) std::cout<<INFO<<std::endl

/**
 * @brief Implement a thread safe singleton Logger class.
 */
class Logger
{
public:
    enum LogLevel { ALL, INFO, WARNING, ERROR, NEEDED };
private:
    LogLevel Errorlevel = ALL;
    std::string LogLevelNames[5] = { "ALL","INFO","WARNING", "ERROR", "NEEDED" };
public:
    Logger(LogLevel level)
    {
        Errorlevel = level;
        if (Errorlevel <= INFO)
        {
            LOG(  "[" << LogLevelNames[Errorlevel] << "]: " << "LOGGER set to: " << LogLevelNames[Errorlevel] << std::endl);
        }
    }
    ~Logger()
    {
        if (Errorlevel <= WARNING)
        {
            LOG(  "[" << LogLevelNames[Errorlevel] << "]:" << " LOGGER destroyed" << std::endl);
        }
    }
    void log(LogLevel level, std::string message)
    {
        if (Errorlevel <= level)
        {
            LOG(  "[" << LogLevelNames[level] << "]: " << message << std::endl);
        }
    }
};


#endif // LOGGER_H
