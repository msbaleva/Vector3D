#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
#include "vector3D.h"
#include "functions.h"
using namespace std;

int main() {
	cin >> operation;
	switch (operation[0]) {
	case '+':
		vectorAddition(); break;
	case '-':
		vectorSubtraction(); break;
	case 'N':
		vectorNegation(); break;
	case '*':
		vectorMultiplication(); break;
	default:
		if (operation[0] >= '0' && operation[0] <= '9') { friendMultiplication(); } break;
	}

	return 0;
}