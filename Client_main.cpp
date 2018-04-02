//============================================================================
// Name        : Client_main.cpp
// Author      : Anna
// Version     :
// Copyright   : Test task for Protey
// Description : Client_main in C++, Ansi-style
//============================================================================

#include "Client/Client.h"

using namespace std;

int main(int argc, char** argv)
{
	string protocol_name;
	//Если клиент забыл указать в параментрах протокол, даем ему шанс исправиться.
	if (argc < 2){
		cerr << "Argument of protocol is not found. Choose TCP/UDP to continue..." << endl;
		getline(cin, protocol_name);
	}
	else{
		protocol_name = string(argv[1]);
	}

	//Создание экземпляра клиента
	Client client(protocol_name);

	//Попытка подключения к серверу
	try{
		client.Connect();
	}catch(const char* reason){
		cerr << "Connection error : " << reason << endl;
		return EXIT_FAILURE;
	}
	//Отправка сообщения
	string message, answer;
	getline(cin, message);

	client.Send(message);

	//Получение ответа
	client.Recv(&answer);

	cout << answer << endl;
	try{
		client.Disconnect();
	}catch(...){}

	return EXIT_SUCCESS;

}

