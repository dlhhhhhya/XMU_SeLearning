/*
	�㷨ʵ��3 - ̰�Ĳ��Բ����ظ����ŷֽ�����
	22920212204392 ���� 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> mult; 
int main(){
	long long n;
	cin >> n;
	if(n==1){
		cout << 1 << endl;
		return 0;
	}
	long long tmp=n;
	int cnt=2,i=-1;
	while(tmp>=cnt){
		//̰�Ĵ�С����ֽ� 
		mult.push_back(cnt);
		tmp-=cnt;
		cnt++;
		i++;
	}
	//�����ʣ���������� 
	if(tmp==cnt-1){
		mult[i]++;
	}
	for(int j=i;j>=0&&tmp;j--){
		tmp--;
		mult[j]++;
	}
	//����� 
	long long ans=1;
	for(auto mul:mult){
		ans*=mul;
	}
	cout << ans << endl;
    return 0; 
} 
