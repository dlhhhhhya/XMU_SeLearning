#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
	int data;
	Node* next;
};
class IntSet
{
	int size;
	Node* head;

public:
	IntSet() { size = 0; head = NULL; }
	IntSet(const IntSet& s)
	{
		Node* p;
		p = s.head;
		head = NULL;	//����head
		size = s.size;
		for (int i = 0; i < s.size; i++)
		{
			insert(p->data);
			p = p->next;
		}
	}	//�����õ�s�����ݷ��統ǰ���������
	~IntSet()
	{
		Node* p;
		p = head;
		head = NULL;
		if (p != NULL)
			delete[]p;
		size = 0;
	}

	bool is_empty()const;
	int Size() const;
	bool is_element(int e)const;
	bool is_subset(const IntSet& s)const;
	bool is_equal(const IntSet& s)const;
	bool insert(int e);
	bool remove(int e);
	void display() const;
	IntSet union2(const IntSet& s)const;
	IntSet intersection(const IntSet& s)const;
	IntSet difference(const IntSet& s)const;
};

bool IntSet::is_empty()const
{
	if (head == NULL)
		return true;
	else return false;
}

int IntSet::Size() const
{
	return size;
}

bool IntSet::is_element(int e)const
{
	Node* p;
	p = head;
	bool flag = false;
	for (int i = 0; i < size; i++)
		if (p->data == e)
		{
			flag= true;
			break;
		};
	return flag;//���û�г�����Ԫ����flagĬ��Ϊfalse
}

bool IntSet::is_subset(const IntSet& s)const
{
	Node* p;
	p = s.head;
	bool flag = true;
	for (int i = 0; i < s.size; i++)
		if (!is_element(p->data))
		{
			flag= false;
			break;
		}//�������s��ĳ��Ԫ�ز��������ڵ���������У�ֱ�ӷ���false
	return flag;
}
bool IntSet::is_equal(const IntSet& s)const
{
	Node* p1, * p2;
	if (size != s.size)return false;
	else 
	{
		for (p1=head,p2=s.head;p1->next!=NULL;p1=p1->next,p2=p2->next)
			if (p1->data != p2->data)return false;
	}
	return true;
}

bool IntSet::insert(int e)
{
	Node* p1, * p2;
	if (head != NULL) {

		p2 = new Node;
		p2->data = e;
		p2->next = NULL;	//Ĭ�ϲ�������β��

		for (p1 = head; p1->next != NULL; p1 = p1->next);	//��p1�ƶ�������ĩ��
		p1->next = p2;	//��p2����p1ĩ��
	}
	else
	{
		head = new Node;
		head->data = e;
		head->next = NULL;
	}
}

bool IntSet::remove(int e)
{
	Node* p1, * p2;

	if (head == NULL)return false;
	else
	{
		for (p1 = head; p1->data != e; p1 = p1->next);
		for (p2 = head; p2->next != p1; p2 = p2->next);//��p2ͣ��p1����һ���ڵ�
		if (p1->data != e)
			return false;//���ѭ������p1->data����e��˵��e������

		p2->next = p1->next;
		delete p1;

		return true;
	}
}

void IntSet::display() const
{
	for (Node* p1 = head; p1->next != NULL; p1 = p1->next)
		cout << p1->data << " ";
	cout << endl;
}

IntSet IntSet::union2(const IntSet& s)const
{
	IntSet set(s);//��s�����ݿ�����set��
	Node* p = head;
	for (p = head; p->next != NULL; p = p->next)
	{
		if (!set.is_element(p->data))
			set.insert(p->data);
	}
	return set;
}

IntSet IntSet::intersection(const IntSet& s)const
{
	IntSet set;//Ĭ�Ϲ���Ϊ�յ�����
	Node* p;
	for (p = head; p->next != NULL; p = p->next)
		if (s.is_element(p->data))
			set.insert(p->data);

	return set;
}

IntSet IntSet::difference(const IntSet& s)const
{
	IntSet set(s);
	Node* p;
	for (p = head; p->next != NULL; p = p->next)
	{
		if (s.is_element(p->data))
			set.remove(p->data);
		else set.insert(p->data);
	}
	return set;
}