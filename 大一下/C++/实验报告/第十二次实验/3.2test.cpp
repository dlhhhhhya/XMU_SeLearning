#include<iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////
class A       //����
{
private:
    int privatedateA;
protected:
    int protecteddateA;
    int testfun(int a){
    	protecteddateA = a;
	} 
public:
    int publicdateA;
    void check(){
    	cout << protecteddateA << endl;
	}
};
//////////////////////////////////////////////////////////////////////////
class B :public A      //����A��������B�����м̳У�
{
public:
    void funct()
    {
        int b;
        b=protecteddateA; //ok������ı�����Ա����������Ϊ������Ա
        b=publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա
    }
	using A::testfun;
};
//////////////////////////////////////////////////////////////////////////
int main()
{
    int a; 
 	A objA;
 
    B objB;
    objB.testfun(3);
    objB.check();
    return 0;
}
