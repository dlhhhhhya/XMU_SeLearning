#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string str; //C++��������ȫ֧��string���ͣ�û��Ҫ����C���ַ�buffer��
	cin>>str; //�����ַ���
	reverse(str.begin(), str.end()); //strִ������䣬���Ѿ�����������
	cout<<str<<endl;
	return 0; 
}
