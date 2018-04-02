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
}

Protocol::~Protocol() {
	close(SocketFD);
	close(ConnectFD);
}

void Protocol::Bind(){
	if (SocketFD == -1){
		throw "cannot create socket";
	}
    if (::bind(SocketFD,(struct sockaddr *)&sa, sizeof sa) == -1) {
		throw "bind failed";
	}
}

int Protocol::Connect(){
	if (SocketFD == -1){
		throw "cannot create socket";
	}
	return 0;
}

TCP::TCP() {
	SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	sa.sin_port = htons(M_TCP_PORT);
}

TCP::~TCP() {}

int TCP::Connect(){
	if (connect(SocketFD, (struct sockaddr *)&sa, sizeof sa) == -1) {
	  throw "connect failed";
	}
	return EXIT_SUCCESS;
}

int TCP::ClientSend(string message){
	return send(SocketFD, message.c_str(), message.size() + 1, 0);
}
int TCP::ClientRecv(string* answer){
	char res[M_MESSAGE_LEN];
	int size = recv(SocketFD, &res, M_MESSAGE_LEN, 0);
	*answer = string(res);
	return size;
}

int TCP::ServerSend(string message){
	return send(ConnectFD, message.c_str(), message.size() + 1, 0);
}
int TCP::ServerRecv(string* answer){
	char res[M_MESSAGE_LEN];
	int size = recv(ConnectFD, &res, M_MESSAGE_LEN, 0);
	*answer = string(res);
	return size;
}

void TCP::ClientDisconnect(){
	if (shutdown(SocketFD, SHUT_RDWR) == 1){
		throw "shutdown failed";
	}
}

void TCP::ServerDisconnect(){
	if (shutdown(ConnectFD, SHUT_RDWR) == 1){
		close(ConnectFD);
		close(SocketFD);
		throw "shutdown failed";
	}
	close(ConnectFD);
}

void TCP::Listen(){
	if (listen(SocketFD, 10) == -1){
		throw "listen failed";
	}
}
int TCP::Accept(){
	ConnectFD = accept(SocketFD, NULL, NULL);
	return ConnectFD;
}

UDP::UDP() {
	SocketFD = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	sa.sin_port = htons(M_UDP_PORT);
}

UDP::~UDP() {}

int UDP::ClientSend(string message){
	return sendto(SocketFD, message.c_str(), message.size() + 1, 0, (struct sockaddr*)&sa, sizeof(struct sockaddr_in));
}

int UDP::ClientRecv(string* answer){
	char res[M_MESSAGE_LEN];
	unsigned int addr_size = sizeof(sockaddr_in);
	int size = recvfrom(SocketFD, res, M_MESSAGE_LEN, 0, (struct sockaddr*)&sa, &addr_size);
	*answer = string(res);
	return size;
}

int UDP::ServerSend(string message){
	return sendto(SocketFD, message.c_str(), message.size() + 1, 0, (struct sockaddr*)&sa, sizeof(struct sockaddr_in));
}

int UDP::ServerRecv(string* answer){
	char res[M_MESSAGE_LEN];
	unsigned int addr_size = sizeof(sockaddr_in);
	int size = recvfrom(SocketFD, res, M_MESSAGE_LEN, 0, (struct sockaddr*)&sa, &addr_size);
    *answer = string(res);
	return size;
}

