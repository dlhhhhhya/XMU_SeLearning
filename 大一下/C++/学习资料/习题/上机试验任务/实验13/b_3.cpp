#include <iostream>
using namespace std;

double product1(double a, double b)
{
	if (b == 0)throw 1;
	else return a / b;
}

double product2(double a, double b)
{
	if (b == 0)throw 1.0;
	else return a / b;
}

void func()
{
	cout << "catch";
}

int main()
{
	double x, y,p;		//�ó���������֤
	cout << "�Ƚ���������:" << endl;
	cout << "���������������������֣�" << endl;
	cin >> x >> y;

	try 
	{
		product1(x, y);
	}
	catch (int)
	{
		func();
	}

	try
	{
		product2(x, y);
	}
	catch (int)
	{
		func();
	}

	return 0;
}