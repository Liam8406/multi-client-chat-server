#include "server.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main(){
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8008);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    if(connect(clientSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) < 0){
        return 1;
    }

    return 0;
}