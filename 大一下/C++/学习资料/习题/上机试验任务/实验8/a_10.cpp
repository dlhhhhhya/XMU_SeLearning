#include <iostream>
using namespace std;

class A
{
public:
	virtual A* create() {
		return new A;
	}
};

class B :public A
{
public:
	A* create() {
		return new B;
	}
};

int main()
{
	A* p;
	if (1)p = new A;
	else p = new B;
	A* q;
	q = p->create();//ʹ�ö�̬�󶨣�����ΪA���ָ�룬����ָ��A��������B�����ö�̬��
}