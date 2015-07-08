#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define NUM 4
#define RESULT 24
#define PRECISION 1E-6

bool Cal(int n, double* number, string* equation) {
    if (n == 1) {
		if (fabs(number[0]-RESULT) < PRECISION)
			return true;
		else
			return false;
	}
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			double a, b;
			string expa, expb;
			a = number[i];
			b = number[j];
			number[j] = number[n-1];
			expa = equation[i];
			expb = equation[j];
			equation[j] = equation[n-1];
			//a+b
			equation[i] = '(' + expa + '+' + expb + ')';
			number[i] = a + b;
			if (Cal(n-1, number, equation))
				return true;
			//a-b
			equation[i] = '(' + expa + '-' + expb + ')';
			number[i] = a - b;
			if (Cal(n-1, number, equation))
				return true;
			//b-a
			equation[i] = '(' + expb + '-' + expa + ')';
			number[i] = b - a;
			if (Cal(n-1, number, equation))
				return true;
			//a*b
			equation[i] = '(' + expa + '*' + expb + ')';
			number[i] = a * b;
			if (Cal(n-1, number, equation))
				return true;
			//a/b
			if (b != 0) {
				equation[i] = '(' + expa + '/' + expb + ')';
				number[i] = a / b;
				if (Cal(n-1, number, equation))
					return true;
			}
			//b/a
			if (a != 0) {
				equation[i] = '(' + expb + '/' + expa + ')';
				number[i] = b / a;
				if (Cal(n-1, number, equation))
					return true;
			}
			//recover
			number[i] = a;
			number[j] = b;
			equation[i] = expa;
			equation[j] = expb;
		}
	}
	return false;
}

void main() {
	double a[NUM];
	string eq[NUM];
	cout<<"----------巧算24点----------"<<endl;
	cout<<"请输入4个数："<<endl;
	for (int i=0; i<NUM; i++) {
		char buffer[20];
		int x;
		cin>>x;
		a[i] = x;
		itoa(x, buffer, 10);
		eq[i] = buffer;
	}
	if (Cal(NUM, a, eq))
		cout<<"计算过程："<<eq[0]<<endl;
	else
		cout<<"该4个数构不成24"<<endl;
}
