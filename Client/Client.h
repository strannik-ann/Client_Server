/*
 * Client.h
 *
 *  Created on: 1 апр. 2018 г.
 *      Author: jenny
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Protocol.h"

class Client {
	Protocol* protocol;

public:
	Client();
	virtual ~Client();

	int Connect();
	int Send(unsigned int num);
	int Recv(unsigned long* answer);
	void Disconnect();
};

#endif /* CLIENT_H_ */
