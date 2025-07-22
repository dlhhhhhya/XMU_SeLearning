#include <iostream>
using namespace std;

class List {
public:
    List(){create_List();}
    ~List(){clear();}
    void create_List();
    void insert(const int& x1,const int& y1);
    void print();
private:
    //�ڵ�ṹ
    struct Node{
        int x,y;
        Node * next;
        Node(const int& x1,const int& y1):x(x1),y(y1),next(NULL){}
    };
    Node * head;//ͷ�ڵ�
    //����������
    void clear(){
        Node * p = head;
        //��ͷ�ڵ㿪ʼѭ��ɾ��
        while(p){
            Node * q = p->next;
            delete p;
            p = q;
        }
    }
};

//����ͷ���
void List::create_List()
{
     head = new Node(0,0);
}
//��ͷ����һ���ڵ�
void List::insert(const int& x1,const int& y1)
{
    Node *p = new Node(x1,y1);
    p->next = head->next;
    head->next = p;
}
//��ӡ����
void List::print()
{
    for(Node * p = head->next;p;p=p->next){
        cout << "x���꣺"<< p->x << "  y���꣺" << p->y << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    List house;
    house.insert(8,4);
    house.insert(7,2);
    house.insert(6,4);
    house.insert(4,3);
    house.insert(2,4);
    house.insert(1,2);
    house.insert(0,0);
    cout << "����Ϊ:" << endl; 
    house.print();
    return 0;
}
