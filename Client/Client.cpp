/*
 * Client.cpp
 *
 *  Created on: 1 апр. 2018 г.
 *      Author: jenny
 */

#include "Client.h"

Client::Client() {
	protocol = new Protocol();
}

Client::~Client() {
	delete protocol;
}

int Client::Connect(){
	return protocol->Connect();
}

int Client::Send(unsigned int num){
	return protocol->ClientSend(num);
}

int Client::Recv(unsigned long* answer){
	return protocol->ClientRecv(answer);
}

void Client::Disconnect(){
	protocol->ClientDisconnect();
	return;
}

