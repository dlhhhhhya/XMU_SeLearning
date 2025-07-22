#include <iostream>
using namespace std;

class List {
	public:
		List() {
			create_List();
		}
		~List() {
			clear();
		}
		void create_List();
		void insert(const int& d);
		void print();
		void delete_between(const int& mink,const int& maxk);
	private:
		//�ڵ�ṹ
		struct Node {
			int data;
			Node * next;
			Node(const int& d):data(d),next(NULL) {}
		};
		Node * head;//ͷ�ڵ�
		//����������
		void clear() {
			Node * p = head;
			//��ͷ�ڵ㿪ʼѭ��ɾ��
			while(p) {
				Node * q = p->next;
				delete p;
				p = q;
			}
		}
		//��������d����һ���ڵ�λ�õĺ���
		//Ϊ�˷������ɾ������
		Node* find(const int& d) {
			Node * p = head;
			for(; p; p=p->next) {
				if(p->next->data==d)
					break;
			}
			return p;
		}
};

//����ͷ���
void List::create_List() {
	head = new Node(0);
}
//��ͷ����һ���ڵ�
void List::insert(const int& d) {
	Node *p = new Node(d);
	p->next = head->next;
	head->next = p;
}
//��ӡ����
void List::print() {
	for(Node * p = head->next; p; p=p->next) {
		cout << p->data << endl;
	}
	cout << endl;
}
//ɾ���������������ֵ���� mink ��С��maxk������Ԫ��
void List::delete_between(const int& mink,const int& maxk) {
	for(Node * p = head->next; p; p=p->next) {
		if(p->next->data <= mink) {
			continue;
		}
		for(Node * q = p; q; q=q->next) {
			if(q->data < maxk) {
				continue;
			}
			p->next = q;
			break;
		}
		break;
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	List list;
	list.insert(30);
	list.insert(25);
	list.insert(20);
	list.insert(15);
	list.insert(10);
	cout << "ɾ��ǰ:" << endl;
	list.print();
	list.delete_between(15,25);
	cout << "ɾ����:" << endl;
	list.print();
	return 0;
}
