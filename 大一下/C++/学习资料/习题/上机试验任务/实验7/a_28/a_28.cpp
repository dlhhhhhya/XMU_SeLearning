#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100

class INT{

	int array[MAX];
	int length;

public:
	INT() {
		memset(array, '\0', MAX);
		array[0] = 1;//�����һλ���ڱ�ʾ����
		length = 0;
	}

	~INT()	{
		delete[]array;
		length = 0;
	}

	INT(char* s){
		int len;
		len = strlen(s);
		if (s[0] == '-')
		{
			for (int i = 1; i < len; i++)
				array[i] = s[i] - '0';

			length = len-1;
		}//����Ϊ��

		else
		{
			for (int i = 1; i <= len; i++)
				array[i] = s[i-1] - '0';
			array[0] = 1;	//��һ��Ԫ�ر�ʾ����Ϊ��

			length = len;
		}//����Ϊ��
	}//ʹ���ַ���s��INT���г�ʼ��

	INT(const INT& ni) {
		memset(array, '\0', MAX);
		length = ni.length;
		for (int i = 0; i < length; i++)
			array[i] = ni.array[i];
	}

	INT(int i) {
		memset(array, '\0', MAX);
		length = 0;
		if (i < 0)array[0] = -1;
		else array[0] = 1;

		i = abs(i);
		for(int j=1;i;j++,i/=10)
		{
			length += 1;
			array[j] = i % 10;
		}//��intת��Ϊ����Ԫ��

	}

	void show();
	INT operator+( INT& i);
	INT operator-( INT& i);
	INT operator*( INT& i);
	INT operator/( INT& i);
	INT operator=( INT& i);
	INT operator+(int i);
	INT operator-(int i);
	INT operator*(int i);
	INT operator/(int i);
	INT operator=(int i);
};

void INT::show() {
	if (array[0] == -1)
		cout << "-";	//��һ������Ԫ�ر�ʾ����
	for (int j = 1; j < length; j++)
		cout << array[j];	//ѭ�����ÿ��Ԫ��
}

INT INT::operator+( INT& i){
	INT ni;	//��ni������,ʹ�ö���i�����ʼ��

	int j, k, l;//����forѭ������
	if (length < i.length)ni.length = i.length;
	else ni.length = length;
	//���ÿ������λ����λ���⣬ֱ�������λ������λ��������Ӱ���������
	if (array[0] == i.array[0])
	{
		for (j = length, k = i.length, l = ni.length; j >= 1&&k >= 1; l--, j--, k--)
		{
			array[l] = array[j] + i.array[k];
			if ((l - 1) != 0)
			{
				array[l - 1] += 1;
				array[l] -= 10;
			}//�������λ���������λ������λ,����Ѿ������λ������λ��ֱ�Ӵ洢2λ��
		}//������ʵ�ִ������ӷ�
		return ni;
	}
	else if (array[0] == -1 && i.array[0] == 1)
		return *this - i;
	else
		return i - *this;
}

