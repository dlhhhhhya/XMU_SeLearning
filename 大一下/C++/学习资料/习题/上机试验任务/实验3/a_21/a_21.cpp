#include <iostream>
#include <cstdlib>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct Node
{
	int data;
	Node *next;
};
//�涨����-1Ϊ��ʾ�������
Node* Create()
{
	Node *h = NULL;
	Node* p1=NULL, * p2=NULL;	//p1�������������µĽڵ�
	p1 = new Node;
	h = p1;
	int x;
	cin >> x;	//�����һ������
	while (x != -1)
	{
		p2 = p1;
		p2->data = x;
		p1 = p2->next;
		p1 = new Node;

		cin >> x;
	}
	p2->next = NULL;//�������-1,�ϸ��ڵ���ǽ����㣬-1����������
	delete p1;
	return h;
}

void insert(Node* h, int a)
{
	Node* p1 = NULL, * p2 = NULL;
	if (h == NULL)
	{
		h = new Node;
		h->data = a;
		h->next = NULL;
	}
	else
	{
		p1 = h;
		while (p1->next != NULL)
			p1 = p1->next;

		p2 = new Node;//�����½ڵ�
		p1->next = p2;
		p2->data = a;//��Ҫ�����ֵ����ڵ���
		p2->next = NULL;
	}
}

void remove(Node*& h, int pos)
{
	Node* p1, * p2;
	if (pos == 1)
	{
		p1 = h;
		h = h->next;
		delete p1;
	}

	else
	{
		p1 = h;
		p2 = h;
		int i = 1, j = 1;
		while (i < pos)
		{
			p1 = p1->next;
			i++;
		}
		while (j < pos - 1)
		{
			p2 = p2->next;
			j++;
		}

		if (p1->next == NULL)
		{
			p2->next = NULL;
			delete p1;
		}
		else
		{
			p2->next = p1->next;
			delete p1;
		}
	}
}

int main()
{
	Node* h1=NULL, * h2=NULL;
	Node* h3 = NULL, * h4 = NULL,*h5=NULL;
	Node* Create();
	void insert(Node * h, int a);
	void remove(Node * h,  int pos);

	
	h1 = Create();
	cout << endl;	//�����һ������
	h2 = Create();
	cout << endl;	//����ڶ�������

	Node* p1 = NULL , * p2=NULL;
	for (p1 = h1; p1->next != NULL; p1 = p1->next)
		insert(h3, p1->data);	//��h1���������ֵ��h3;

	for(p1=h1;p1->next!=NULL;p1=p1->next)
		for (p2 = h2; p2->next != NULL; p2 = p2->next)
			if (p1->data != p2->data)insert(h3, p2->data);		//�󲢼����洢��h1��ʾ������

	cout << "������";
	for (p1 = h3; p1->next != NULL; p1 = p1->next)
		cout << p1->data << " ";
	cout << endl;		//�������


	for (p1 = h1; p1->next != NULL; p1 = p1->next)
		for (p2 = h2; p2->next != NULL; p2 = p2->next)
			if (p1->data == p2->data)insert(h4, p2->data);			//�󽻼�

	cout << "������";
	for (p1 = h4; p1->next != NULL; p1 = p1->next)
		cout << p1->data << " ";		
	cout << endl;		//�������

	for (p1 = h3; p1->next != NULL; p1 = p1->next)
		insert(h5, p1->data);//������3���Ƹ�����5

	int i=1;
	for (p1 = h4; p1->next != NULL; p1 = p1->next)
		for (i = 1, p2 = h3; p2->next != NULL; p2 = p2->next, i++)
			if (p1->data == p2->data)remove(h5, i);		//��

	cout << "���";
	for (p1 = h5; p1->next != NULL; p1 = p1->next)
		cout << p1->data << " ";
	cout << endl;//����
}