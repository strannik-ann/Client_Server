/*
 * Server.cpp
 *
 *  Created on: 1 апр. 2018 г.
 *      Author: jenny
 */

#include "Server.h"

#include "Server.h"
#include <iostream>

Server::Server(): is_run(true), result(1){
	protocol = new Protocol();
}

Server::~Server() {
	delete protocol;
}

void Server::Start(){
	Socket();
	Bind();
	Listen();
	return;
}

void Server::Stop(){
	is_run = false;
	exit(0);
}

bool Server::IsRunning(){
	return is_run;
}

void Server::Socket(){
	protocol->Socket();
}

void Server::Bind(){
	protocol->Bind();
}

void Server::Listen(){
	protocol->Listen();
}

void Server::Accept(){
	protocol->Accept();
}

void Server::Disconnect(){
	protocol->ServerDisconnect();
}


int Server::Send(unsigned long answer){
	return protocol->ServerSend(answer);
}

int Server::Recv(unsigned int* num){
	return protocol->ServerRecv(num);
}

unsigned long Server::Count(unsigned int num){
	if (!result || !num)
		return result = 0;
	unsigned int maxDivider = countEuclid(num, result);
	return result *= num / maxDivider;
}

unsigned int Server::countEuclid(unsigned int a, unsigned int b){
	unsigned int max = a > b ? a : b;
	unsigned int min = a > b ? b : a;
	if (!min) return max;
	return countEuclid(max - min, min);
}


