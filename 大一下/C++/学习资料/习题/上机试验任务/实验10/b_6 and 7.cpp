#include<iostream>
using namespace std;

template<class T>
class node{
public:
	T data;
	node<T>* next;
};

template<class T>
class my_list
{
private:
	node<T>* head;
	int size;
public:
	my_list<T>() {
		head = nullptr;
		size = 0;
	}

	my_list<T>(my_list<T>& l)
	{
		if (l.get_size() == 0)
		{
			head = nullptr;
			size = 0;
		}

		else
		{
			int i;
			for (i = 1; i <= size; i++)
				insert(l.at(i));
		}
	}

	T at(int pos) 
	{
		if (head != nullptr) {
			int i;
			node<T>* p=nullptr;
			for (p = head, i = 1; i < pos; i++, p = p->next);

			return p->data;
		}

		else {
			exit(-1);
		}
	}
	//����ĳ���ڵ������



	void insert(T x)
	{
		node<T>* p1, * p2, * p3;

		if (size == 0)
		{
			p1 = new node<T>;
			p1->data = x;
			p1->next = nullptr;
			head = p1;

			p1 = nullptr;
		}

		else if (size == 1)
		{
			if (x <= head->data)
			{
				p1 = new node<T>;
				
				p1->data = x;
				p1->next = head;
				head = p1;
			}


			else
			{
				p1 = new node<T>;

				p1->data = x;
				p1->next = nullptr;

				head->next = p1;
			}

			p1 = nullptr;
		}

		else
		{
			for (int i = 1; i < size; i++)
			{
				if (at(i) <= x && at(i + 1) >= x)
				{
					int j=1;
					for (p1 = head, j = 1; j < i; j++, p1 = p1->next);
					for (p2 = head,  j = 1; j <= i; j++, p2 = p2->next);

					p3 = new node<T>;
					p3->data = x;
					p3->next = p2;
					p1->next = p3;

					p1 = p2 = p3 = nullptr;
					break;
				}
				//�������ڵ�֮������µ�����
				

				if (at(1) >= x)
				{
					p1 = new node<T>;
					p1->data = x;

					p2 = head;
					p1->next = p2;
					head = p1;

					p1 = p2 = nullptr;
					break;
				}

				if (x >= at(size))
				{
					for (p1 = head; p1->next != nullptr; p1 = p1->next);
					p2 = new node<T>;

					p2->data = x;
					p2->next = nullptr;
					p1->next = p2;

					p1 = p2 = nullptr;
					break;
				}
			}

		}

		size++;
	}



	void remove(T x)
	{
		node<T>* p1, * p2, * p3;
		p1 = p2 = p3 = nullptr;

		if (find(x) == 0)
		{
			cout << "�޸�Ԫ��" << endl;
			exit(-1);
		}

		else
		{
			if (find(x) == size)
			{
				int i=1;
				for (p1 = head; p1->next != nullptr; p1 = p1->next);
				for (p2 = head, i = 1; i < find(x); i++)
					p2 = p2->next;

				p2->next = nullptr;			//��ǰһ���ڵ���Ϊ���ĩ��
				delete p1;				//�黹x�Ŀռ�

				size--;

				p1 = p2 = nullptr;
			}

			else if (find(x) == 1)
			{
				if (size == 1) delete head;


				else {
					p1 = head;
					p2 = head->next;

					head = p2;
					delete p1;

					p1 = p2 = nullptr;
				}

				size--;
			}

			else
			{
				int i = 1;
				for (p1 = head,  i = 1; i < find(x); i++,p1=p1->next);		//p1ָ��x�Ľڵ�
				for (p2 = head,  i = 1; i < find(x) - 1; i++, p2 = p2->next);//p2ָ��x����һ���ڵ�
				for (p3 = head,  i = 1; i <= find(x); i++, p3 = p3->next);	//p3ָ��x����һ���ڵ�

				p2->next = p3;
				delete p1;

				p1 = p2 = p3 = nullptr;

				size--;
			}
		}
	}

	int find(T x)
	{
		int pos=0;		//���ؽڵ��λ��
		node<T>* p1;

		if (head == nullptr)return 0;
		
		for (p1 = head; p1->next != nullptr; p1 = p1->next)
		{
			pos++;
			if (p1->data == x) return pos;
		}

		return 0;	//����Ҳ���������0
	}

	void show() {
		node<T>* p;
		cout << "����Ԫ��Ϊ:" << endl;
		for (p = head; p->next != nullptr; p = p->next)
			cout << p->data << endl;
		cout << p->data << endl;

		p = nullptr;
	}

	int get_size() {
		return size;
	}

	void operator=(my_list<T>& l)
	{
		if (l.get_size() == 0)
		{
			head = nullptr;
			size = 0;
		}

		else
		{
			int i;
			for (i = 1; i <= l.get_size(); i++)
				insert(l.at(i));
		}
	}
};

int main() {
	my_list<int> list;
	list.insert(1);
	list.insert(4);
	list.insert(3);

	list.show();

	cout << "���������Ƴ�Ԫ��3" << endl;
	list.remove(3);

	list.show();


	cout << "����һ���µ�����" << endl;
	my_list<int> list1;
	list1 = list;
	list1.show();

	return 0;
}