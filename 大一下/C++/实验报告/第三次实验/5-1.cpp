#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double calc(double a) { //������
	return a*a;
}
double calc(double a,double b) { //������
	return a*b;
}
double calc(double a,double b,double c) { //������
	return 0.5*a*b*sin(c);
}
double calc(double a,double b,double c,double d) { //����
	return (a+b)*c*0.5;
}

int main() {
	cout << endl << "������״��1������ 2������ 3������ 4���� : ";
	int a,ans;
	cin >> a;
	if(a == 1) {
		double b;
		cin >> b;
		ans = calc(b);
	}
	if(a == 2) {
		double b,c;
		cin >> b >> c;
		ans = calc(b,c);
	}
	if(a == 3) {
		double b,c,d;
		cin >> b >> c >> d;
		ans = calc(b,c,d);
	}
	if(a == 4) {
		double b,c,d;
		cin >> b >> c >> d;
		ans = calc(b,c,d,1);
	}
	cout << "���Ϊ��" << ans << endl; 
	return 0;
}

