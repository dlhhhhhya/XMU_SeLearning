/*
	�㷨ʵ��3 - ̰�Ĳ���ɾ������
	22920212204392 ���� 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int m;
	cin >> m;
	while(m--){
		int pos=0;
		for(int i=1;i<s.length();i++){
			//�������� 
			if(s[i]>s[pos]){
				pos=i;
			}
		}
		//̰��ÿ��ȡ�������ɾ�� 
		s.erase(pos,1);
	} 
	cout << s << endl; 
    return 0; 
} 
