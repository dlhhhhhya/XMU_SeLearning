/*
	�㷨ʵ��3 - ���ޱ��
	22920212204392 ���� 
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000][3];
int main(){
	string s;
	cin >> s;
	if(s.length()==1){
		// ���ж�ֻ��һ���ַ���� 
		if(s=="a"){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	} 
	for(int i=0;i<s.length();i++){
		// ֻ���Լ������ŵ���� 
		dp[i][i][s[i]-'a']=1;
	}
	for(int l=1;l<s.length();l++) // ö�ٳ��� 
    {
        for(int i=0;i<s.length()-l;i++) // ö����ʼ�ַ� 
        {
            int j=i+l; //����������ֹ�ַ� 
            for(int p=i;p<j;p++) // ÿ���ط������� 
            {
                dp[i][j][0]+=dp[i][p][2]*dp[p+1][j][0]+(dp[i][p][0]+dp[i][p][1])*dp[p+1][j][2]; //a 
                dp[i][j][1]+=dp[i][p][0]*(dp[p+1][j][0]+dp[p+1][j][1])+dp[i][p][1]*dp[p+1][j][1]; //b 
                dp[i][j][2]+=dp[i][p][1]*dp[p+1][j][0]+dp[i][p][2]*(dp[p+1][j][1]+dp[p+1][j][2]); //c 
            }
        }
    }
    cout<<dp[0][s.length()-1][0]<<endl;
    return 0; 
} 
