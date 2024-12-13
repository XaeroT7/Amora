#include <iostream>
#include <ctime>
#include <chrono>
#include "Logger.h"

std::vector<LogEntry> Logger::messages;

std::string localtime_to_str() {
    std::chrono::time_point time_point = std::chrono::system_clock::now();
    std::time_t now = std::chrono::system_clock::to_time_t(time_point);
	
    char timeBuffer[std::size("www/bb/YYYY II:MM:SS")];
    struct tm time_info;
	localtime_s(&time_info, &now);
    std::strftime(timeBuffer, std::size(timeBuffer), "%w/%b/%Y %I:%M:%S", &time_info);
    
    return timeBuffer;
}

void Logger::log(const std::string& message) {
    LogEntry log_entry;
    log_entry.type = LOG_INFO;
    log_entry.message = "LOG: [" + localtime_to_str() + "]: " + message;
 
    std::cout << "\033[32m" << log_entry.message << "\033[0m" << std::endl;
    messages.push_back(log_entry);
}

void Logger::log_error(const std::string& message) {
    LogEntry log_entry;
    log_entry.type = LOG_ERROR;
    log_entry.message = "ERROR: [" + localtime_to_str() + "]: " + message;
    
    std::cerr << "\033[91m" << output << "\033[0m" << std::endl;
    messages.push_back(log_entry);
}