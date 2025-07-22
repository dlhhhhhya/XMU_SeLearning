#include <iostream>
#include <cstring>
using namespace std;

const int N = 8;
int solution;
int *arr;//���ڴ�����еĻʺ����λ��
//�涨���½�Ϊ����ԭ��

bool IsPlaceOk(int t)
{
	for (int i = 1; i < t; i++)
		if (abs(arr[i] - arr[t]) == abs(i - t) ||  arr[i] == arr[t])
			return false;
	return true;
}//������һ�е�λ��t�Ƿ����

void backtrack(int t)
{
	if (t <= N)
	{
		for (int i = 1; i <= N; i++)
		{
			arr[t] = i;//�õ�t�еĻʺ�ȡ������λ��
			if (IsPlaceOk(t))
				backtrack(t + 1);//���ĳһ��λ��Ŀǰ���ԣ�������һ�е��ж�
		}
	}//ȡ��������λ�ã��������λ���ж�����solution+1

	else solution++;
}

void main()
{
	solution = 0;
	arr = new int[N + 1];
	for (int n = 1; n <= N; n++)
		arr[n] = 0;
	backtrack(1);
	cout << solution;
	delete []arr;
}