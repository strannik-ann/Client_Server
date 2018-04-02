/*
 * Server.h
 *
 *  Created on: 29 мар. 2018 г.
 *      Author: jenny
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include "Server_activity.h"
#include "../Protocol/Protocol.h"

using namespace std;

enum Protocol_num{
	M_UDP_NUM = 0,
	M_TCP_NUM = 1
};

class Server {
	Protocol* p_udp, *p_tcp;
	bool is_run;
public:
	Server();
	virtual ~Server();
	void Start();
	void Stop();
	bool IsRunning();

	void Socket();
	void Bind();
	void Listen();
	void Accept();
	void Disconnect();

	int Send(string answer, Protocol_num protocol_num);
	int Recv(string* message, Protocol_num protocol_num);
};

#endif /* SERVER_H_ */
