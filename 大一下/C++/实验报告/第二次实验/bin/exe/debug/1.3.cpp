//��ע����������ֵΪ��ͨ���ͺͷ���ֵΪ��������֮��Ĳ��
#include <iostream>
using namespace std;
float temp;
float fn1(float r) {
	temp = r*r*3.14;
	return temp;
}
float& fn2(float r) {
	temp = r*r*3.14;
	return temp;
}
int main() {
	float a=fn1(5.0); //1 ���������洢 fn1(5.0);
	const float& b=fn1(5.0); //2 fn1(5.0)���صľֲ�����temp���ܱ�c++����Ϊ���ã��ֲ��������ܱ�main�޸ģ� ����const 
	float c=fn2(5.0); //3 �������c�洢temp�ĵ�ǰֵ 
	float& d=fn2(5.0); //4 dΪ��temp������ 
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	cout << temp << endl;
	cout << "----------" << endl; 
	d=1.0;
	cout << temp << endl; 
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
}

