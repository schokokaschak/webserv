/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:11:47 by akashets          #+#    #+#             */
/*   Updated: 2023/10/23 21:18:14 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/Logger.hpp"

L_State 	Logger::state = ON;
std::string Logger::file_name = "logfile.txt";

void    Logger::logMsg(Mode m, const char* msg, ...){
    char        output[8192];
    va_list     args;
    int         n;

    if (state == ON)
    {
        va_start(args, msg);
        n = vsnprintf(output, 8192, msg, args);
        std::string date = getCurrTime();
        if (m == FILE_OUTPUT){
            if (mkdir("logs", 0777) < 0 && errno != EEXIST){
                std::cerr << "mkdir() Error: " << strerror(errno) << std::endl;
                return ;
            }
            int fd = open(("logs/" + file_name).c_str(), O_CREAT | O_APPEND | O_WRONLY, S_IRUSR | S_IWUSR);
            std::cout << "fd is " << fd << " and errno is :" << strerror(errno) << std::endl;
            write(fd, date.c_str(), date.length());
            write(fd, "   ", 3);
            write(fd, output, n);
            write(fd, "\n", 1);
            close(fd);
        }
        else if (m == CONSOLE_OUTPUT)
            std::cout << getCurrTime() << output << std::endl;   
        va_end(args);
    }
}

std::string Logger::getCurrTime(){
    tzset();
    char date[1000];
    time_t now = time(0);
    struct tm tm = *gmtime(&now);
    tm.tm_hour = tm.tm_hour + GST;
    strftime(date, sizeof(date), "[%Y-%m-%d  %H:%M:%S]   ", &tm);
    return (std::string(date));
}