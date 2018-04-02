/*
 * Server.cpp
 *
 *  Created on: 29 мар. 2018 г.
 *      Author: jenny
 */

#include "Server.h"
#include <iostream>

Server::Server(): p_udp(NULL), p_tcp(NULL), is_run(true){}

Server::~Server() {
	delete p_udp;
	delete p_tcp;
	return;
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
	p_udp = new UDP();
	p_tcp = new TCP();
	return;
}

void Server::Bind(){
	p_udp->Bind();
	p_tcp->Bind();
}

void Server::Listen(){
	p_tcp->Listen();
	return;
}

void Server::Accept(){
	p_tcp->Accept();
}

void Server::Disconnect(){
	p_tcp->ServerDisconnect();
	return;
}


int Server::Send(string answer, Protocol_num protocol_num){
	switch(protocol_num){
	case M_TCP_NUM:
		return p_tcp->ServerSend(answer);
	case M_UDP_NUM:
		return p_udp->ServerSend(answer);
	}
	return 0;
}

int Server::Recv(string* message, Protocol_num protocol_num){
	switch(protocol_num){
	case M_TCP_NUM:
		return p_tcp->ServerRecv(message);
	case M_UDP_NUM:
		return p_udp->ServerRecv(message);
	}
	return 0;
}



