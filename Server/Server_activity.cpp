/*
 * Server_activity.cpp
 *
 *  Created on: 31 мар. 2018 г.
 *      Author: jenny
 */

#include "Server_activity.h"

Server_activity::Server_activity(string s): exist(false){
	number.resize(10, 0);
	for (unsigned int i = 0; i < s.size(); ++i){
		if (isdigit(s[i])){
			number[s[i]-'0']++;
		}
	}
	for (int i = 0; i < 10; ++i){
		if (number[i]){
			exist = true;
			break;
		}
	}
}

Server_activity::~Server_activity(){
	number.clear();
}

bool Server_activity::number_exist(){
	return exist;
}

void Server_activity::print_sum(){
	cout << sum() << endl;
}
void Server_activity::print_sort(){
	for (int i = 9; i >= 0; --i){
		for (int j = 0; j < number[i]; ++j){
			cout << i;
		}
	}
	cout << endl;
}
void Server_activity::print_max_min(){
	cout << max() << " " << min() << endl;
}

void Server_activity::print_result(){
	if (!exist){
		return;
	}
	print_sum();
	print_sort();
	print_max_min();
}

unsigned int Server_activity::sum(){
	unsigned int s = 0;
	for (int i = 1; i < 10; ++i){
		s += i * number[i];
	}
	return s;
}
unsigned int Server_activity::max(){
	for (unsigned int i = 9; i >= 0; --i){
		if (number[i] > 0)
			return i;
	}
	return 0;
}
unsigned int Server_activity::min(){
	for (unsigned int i = 0; i <= 9; ++i){
		if (number[i] > 0)
			return i;
	};
	return 9;
}
