#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	double max(double a=0,double b=0,double c=0);
	cout << endl << "��������������:";
	double a,b,c;
	cin >> a >> b >> c;
	cout << "�����Ϊ��" << max(a,b,c) << endl; 
	return 0;
}

double max(double a=0,double b=0,double c=0) {
	if(a>=b && a>=c)return a;
	if(b>=a && b>=c)return b;
	return c;
}
