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
void vectorAddition() {        // ������� ������ (��������� ������� �� ������), ����� � ������ �� ���������� ������� � ������
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		Vectors[cnt] = Vectors[cnt] + Vectors[i];
	}
	printResult();
	delete[] Vectors;
}
void vectorSubtraction() {     // ������� ������ (��������� ������� �� ������), ����� � ��������� �� ���������� ������� � ������
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

void vectorNegation() {      // ������� �������������� ��������� �� ������ � �������� �����
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		cin.ignore();
		Vectors[i] = -Vectors[i];
	}
	printResult();
	delete[] Vectors;
}


void vectorMultiplication() {   // ������� �������������� ���������, �������� � ���������� ����� (���������� ����� ������� � '*')
	current = 1;          // �� 0-�� ������� � ������� � '*'

	while (operation[current] >= '0' && operation[current] <= '9')  // �������������� ������ ����������� �����, ���� �� �������� ��� ����������� ������ �� 10
	{                                                         // ���������, ������ �������� ������ ��� ������ '.', ��� ������� � ��� double
		num *= 10;
		num += int(operation[current] - '0');
		current++;
	}                    // ������� �������� ��� ���������� �� ������� ��� ��������� �� �����;
	current++;           // � ����� ������ ������ �������� ������ �� ���������, �� ����� ��� ��������� ��� �����
	
	while (operation[current] >= '0' && operation[current] <= '9') {   // ��� ������� � ��� double �������������� ���� ����������� ����� ���� '.' �� �������� �� 10 � �� �������� ��� num
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
void friendMultiplication() {           // ������� �������������� ���������, �������� � ���������� ����� (���������� ����� ������� � �������)
	while (operation[current] >= '0' && operation[current] <= '9') {  // 
		num *= 10;
		num += int(operation[current] - '0');    // ������ ������� � ��������, ������ �������� '.' ��� '*'
		current++;
	}
	if (operation[current] == '.') { current++; }   // ��� � ��� double ����� ������� ������ �� ��������� � ������ ������ ���� ���������� �������
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
