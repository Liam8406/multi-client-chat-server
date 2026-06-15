#include "server.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>



int main(){
    Server srv(8008);
    srv.start();
    
    return 0;
}

Server::Server(int p) : port(p)
{
}


void Server::start()
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(serverSocket < 0){
        std::cerr<< "Failed to create server socket" << std::endl;
        return;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        std::cerr << "Bnd failed" << std::endl;
        return;
    }

    if(listen(serverSocket, 10) < 0)
    {
        std::cerr << "Listen failed" << std::endl;
        return;
    }
    std::cout << "Server listening on port " << port << std::endl;
    acceptClients();
}

void Server::acceptClients()
{
    while(true){
        sockaddr_in clientAddress;
        socklen_t clientSize = sizeof(clientAddress);

        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddress, &clientSize);
        if(clientSocket < 0){
            std::cerr<< "Failed to connect client to server" << std::endl;
            continue;
        }
        std::cout << "Client connected from " << inet_ntoa(clientAddress.sin_addr) << std::endl;
    }
}

void Server::handleClient(int clientSocket)
{

}

void Server::broadcast(const std::string &message, int senderSocket)
{

}
