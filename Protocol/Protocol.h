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
	M_TCP_PORT = 1100,
	M_UDP_PORT = 5800,
	M_MESSAGE_LEN = 2048
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
	virtual int Connect();
	virtual int ClientSend(string message) = 0;
	virtual int ClientRecv(string* answer) = 0;

	//Client-server
	virtual void ClientDisconnect(){};
	virtual void ServerDisconnect(){};

	//Server functions
	void Bind();
	virtual void Listen(){};
	virtual int Accept(){return 0;};

	virtual int ServerSend(string answer) = 0;
	virtual int ServerRecv(string* message) = 0;

};

class UDP : public Protocol {
public:
	UDP();
	virtual ~UDP();

	int ClientSend(string message);
	int ClientRecv(string* answer);

	int ServerSend(string answer);
	int ServerRecv(string* message);
};

class TCP : public Protocol {
public:
	TCP();
	virtual ~TCP();

	int Connect();
	int ClientSend(string message);
	int ClientRecv(string* answer);
	void ClientDisconnect();
	void ServerDisconnect();

	void Listen();
	int Accept();
	int ServerSend(string answer);
	int ServerRecv(string* message);
};

#endif /* PROTOCOL_H_ */
