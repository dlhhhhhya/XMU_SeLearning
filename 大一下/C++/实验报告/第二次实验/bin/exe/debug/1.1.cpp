#include <iostream>
using namespace std;
int value=0;
void printvalue() {
	cout<<"Value="<<value;//�ڶ�����������2 
}
int main() {
	int value=0;
	value=1;
	cout<<"Value="<<value<<endl;//��һ����������1 
	::value=2;
	printvalue();
	return 0;
}

