/*
 * Protocol.cpp
 *
 *  Created on: 30 мар. 2018 г.
 *      Author: jenny
 */

#include "Protocol.h"

Protocol::Protocol() : SocketFD(0), ConnectFD(0){
	memset(&sa, 0, sizeof sa);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr(M_INET_ADDR);
	sa.sin_port = htons(M_TCP_PORT);
}

Protocol::~Protocol() {
	close(SocketFD);
	close(ConnectFD);
}

void Protocol::Socket(){
	SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SocketFD == -1){
		throw "cannot create socket";
	}
}

void Protocol::Bind(){
    if (bind(SocketFD,(struct sockaddr *)&sa, sizeof sa) == -1) {
		throw "bind failed";
	}
}

int Protocol::Connect(){
	Socket();
	if (connect(SocketFD, (struct sockaddr *)&sa, sizeof sa) == -1) {
		throw "connect failed";
	}
	return 0;
}

int Protocol::ClientSend(unsigned int num){
	return send(SocketFD, &num, sizeof(unsigned int), 0);
}
int Protocol::ClientRecv(unsigned long* answer){
	return recv(SocketFD, answer, sizeof(unsigned long), 0);
}

int Protocol::ServerSend(unsigned long answer){
	return send(ConnectFD, &answer, sizeof(unsigned long), 0);
}
int Protocol::ServerRecv(unsigned int* num){
	return recv(ConnectFD, num, sizeof(unsigned int), 0);
}

void Protocol::ClientDisconnect(){
	if (shutdown(SocketFD, SHUT_RDWR) == -1){
		throw "shutdown failed";
	}
	close(SocketFD);
}

void Protocol::ServerDisconnect(){
	if (shutdown(ConnectFD, SHUT_RDWR) == -1){
		close(ConnectFD);
		close(SocketFD);
		throw "shutdown failed";
	}
	close(ConnectFD);
}

void Protocol::Listen(){
	if (listen(SocketFD, 10) == -1){
		throw "listen failed";
	}
}
int Protocol::Accept(){
	ConnectFD = accept(SocketFD, NULL, NULL);
	return ConnectFD;
}



