/*
	�㷨ʵ��3 - ̰�Ĳ��Կ��ظ����ŷֽ�����
	22920212204392 ���� 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	long long ans; 
	cin >> n;
	if(n==1){
		//������� 
		cout << 1;
		return 0;
	}
	if(n%3==0){
		ans = pow(3,n/3);
		//ȫ���ֽ�Ϊ3 
	}else if(n%3==1){
		ans = pow(3,n/3-1)*4;
		//�ֽ�Ϊ����2������ȫ��3 
	}else{
		ans = pow(3,n/3)*2;
		//�ֽ�Ϊһ��2������ȫ��3 
	}
	cout << ans << endl;
    return 0; 
} 
