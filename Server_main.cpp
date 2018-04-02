//============================================================================
// Name        : Server_main.cpp
// Author      : Anna
// Version     :
// Copyright   : Test task for Protey
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include "Server.h"

void CommandProcess(Server* server);

using namespace std;

int main() {
	//Создание экземляра сервера
	Server server;

	//Запуск TCP и UPD серверов
	try{
		server.Start();
	}catch(const char* reason){
		cerr << "Preparing error : " << reason << endl;
		return 1;
	}

	//Нить команд, для остановки сервера
	thread ExitThread(CommandProcess, &server);
	ExitThread.detach();

	//Запуск сервера
	while(server.IsRunning()){
		try{
			server.Accept();
		}catch(const char* reason){
			cerr << "Connection error : " << reason << endl;
			return 1;
		}
		unsigned long answer;
		unsigned int num;
		server.Recv(&num);
		answer = server.Count(num);
		server.Send(answer);
		try{
			server.Disconnect();
		}catch(const char* reason){
			cerr << "Disconnecting error : " << reason << endl;
			return 1;
		}
	}

    return 0;
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
