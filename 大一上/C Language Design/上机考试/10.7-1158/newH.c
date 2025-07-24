#include <stdio.h>
#define N 60000
//from hkk 
const int dp[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int dr[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

char ss[30];//�洢ѯ�� 

char chk(int y) { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }//�ж��Ƿ������� 

char cmp(int y1, int m1, int d1, int y2, int m2, int d2) {//�Ƚ���� ��ҪΪ�����жϴ����ĸ������׼�� 
	if (y1 != y2) return y1 > y2;
	if (m1 != m2) return m1 > m2;
	return d1 >= d2;
}
int tr1(char h) {//���ת��� 
	if (h == 'M') return 1868;
	if (h == 'T') return 1912;
	if (h == 'S') return 1926;
	if (h == 'H') return 1989;
	if (h == 'R') return 2019;
}
char tr2(int y, int m, int d) {//���ת��� 
	if (cmp(y, m, d, 2019, 5, 1)) return 'R';
	if (cmp(y, m, d, 1989, 1, 8)) return 'H';
	if (cmp(y, m, d, 1926, 12, 25)) return 'S';
	if (cmp(y, m, d, 1912, 7, 30)) return 'T';
	return 'M';
}

int Y[N], M[N], D[N], P[200][13][32];//��ǰ�������ÿһ������Ӧ��������ڼ������ ѯ��ʱֱ�ӵ��� 
void init() {//�����Ӻ��� 
	int y = 1868, m = 9, s = 8;
	const int *d = chk(y) ? dr : dp;//��������  ָ��ָ���Ӧ���� 
	int i; 
	for (i = 1; i < 60000; ++i) {
		Y[i] = y, M[i] = m, D[i] = s;//�ӵ�һ�쿪ʼ 
		P[y - 1868][m][s] = i;//�����ǵڼ�����P�� 
		++s;//��һ�� 
		if (s > d[m]) s -= d[m], ++m;//��һ�� 
		if (m > 12) m = 1, ++y, d = chk(y) ? dr : dp;//��һ�� 
	}
}

int main() {
	int n; init();
	while (~scanf("%s%d", ss, &n)) {
		char h;
		int y, m, s;
		sscanf(ss, "%c%d/%d/%d", &h, &y, &m, &s);
		y += tr1(h) - 1;//ת��ʵ�� 
		int id = P[y - 1868][m][s] + n;//�Ӽ�����������ҳ���Ӧ�ĵڼ������ 
		char r = tr2(Y[id], M[id], D[id]);//����� 
		printf("%c%d/%d/%d\n", r, Y[id] - tr1(r) + 1, M[id], D[id]);
	}
	return 0;
}


