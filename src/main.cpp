/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akashets <akashets@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:22:11 by akashets          #+#    #+#             */
/*   Updated: 2023/10/23 21:18:11 by akashets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Webserv.hpp"

// void sigpipeHandle(int sig) { if(sig) {}}

int main(int argc, char **argv) 
{
	// Logger::setState(OFF);
	if (argc == 1 || argc == 2) {
		try 
		{
			(void)argv;
			// ConfigParser	cluster;
        	ServerManager 	master;
			// signal(SIGPIPE, sigpipeHandle);
			// cluster.createCluster(argc == 1 ? "configs/default.conf" : argv[1]);
			// cluster.print(); // for checking
			master.setupServers(cluster.getServers());
			// master.runServers();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (1);
		}
    }
    else 
	{
		Logger::logMsg(CONSOLE_OUTPUT, "Error: wrong arguments");
		return (1);
	}
    return (0);
}