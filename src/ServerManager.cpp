#include "../include/ServerManager.hpp"

ServerManager::ServerManager(){}
ServerManager::~ServerManager(){}

/**
 * Start all servers on ports specified in the config file
 */
void    ServerManager::setupServers(std::vector<ServerConfig> servers)
{
    std::cout << std::endl;
    Logger::logMsg(CONSOLE_OUTPUT, "Initializing  Servers...");
    _servers = servers;
    char buf[INET_ADDRSTRLEN];
    bool    serverDub;
    for (std::vector<ServerConfig>::iterator it = _servers.begin(); it != _servers.end(); ++it)
    {
        serverDub = false;
        for (std::vector<ServerConfig>::iterator it2 = _servers.begin(); it2 != it; ++it2)
        {
            if (it2->getHost() == it->getHost() && it2->getPort() == it->getPort())
            {
                it->setFd(it2->getFd());
                serverDub = true;
            }
        }
        if (!serverDub)
            it->setupServer();
        Logger::logMsg(CONSOLE_OUTPUT, "Server Created: ServerName[%s] Host[%s] Port[%d]",it->getServerName().c_str(),
                inet_ntop(AF_INET, &it->getHost(), buf, INET_ADDRSTRLEN), it->getPort());
    }
}


