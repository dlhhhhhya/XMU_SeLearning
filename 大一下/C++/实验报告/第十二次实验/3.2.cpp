
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
};
//////////////////////////////////////////////////////////////////////////
class B :public A      //����A��������B�����м̳У�
{
public:
    void funct()
    {
        int b;
        b=privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���
        b=protecteddateA; //ok������ı�����Ա����������Ϊ������Ա
        b=publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա
    }
//    int testfun(int a){ //����һ 
//    	protecteddateA = a;
//	}
	using A::testfun;     //������ 
};
//////////////////////////////////////////////////////////////////////////
class C :private A  //����A��������C��˽�м̳У�
{
public:
    void funct()
    {
        int c;
        c=privatedateA;    //error��������˽�г�Ա�����������ǲ��ɼ���
        c=protecteddateA;  //ok������ı�����Ա����������Ϊ˽�г�Ա
        c=publicdateA;     //ok������Ĺ�����Ա����������Ϊ˽�г�Ա
    }
};
//////////////////////////////////////////////////////////////////////////
class D :protected A   //����A��������D�������̳У�
{
public:
    void funct()
    {
        int d;
        d=privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���
        d=protecteddateA; //ok������ı�����Ա����������Ϊ������Ա
        d=publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա
    }
};
//////////////////////////////////////////////////////////////////////////
int main()
{
    int a; 
 	A objA;
	a=objA.protecteddateA; //error���������ı�����Ա�Զ��󲻿ɼ�
 
    B objB;
    a=objB.privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���,�Զ��󲻿ɼ�
    a=objB.protecteddateA; //error������ı�����Ա����������Ϊ������Ա���Զ��󲻿ɼ�
    a=objB.publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա���Զ���ɼ�
 
    C objC;
    a=objC.privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���,�Զ��󲻿ɼ�
    a=objC.protecteddateA; //error������ı�����Ա����������Ϊ˽�г�Ա���Զ��󲻿ɼ�
    a=objC.publicdateA;    //error������Ĺ�����Ա����������Ϊ˽�г�Ա���Զ��󲻿ɼ�
 
    D objD;
    a=objD.privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���,�Զ��󲻿ɼ�
    a=objD.protecteddateA; //error������ı�����Ա����������Ϊ������Ա���Զ��󲻿ɼ�
    a=objD.publicdateA;    //error������Ĺ�����Ա����������Ϊ������Ա���Զ��󲻿ɼ�
 
    return 0;
}
