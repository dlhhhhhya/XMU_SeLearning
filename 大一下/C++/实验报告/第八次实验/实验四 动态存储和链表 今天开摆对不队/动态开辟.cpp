#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
	// Ϊԭʼ���鿪���ڴ�
	int* p = new int[5];
	for(int i = 0; i < 5; i++) {
		p[i] = i;
		cout << p[i] <<" ";
	}
	// ����һ�θ�����ڴ�
	int *pointer = new int[10];
	// ��ԭʼ�ڴ������ �������µ��ڴ���
	memcpy(pointer, p, sizeof(int) * 5);
	// �ͷ�ԭʼָ��p�Ŀռ�
	delete p;
	// ��ָ��pָ���µ��ڴ�
	p = pointer;
	// ����µ�Ԫ�ص������У���������
	for(int i = 5; i < 10; i++) {
		p[i] = i;
		cout << p[i] << " ";
	}
	return 0;
}
