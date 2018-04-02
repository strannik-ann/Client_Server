/*
 * Server.h
 *
 *  Created on: 1 апр. 2018 г.
 *      Author: jenny
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string>
#include "Protocol.h"

using namespace std;

class Server {
	Protocol* protocol;
	bool is_run;
	unsigned long result;
	unsigned int countEuclid(unsigned int a, unsigned int b);
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

	int Send(unsigned long answer);
	int Recv(unsigned int* num);

	unsigned long Count(unsigned int num);
};

#endif /* SERVER_H_ */
