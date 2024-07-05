#include "mrt_server.h"

Server::Server(unsigned int port, long buff){

    this-> server_port = htons(port);
    this -> buff_size = buff;
    memset(&(this-> serverAddr), 0 , sizeof(this->serverAddr));
    memset(&(this-> clnaddr), 0 , sizeof(this->clnaddr));

    if ((sock =socket(AF_INET, SOCK_DGRAM, 0)) < 0)
        die("socket failed");
    this -> serverAddr.sin_family = AF_INET;
    this -> serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    this->serverAddr.sin_port = this->server_port;

    if (bind(this->sock, (struct sockaddr*)&(this->serverAddr), sizeof(this->serverAddr)) < 0) {
            perror("bind failed");

    }
}
int Server::accept(){

}
int Server::close(){

}
void Server::recv(){

    char buffer[4096]; 
    
    socklen_t len = sizeof(this->clnaddr);
    int n = recvfrom(this->sock, (char *) buffer, sizeof(buffer) , MSG_WAITALL,
                     (struct sockaddr*)&(this->clnaddr), &len);
     if (n < 0) {
        perror("recvfrom failed");
    }
    std::cout<<buffer<<std::endl;
    
}
Server::~Server(){
    
}
