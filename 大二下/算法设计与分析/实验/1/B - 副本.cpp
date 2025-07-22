#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dfs(int i, int k) { //�ݹ�����i��ͷ����Ϊk�������ַ������ܸ���
  LL sum = 0;
  if (k == 1) {
    return 1;
  }
  for (int j = i + 1; j <= 26; j++) {
    sum += dfs(j, k - 1);
  }
  return sum;
}

LL fun(int k) { //����Ϊk�������ַ����ܸ���
  LL sum = 0;
  for (int i = 1; i <= 26; i++) {
    sum += dfs(i, k);
  }
  return sum;
}
signed solve() {
  string s;
  while (cin >> s) {
    LL ans = 1;
    int len = s.size();
    //�Ȱ����г���С�������ַ������ȵ��ַ����ĸ��������
    for (int i = 1; i < len; i++) {
      ans += fun(i);
    }
    LL temp = 0;
    for (int i = 0; i < len; i++) {
      int num = s[i] - 'a' + 1; //��һλ�ַ�
      int len2 = len - i;       //��ȡ��ǰ�ĳ���
      for (int j = temp + 1; j < num; j++) {
        ans += dfs(j, len2);
      }
      temp = num;
    }
    cout << ans << endl;
  }
}
signed main() {
  solve();
  return 0;
}
