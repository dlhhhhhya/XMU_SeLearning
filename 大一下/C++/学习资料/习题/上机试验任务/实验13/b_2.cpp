#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

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
	vector<double> vec_s;
	string file_name;

	double a, b, c, s,no;
	cout << "�������(����0��������):" << endl;
	cin >> no;
	
	while (no != 0)		//�涨��һ������0��ʱ���ʾ����
	{
		cout << "���������߳�:";
		cin >> a >> b >> c;
		try
		{
			s = cul_s(a, b, c);
			cout << endl << "���Ϊ:" << s;
			vec_s.push_back(s);
		}
		catch (int)
		{
			cout << "�������������,���������������߳�:";
			cin >> a >> b >> c;
			s = cul_s(a, b, c);
			cout << endl << "���Ϊ:" << s;
			vec_s.push_back(s);
		}

		cout<<  "�������(����0��������):" << endl;
		cin >> no;
	}

	cout << "��������Ҫ�򿪵��ļ���:";
	cin >> file_name;

	out_file.open(file_name, ios::out|ios::app);
	for (int i = 0; i < vec_s.size(); i++)
		out_file << vec_s[i] << endl;
	
	out_file.close();
	return 0;
}