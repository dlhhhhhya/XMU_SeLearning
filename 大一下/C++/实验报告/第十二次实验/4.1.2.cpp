#include<iostream>
using namespace std;

//����People
class People{
protected:
    char *m_name;
    int m_age;
};

//������Student
class Student: public People{
public:
	float m_score;
    void display();
};
void Student::display(){
    cout<<"�����ϵĳɼ���"<<m_score<<"��"<<endl;
}

int main(){
    Student stu;
    stu.m_score=90.5; 
    stu.display();

    return 0;
}
