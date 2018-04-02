//============================================================================
// Name        : Client_main.cpp
// Author      : Anna
// Version     :
// Copyright   : Test task for Protey
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "Client.h"

using namespace std;

int main() {
	//Создание экземпляра клиента
	Client client;

	//Попытка подключения к серверу
	try{
		client.Connect();
	}catch(const char* reason){
		cerr << "Connection error : " << reason << endl;
		return 1;
	}
	//Отправка сообщения
	unsigned int num;
	unsigned long answer;
	cin >> num;

	client.Send(num);

	//Получение ответа
	client.Recv(&answer);

	cout << answer << endl;
	client.Disconnect();

	return 0;
}
