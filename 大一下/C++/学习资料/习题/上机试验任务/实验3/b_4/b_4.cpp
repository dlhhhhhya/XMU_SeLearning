#include <iostream>
#include <cstdlib>
using namespace std;

struct Node 
{
	int data;
	Node* next;
};

void remove_last(Node*& h, int& a)
{
	Node* p;
	p = h;
	int i = 1;
	int j = 0;//j��ʾi����һ���ڵ�
	while (p->next != NULL)
	{
		p = p->next;
		i++;
		j++;
	}

	a = p->data;
	delete p;//��ɾ����ֵ������a�У�ɾ���ڵ�

	p = h;//����p����h����p
	i = 1;

	while (i < j)
		p = p->next;
	p->next = NULL;
}