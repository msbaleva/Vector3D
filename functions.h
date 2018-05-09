#ifndef VECTORD3D_1_FUNCTIONS_H_
#define VECTORD3D_1_FUNCTIONS_H_

#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
#include "vector3D.h"
using namespace std;

int cnt = 0;
double num = 0.0;
int power = 1;
int current = 0;
char operation[100];
Vector3D* Vectors;

void VectorCnt() {          
	cin >> cnt;
	Vectors = new Vector3D[cnt + 1];
	assert(Vectors != NULL);
	cin.ignore();
}

void printResult() {
	if (operation[0] == '+' || operation[0] == '-') { cout << Vectors[cnt]; }
	else{
		for (int i = 0; i < cnt - 1; i++) {
			cout << Vectors[i] << " " ;

		}
		cout << Vectors[cnt - 1];
	}
}
void vectorAddition() {        // извежда вектор (последния елемент от масива), който е сумата на подадените вектори в масива
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		Vectors[cnt] = Vectors[cnt] + Vectors[i];
	}
	printResult();
	delete[] Vectors;
}
void vectorSubtraction() {     // извежда вектор (последния елемент от масива), който е разликата на подадените вектори в масива
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		if (i == 0) { Vectors[cnt] = Vectors[i]; }
		else { Vectors[cnt] = Vectors[cnt] - Vectors[i]; }

	}
	printResult();
	delete[] Vectors;
}

void vectorNegation() {      // извежда последователно векторите от масива с обърнати знаци
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		Vectors[i] = -Vectors[i];
	}
	printResult();
	delete[] Vectors;
}


void vectorMultiplication() {   // извежда последователно векторите, умножени с подаденото число (подаденият израз започва с '*')
	current = 1;          // на 0-ва позиция в стринга е '*'

	while (operation[current] >= '0' && operation[current] <= '9')  // последователно събира прочетените цифри, като ги умножава със съответната степен на 10
	{                                                         // приключва, когато стрингът свърши или стигне '.', ако числото е тип double
		num *= 10;
		num += int(operation[current] - '0');
		current++;
	}                    // цикълът завършва при изчерпване на стринга или достигане на точка;
	current++;           // в двата случая местим текущият индекс на следващия, на който със сигурност има цифра
	
	while (operation[current] >= '0' && operation[current] <= '9') {   // ако числото е тип double последователно дели прочетените цифри след '.' на степение на 10 и ги прибавая към num
		num += (int(operation[current]) - '0') / (pow(10, power));
		power++;
		current++;
	}

	VectorCnt();

	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		Vectors[i] = Vectors[i] * num;
	}
	printResult();
	delete[] Vectors;
}
void friendMultiplication() {           // извежда последователно векторите, умножени с подаденото число (подаденият израз започва с числото)
	while (operation[current] >= '0' && operation[current] <= '9') {  // 
		num *= 10;
		num += int(operation[current] - '0');    // намира числото и завършва, когато достигне '.' или '*'
		current++;
	}
	if (operation[current] == '.') { current++; }   // ако е тип double мести текущия индекс на следващия и намира частта след десетината запетая
	while (operation[current] != '*') {
		num += (int(operation[current]) - '0') / (pow(10, power));
		power++;
		current++;
	}
	
	VectorCnt();

	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		Vectors[i] = num * Vectors[i];
	}
	printResult();
	delete[] Vectors;
}
#endif
