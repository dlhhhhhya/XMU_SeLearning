#include <iostream>
#include <cstring> 
using namespace std;

int main(int argc, const char * argv[])
{
	int length1,length2;
	cout << "�����ַ���1���ȣ�"; 
	cin >> length1;
	cout << "�����ַ���2���ȣ�"; 
	cin >> length2;
	char *p= new char[length1+length2+5];
	char *q= new char[length2+5];
	cin >> p;
	cin >> q;
	strcat(p,q);
	cout << p; 
    return 0;
}
