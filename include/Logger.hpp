/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:21:57 by akashets          #+#    #+#             */
/*   Updated: 2023/10/23 21:18:26 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#define GST             4;
# include "Webserv.hpp"

enum L_State{
    ON,
    OFF
};

enum Mode{
    CONSOLE_OUTPUT,
    FILE_OUTPUT
};

class Logger{
	public: 
		static std::string 	file_name;
		static L_State 		state;

	    static void         setFilenName(std::string);
        static void         setState(L_State);

      	static void         logMsg(Mode, const char*, ...);
		static std::string  getCurrTime();
};

#endif