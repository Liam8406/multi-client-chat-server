#pragma once

#include "client.hpp"
#include <vector>
#include <thread>
#include <mutex>
#include <string>

class Server{
    private:
        const int port;
        int serverSocket;
        std::vector<int> clients;
        std::mutex serverMutex;

    public:
        Server(int p);
        void start();
        void acceptClients();
        void handleClient(int clientSocket);
        void broadcast(const std::string &message, int senderSocket);
};