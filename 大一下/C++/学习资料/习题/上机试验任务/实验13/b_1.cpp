#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct figure
{
	double a;
	double b;
	double c;
};

double cul_s(double x, double y, double z)
{
	double p = (x + y + z) / 2;
	if (x <= 0 || y <= 0 || z <= 0) throw 0;
	if (x + y > z && x + z > y && y + z > x)
		return sqrt(p * (p - x) * (p - y) * (p - z));
	else throw 0;
}

int main()
{
	ofstream out_file;
	out_file.open("out.txt", ios::app);

	double a, b, c, s;
	try
	{
		cout << "���������߳�:";
		cin >> a >> b >> c;
		s = cul_s(a, b, c);
		cout << endl << "���Ϊ:" << s;
		out_file << s << endl;
	}
	catch (int)
	{
		cout << "�������������,���������������߳�:";
		cin >> a >> b >> c;
	}

	

	
	out_file.close();
	return 0;
}