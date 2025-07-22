#include <stdio.h>
typedef long long ll;
const int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 3, 5, 5, 4};//����ÿ�ֻ��� 
int get(ll x) {//���������Ļ��� 
	int ans = 0;
	if (!x) ans = c[x]; 
	while (x) ans += c[x % 16], x /= 16;
	return ans;
}
int ans;
void dfs(int n, ll a, ll b, char flag) {//���� 
	if (b > a) return;//����Ϊ����ȥ
	if (n < 2) return;//û�п��԰ڷŵĻ����� 
	if (!flag) {
		if (n < 4) return;//�������϶��������ٷ��� 
		int i; 
		for(i=0;i<16;++i)if(n>c[i])if(a||i)dfs(n - c[i], a * 16 + i, b, 0);//��������λ 
		if (!a) dfs(n - c[0], a, b, 1);//���������� ��ʼ�ż�����aΪ0ʱ�� 
		else dfs(n, a, b, 1);//aΪ1ʱ 
	} else {
	if(b&&n==get(a-b))++ans;//���� bΪ�� 
	if(!b&&n==get(a-b)+c[0])++ans;//bΪ0 
	int i;
	for(i=0;i<16;++i)if(n>c[i])if(b||i)dfs(n - c[i], a, b * 16 + i, 1);//������λ 
	}
}
int main() {
	int n;
	while (scanf("%d", &n)!=EOF) {
		ans = 0;
		dfs(n - 3, 0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
