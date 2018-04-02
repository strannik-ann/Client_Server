/*
 * Client.cpp
 *
 *  Created on: 29 мар. 2018 г.
 *      Author: jenny
 */

#include "Client.h"

Client::Client(string prot_name) : protocol_name(prot_name), protocol(NULL){}

Client::~Client() {
	delete protocol;
}

int Client::Connect(){
	if (protocol_name == "TCP"){
		protocol = new TCP();
		return protocol->Connect();
	}
	else if (protocol_name == "UDP"){
		protocol = new UDP();
	}
	else{
		throw "wrong protocol name";
	}
	return EXIT_SUCCESS;
}

int Client::Send(string message){
	return protocol->ClientSend(message);
}

int Client::Recv(string* answer){
	return protocol->ClientRecv(answer);
}

void Client::Disconnect(){
	protocol->ClientDisconnect();
	return;
}

