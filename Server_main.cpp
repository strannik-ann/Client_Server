//============================================================================
// Name        : Server_main.cpp
// Author      : Anna
// Version     :
// Copyright   : Test task for Protey
// Description : Server_main in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>

#include "Server/Server.h"


using namespace std;

void CommandProcess(Server* server);
void TcpProcess(Server* server);
void UpdProcess(Server* server);

int main(void)
{
	//Создание экземляра сервера
	Server server;

	//Запуск TCP и UPD серверов
	try{
		server.Start();
	}catch(const char* reason){
		cerr << "Preparing error : " << reason << endl;
		return EXIT_FAILURE;
	}

	//Нить команд, для остановки сервера
	thread ExitThread(CommandProcess, &server);
	ExitThread.detach();

	//Нить TCP
    thread TcpThread(TcpProcess, &server);
    TcpThread.detach();

    //Функция UPD
    UpdProcess(&server);

    return 0;
}

void TcpProcess(Server* server){
	while(server->IsRunning()){
		try{
			server->Accept();
		}catch(const char* reason){
			cerr << "Connection error : " << reason << endl;
			exit(EXIT_FAILURE);
		}
		string message, answer;
		server->Recv(&message, M_TCP_NUM);
		answer = message;
		server->Send(answer, M_TCP_NUM);
		Server_activity count(message);
		count.print_result();
		try{
			server->Disconnect();
		}catch(const char* reason){
			cerr << "Disconnecting error : " << reason << endl;
			continue;
		}
	}
}

void UpdProcess(Server* server){
	while (server->IsRunning())
	{
		string message, answer;
		server->Recv(&message, M_UDP_NUM);
		answer = message;
		server->Send(answer, M_UDP_NUM);
		Server_activity count(message);
		count.print_result();
	}
}

void CommandProcess(Server* server) {
	while (server->IsRunning()) {
		string command;
		getline(cin, command);
		if ((command == "quit")|| command == "exit") {
			server->Stop();
			break;
		}
	}
}

