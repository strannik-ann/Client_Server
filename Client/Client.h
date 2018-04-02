/*
 * Client.h
 *
 *  Created on: 29 мар. 2018 г.
 *      Author: jenny
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "../Protocol/Protocol.h"
#include <string>

using namespace std;

class Client {
	string protocol_name;
	Protocol* protocol;

public:
	Client(string prot_name);
	virtual ~Client();

	int Connect();
	int Send(string message);
	int Recv(string* answer);
	void Disconnect();
};

#endif /* CLIENT_H_ */
