/*
 * Server_activity.h
 *
 *  Created on: 31 мар. 2018 г.
 *      Author: jenny
 */

#ifndef SERVER_ACTIVITY_H_
#define SERVER_ACTIVITY_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Server_activity {
	vector<int> number; //массив частот каждой цифры от 0 до 9
	bool exist;
public:
	Server_activity(string s); //Считает количество повторений каждой цифры в строке
	virtual ~Server_activity();

	//Пользовательские функции
	void print_sum();
	void print_sort();
	void print_max_min();
	void print_result(); //Выводит на печать результат выполнения задания
	bool number_exist(); //Внешняя проверка существования чисел в строке
private:
	unsigned int sum();
	unsigned int max();
	unsigned int min();
};

#endif /* SERVER_ACTIVITY_H_ */
