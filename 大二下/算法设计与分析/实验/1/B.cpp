#include<stdio.h>
#include<string.h>
const int N =26;
const int LEN=7;
char str[LEN];
int c[N+1][N+1]; //c[i][j]��¼�����

//ʹ��������Ǽ���n���ڵ�c[i][j]  c[i][j]=c[i-1][j-1]+c[i-1][j];
void Get_C(int n,int c[][N+1]) {
	int i,left,right;
	c[0][0]=1;
	for(i=1; i<=n; i++) {
		c[i][0]=1;
		c[i][i]=1;
		left=1;
		right=i-1;
		while(left<=right) { //��������ʣ�c[i][j]=c[i][i-j];
			c[i][left] = c[i-1][left-1]+c[i-1][left];
			c[i][right--]=c[i][left++];
		}
	}
}

//ͳ�Ƴ���С��len�ĺϷ���
int Get_smaller(int len) {
	int i,curans=0;
	for(i=1; i<len; i++)
		curans+=c[N][i];//ͳ�Ƴ���Ϊi���ַ�������
	return curans;
}

//���������ͳ����ͬǰ׺�µ��ַ�������
int Get_prefix(int len,char*str) {
	int i,j,curans=0;
	int pre=-1;   //��¼ǰһ�ַ�
	for(i=0; i<len; i++) { //ͳ��ǰ׺Ϊi-1λʱ���ɳ��ֵĺϷ�����
		int cur=str[i]-'a';    //��ǰ�ַ�
		for(j=pre+1; j<cur; j++) { //ö�ٰڷ��ڵ�ǰǰ׺��ĵ�һ���ַ���ͳ����Ϸ���������
			curans+=c[N-j-1][len-i-1];
		}
		pre=cur; //������ǰ�ַ�����Ϊ���ε�ǰһ�ַ�ʹ��
	}

	return curans;

}

//�ж������Ƿ�Ƿ�
bool Is_legal(int len,char*str) {
	int i;
	for(i=1; i<len; i++)
		if(str[i]<=str[i-1]) {
			return false;
		}
	return true;
}


int main() {
	Get_C(N,c);   // ʹ��������Ǽ���26���ڵ����������c[i][j]
	int tests;
	while(scanf("%d",&tests)!=EOF) {
		while(tests--) {
			scanf("%s",str);
			int len=strlen(str);
			int ans;
			bool flag=Is_legal(len,str);//�ж����봮�����Ƿ�Ƿ�

			if(flag==false) { //�����ַ�������Ƿ�ֱ�����0
				printf("0\n");
				continue;
			}

			ans =0;
			ans+=Get_smaller(len); //ͳ�Ƴ���С��len�ĺϷ���

			ans+=Get_prefix(len,str); //���������ͳ����ͬǰ׺�µ��ַ�������

			ans+=1;    //�����䱾��ֵ
			printf("%d\n",ans);
		}
	}
	return 0;

}
