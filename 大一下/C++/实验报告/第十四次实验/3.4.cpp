#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(){}
	~Node(){}
};
template<typename T>
class LinkList
{
public:
	LinkList();                //���캯��
	~LinkList();               //��������
	void printList()const;     //��ӡ�б�
	void append(const T data); //���һ������
	void prepend(const T data);//ǰ��һ������ 
	void removeFront();        //ɾ����һ��Ԫ��
	void insert(const T data); //��˳�����
	bool remove(const T data); //ɾ���ض�����
	bool find(const T data);   //�ҵ��ض�����
	bool isEmpty()const;       //�ж��Ƿ�Ϊ��
	T getFirst()const;         //��ȡ��һ������
	T getLast()const;          //��ȡ���һ������

	Node<T>* head;
	Node<T>* tail;
};
template<typename T>    //���캯��
LinkList<T>::LinkList()
{
	head = tail = NULL;
}

template<typename T>    //�������� 
LinkList<T>::~LinkList()
{
	Node<T>* currentNode = head;
	while (currentNode != NULL)
	{
		Node<T>* temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
} 

template<typename T>  //��ӡ���� 
void LinkList<T>::printList()const
{
	Node<T>* temp = head;   
	while(temp!=nullptr)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
} 

template<typename T>  //���һ������
void LinkList<T>::append(const T data)
{
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = tail = temp;  
	}
	else
	{
		this->tail->next = temp;
		this->tail = temp;
	}
}

template<typename T>  ///ǰ��һ������  
void LinkList<T>::prepend(const T data)  
{	
    Node<T>* temp = new Node<T>;
	temp->data = data;
	if (head == NULL)
	{
		temp->next = NULL;
		head = tail = temp;
	}
	else
	{
		temp->next = this->head; 
		this->head = temp;
	}
}

template<typename T>  //ɾ����һ��Ԫ��  
void LinkList<T>::removeFront()
{
	if (head == NULL)
	{
		cout << "List is empty";
		return;
	}
	Node<T>* temp = this->head;
	this->head = temp->next;
	free(temp);
}

template<typename T> //��˳�����  
void LinkList<T>::insert(const T data)
{
	Node<T>* temp = new Node<T>;
	Node<T>* p = this->head;
	temp->data = data;
	if (head == NULL)   //������Ϊ�գ�����ڵ���Ϊͷ���
	{
		temp->next = NULL;
		head = tail = temp;
		return;
	}
	else if (data < p->data)  //����ڵ�С��ͷ��㣬��ýڵ���Ϊͷ���
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		while (p->next != NULL)
		{
			if (data < p->next->data)  //���Ϻ��ƣ�ֱ����һ���ڵ�Ȳ���ڵ��
				break;
			p = p->next;    
		}
		temp->next = p->next;
		p->next = temp;   //����ڵ�
	}
}

template<typename T>  //ɾ���ض����� 
bool LinkList<T>::remove(const T data)
{
	if (head == NULL)
	{
		cout << "List is empty\n";
		return false;
	}

	Node<T>* p = head;
	Node<T>* front;
	while (p->next != nullptr)//��һ���ڵ㲻Ϊ�գ���ʾ������ɾ��
	{
		front = p;
		p = p->next;
		if (p->data == data)
		{
			front->next = p->next;
			p->next = NULL;
			cout << data << " was successfully removed from the list\n";
			delete p;
			return true;
		}
	}
	cout << data << " was not found in the list when attempting to remove\n";
	return false;
}

template<typename T>  //�ҵ��ض�����
bool LinkList<T>::find(const T data)  
{
	Node<T>* p = head;
	if (head == NULL)
	{
		cout << "List is empty\n";
		return false;
	}
	while (p->next != nullptr)
	{
		if (p->data == data)
		{
			cout << data << " was found in the list\n";
			return true;
		}
		p = p->next;  //Ҫ���жϵ�ǰ�ڵ�������Ƿ�Ϊ������ҵĽڵ㣬�ٽ�p������
		              //��Ȼ���׷���ͷ�ڵ���Ҳ��������
	}
	cout << data << " was not found in the list\n";
	return false;
}

template<typename T>   //�ж��Ƿ�Ϊ��
bool LinkList<T>::isEmpty()const
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>  //��ȡ��һ������
T LinkList<T>::getFirst()const
{
	T first_data;
	first_data = head->data;
	return first_data;
}

template<typename T>   //��ȡ���һ������
T LinkList<T>::getLast()const
{
	T last_data;
	last_data = tail->data;
	return last_data;
}
int main(){
	//��������
	cout << "��������" << endl; 
	LinkList<int> intlist;
	intlist.insert(7); //����С˳��������� 
	intlist.insert(3);
	intlist.insert(5);
	intlist.insert(1);
	intlist.printList();
	intlist.remove(3); //ɾ������
	intlist.find(5);   //Ѱ������ 
	//�ַ�����
	cout << "�ַ�����" << endl; 
	LinkList<char> charlist;
	charlist.append('h'); //��β�Ͳ������� 
	charlist.append('x');
	charlist.append('n');
	charlist.append('b');
	charlist.printList();
	charlist.remove('H'); //ɾ������
	charlist.find('0');   //Ѱ������ 
	//����������
	cout << "����������" << endl; 
	LinkList<float> floatlist;
	floatlist.prepend(2002); //��ͷ�������� 
	floatlist.prepend(520); //�������� 
	floatlist.prepend(13.14);
	floatlist.printList();
	floatlist.remove(2002); //ɾ������
	cout << "ɾ����" << endl;
	floatlist.printList();
	floatlist.find(13.14);   //Ѱ������ 
	return 0;
} 
