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
void vectorAddition() {        // èçâåæäà âåêòîð (ïîñëåäíèÿ åëåìåíò îò ìàñèâà), êîéòî å ñóìàòà íà ïîäàäåíèòå âåêòîðè â ìàñèâà
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		if(i != cnt - 1) {cin.ignore();}
		Vectors[cnt] = Vectors[cnt] + Vectors[i];
	}
	printResult();
	delete[] Vectors;
}
void vectorSubtraction() {     // èçâåæäà âåêòîð (ïîñëåäíèÿ åëåìåíò îò ìàñèâà), êîéòî å ðàçëèêàòà íà ïîäàäåíèòå âåêòîðè â ìàñèâà
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		if(i != cnt - 1) {cin.ignore();}
		if (i == 0) { Vectors[cnt] = Vectors[i]; }
		else { Vectors[cnt] = Vectors[cnt] - Vectors[i]; }

	}
	printResult();
	delete[] Vectors;
}

void vectorNegation() {      // èçâåæäà ïîñëåäîâàòåëíî âåêòîðèòå îò ìàñèâà ñ îáúðíàòè çíàöè
	VectorCnt();
	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		if(i != cnt - 1) {cin.ignore();}
		Vectors[i] = -Vectors[i];
	}
	printResult();
	delete[] Vectors;
}


void vectorMultiplication() {   // èçâåæäà ïîñëåäîâàòåëíî âåêòîðèòå, óìíîæåíè ñ ïîäàäåíîòî ÷èñëî (ïîäàäåíèÿò èçðàç çàïî÷âà ñ '*')
	current = 1;          // íà 0-âà ïîçèöèÿ â ñòðèíãà å '*'

	while (operation[current] >= '0' && operation[current] <= '9')  // ïîñëåäîâàòåëíî ñúáèðà ïðî÷åòåíèòå öèôðè, êàòî ãè óìíîæàâà ñúñ ñúîòâåòíàòà ñòåïåí íà 10
	{                                                         // ïðèêëþ÷âà, êîãàòî ñòðèíãúò ñâúðøè èëè ñòèãíå '.', àêî ÷èñëîòî å òèï double
		num *= 10;
		num += int(operation[current] - '0');
		current++;
	}                    // öèêúëúò çàâúðøâà ïðè èç÷åðïâàíå íà ñòðèíãà èëè äîñòèãàíå íà òî÷êà;
	current++;           // â äâàòà ñëó÷àÿ ìåñòèì òåêóùèÿò èíäåêñ íà ñëåäâàùèÿ, íà êîéòî ñúñ ñèãóðíîñò èìà öèôðà
	
	while (operation[current] >= '0' && operation[current] <= '9') {   // àêî ÷èñëîòî å òèï double ïîñëåäîâàòåëíî äåëè ïðî÷åòåíèòå öèôðè ñëåä '.' íà ñòåïåíèå íà 10 è ãè ïðèáàâàÿ êúì num
		num += (int(operation[current]) - '0') / (pow(10, power));
		power++;
		current++;
	}

	VectorCnt();

	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		if(i != cnt - 1) {cin.ignore();}
		Vectors[i] = Vectors[i] * num;
	}
	printResult();
	delete[] Vectors;
}
void friendMultiplication() {           // èçâåæäà ïîñëåäîâàòåëíî âåêòîðèòå, óìíîæåíè ñ ïîäàäåíîòî ÷èñëî (ïîäàäåíèÿò èçðàç çàïî÷âà ñ ÷èñëîòî)
	while (operation[current] >= '0' && operation[current] <= '9') {  // 
		num *= 10;
		num += int(operation[current] - '0');    // íàìèðà ÷èñëîòî è çàâúðøâà, êîãàòî äîñòèãíå '.' èëè '*'
		current++;
	}
	if (operation[current] == '.') { current++; }   // àêî å òèï double ìåñòè òåêóùèÿ èíäåêñ íà ñëåäâàùèÿ è íàìèðà ÷àñòòà ñëåä äåñåòèíàòà çàïåòàÿ
	while (operation[current] != '*') {
		num += (int(operation[current]) - '0') / (pow(10, power));
		power++;
		current++;
	}
	
	VectorCnt();

	for (int i = 0; i < cnt; i++) {
		cin >> Vectors[i];
		if(i != cnt - 1) {cin.ignore();}
		Vectors[i] = num * Vectors[i];
	}
	printResult();
	delete[] Vectors;
}
#endif
