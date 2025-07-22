#include<iostream>
#include <vector>
using namespace std;
const int MAX_OF_VEC = 10;

template<class T>
class my_vec
{
	T vec[MAX_OF_VEC];
	size_t size;
public:
	my_vec() {
		size = 0;
		memset(vec, 0, MAX_OF_VEC);
	}

	void input() {
		int n;
		cout << "���������" << endl;
		cin >> n;
		size = n;
		
		cout << "������Ԫ��" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
		}

	}


	T sum() {
		T Sum=0;
		for (int i = 0; i < size; i++)
			Sum += vec[i];
		return Sum;
	}

	bool find(T x) {
		for (int i = 0; i < size; i++)
		{
			if (vec[i] == x) {
				cout << "����" << endl;
				return true;
			}
		}
		cout << "������" << endl;
		return false;
	}
};

int main() {
	my_vec<double> v;
	v.input();
	cout << "sum is:" << v.sum() << endl;

	double x;
	cout << "��������Ҫ���ҵ�Ԫ��" << endl;
	cin >> x;
	v.find(x);
}