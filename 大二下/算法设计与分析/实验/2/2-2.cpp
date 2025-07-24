#include<bits/stdc++.h>

using namespace std;

const int MAXN = 201;

int dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    vector<vector<int>> r(n, vector<int>(n, 0));
    
    for (int i = 1; i <= n; i++) {
    	for(int j = 1; j <= n; j++){
    		dp[i][j] = INT_MAX;
		}
        dp[i][i] = 0;
    }
    // ��ȡ�����Ϣ
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> dp[i][j];
        }
    }

    // ��ʼ��dp����
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // ��̬�滮������С���
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
//            dp[i][j] = INT_MAX;
            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
//                cout << i << " " << j << " " << k << " " << dp[i][j] << endl; 
            }
        }
    }

    // �����С���
    cout << dp[1][n] << endl;

    return 0;
}
