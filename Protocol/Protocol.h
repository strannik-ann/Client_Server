/*
 * Protocol.h
 *
 *  Created on: 30 мар. 2018 г.
 *      Author: jenny
 */

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

//default constant

#define M_INET_ADDR "127.0.0.1"

enum default_const{
	M_TCP_PORT = 5600,
};

class Protocol {
protected:
	struct sockaddr_in sa;
	int SocketFD;
	int ConnectFD;
public:
	Protocol();
	virtual ~Protocol();

	//Client functions
	int Connect();
	int ClientSend(unsigned int num);
	int ClientRecv(unsigned long* answer);

	void ClientDisconnect();

	//Server functions
	void Socket();
	void Bind();
	void Listen();
	int Accept();

	int ServerSend(unsigned long answer);
	int ServerRecv(unsigned int* num);

	void ServerDisconnect();
};

#endif /* PROTOCOL_H_ */
