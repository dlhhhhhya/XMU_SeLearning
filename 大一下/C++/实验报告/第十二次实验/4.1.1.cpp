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
private:
    float m_score;
public:
    Student(float score);
    void display();
};
Student::Student(float score): People(),m_score(score){ }
void Student::display(){
    cout<<"�����ϵĳɼ���"<<m_score<<"��"<<endl;
}

int main(){
    Student stu(90.5);
    stu.display();
    return 0;
}
