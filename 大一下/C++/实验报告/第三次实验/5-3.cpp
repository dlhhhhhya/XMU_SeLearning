#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

inline bool judge(char* a) {
	for(int i=0;i<strlen(a);i++){
		if(a[i]<'0'||a[i]>'9')return false;
	} 
	return true;
}

int main() {
	cout << endl << "�����ַ�:";
	char a[100]; 
	cin >> a;
	if(!judge(a)){
		cout << "��������ĸ��";
	}else{
		cout << "ֻ�����֣�"; 
	}
	return 0;
}


