#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 101;

int dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;

    vector<vector<int>> triangle(n, vector<int>(n, 0));

    // ��ȡ����������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // ��ʼ��dp���飬dp[i][j]��ʾ�Ӷ���(i, j)�����·����
    dp[0][0] = triangle[0][0];

    // ��̬�滮�������·����
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + triangle[i][j];  // ��ߵ�·��
            } else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];  // �ұߵ�·��
            } else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];  // ����·����ѡ��ϴ���
            }
        }
    }

    // �ҳ����·����
    int maxSum = dp[n - 1][0];
    for (int j = 1; j < n; j++) {
        maxSum = max(maxSum, dp[n - 1][j]);
    }

    // ������·����
    cout << maxSum << endl;

    return 0;
}

