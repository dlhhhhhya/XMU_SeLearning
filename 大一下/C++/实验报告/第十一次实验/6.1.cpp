#include<iostream>
#include<cstring>
using namespace std;
class MyString {
		friend ostream& operator<<(ostream&out,MyString &ob);//��Ԫ��������<<����Ԫ����
		friend istream& operator>>(istream&in,MyString &ob);//��Ԫ��������>>����Ԫ����
	private:
		char *str;
		int size;//�ַ�������
	public:
		MyString();//�޲ι���
		MyString(const char *str);//�вι��캯��
		MyString(const MyString &ob);//��������
		~MyString();//��������
		int Size(void);//�����ַ�������
		char& operator[](int i);//��Ա��������[]
		MyString& operator =(const MyString &ob);//��Ա��������= ʵ���ֵ ob1=ob2;
		MyString& operator+(const MyString &ob);//��Ա��������+ ʵ��ob1+ob2
		MyString& operator+(const char *str);//��Ա��������+ ʵ��ob1+"abc"
		MyString& operator+=(const MyString &ob);//��Ա��������+= ʵ��ob1+=ob2
		bool operator==(const MyString&ob);//��Ա��������== �ж�ob1==ob2
		bool operator==(const char *str);//��Ա��������== �ж�ob1=="abc"
};
MyString::MyString() {
	this->str=NULL;
	this->size=0;
	cout<<"�޲ι���"<<endl;
}

MyString::MyString(const char *str) {
	cout<<"char * ���캯��"<<endl;
	this->str=new char [strlen(str)+1];
	strcpy(this->str,str);
	this->size=strlen(str);
}
MyString::MyString(const MyString &ob) {
	cout<<"�������캯��"<<endl;
	this->str=new char[strlen(ob.str)+1];
	strcpy(this->str,ob.str);
	this->size=ob.size;
}

MyString::~MyString() {

	if(this->str!=NULL) {
		delete str;
		this->str=NULL;
	}
	cout<<"��������"<<endl;
}

int MyString::Size() {
	return this->size;
}

char& MyString::operator[](int i) {
	if(i>=0&&i<this->size)
		return (this->str)[i];
	else
		cout<<"�±���Ч"<<endl;
}

MyString &MyString::operator =(const MyString &ob) {
	//�Ƚ�this->str�ľɿռ��ͷŵ�
	if(this->str!=NULL) {
		delete str;
		this->str=NULL;
	}
	this->str=new char[strlen(ob.str)+1];
	strcpy(this->str,ob.str);
	this->size=strlen(ob.str);
	cout<<"=�Ÿ�ֵ"<<endl;
	return *this;
}

MyString& MyString::operator+(const MyString &ob) {
	/*
	int tmp_size=strlen(this->str)+strlen(ob.str)+1;
	char *tmp=new char[tmp_size];
	strcpy(tmp,this->str);
	strcat(tmp,ob.str);

	MyString s (tmp);
	if(tmp!=NULL)
	{
	    delete tmp;
	    tmp=NULL;
	}
	return s; //����д������ʵ��cout<<str1+str2<<endl;
			 //ֻ��ʵ��MyString s1=str1+str2;
			 //        cout<<s1<<endl;����Ϊc++�������涨��ʱ����������Ϊ��const����
	*/
	int tmp_size=strlen(this->str)+strlen(ob.str)+1;
	char *tmp=new char[tmp_size];
	strcpy(tmp,this->str);
	strcat(tmp,ob.str);
	static MyString s(tmp);//static����sֻ��ʵ����һ�������Ҳ�����Ϊ��仰��tmp�ı�ֵ
	if(strcmp(s.str,tmp)!=0)//����s�����е�ֵ
		strcpy(s.str,tmp);
	if(tmp!=NULL) { //��ʱ�ͷŶ�������Ŀռ�
		delete tmp;
		tmp=NULL;
	}
	return s;
}

MyString& MyString::operator+=(const MyString &ob) {
	int tmp_size=strlen(this->str)+strlen(ob.str)+1;
	char *tmp=new char[tmp_size];
	strcpy(tmp,this->str);
	strcat(tmp,ob.str);
	this->str=tmp;
	return *this;
}

MyString& MyString::operator+(const char *str) {
	int tmp_size=strlen(this->str)+strlen(str)+1;
	char *tmp=new char[tmp_size];
	strcpy(tmp,this->str);
	strcat(tmp,str);
	static MyString s (tmp);
	if(strcmp(s.str,tmp)!=0)
		strcpy(s.str,tmp);
	if(tmp!=NULL) {
		delete tmp;
		tmp=NULL;
	}
	return s;
}
bool MyString::operator==(const MyString &ob) {
	if((strcmp(this->str,ob.str)==0)&&(this->size==ob.size))
		return true;
	else
		return false;
}

bool MyString::operator==(const char *str) {
	if((strcmp(this->str,str) == 0)&&(this->size==strlen(str)))
		return true;
	else
		return false;
}

ostream& operator<<(ostream&out,MyString &ob) {
	out<<ob.str;
	return out;
}

istream &operator>>(istream &in, MyString &ob) {
	//�ǵý�ԭ�����ݲ���
	if(ob.str!=NULL) {
		delete ob.str;
		ob.str=NULL;
	}
	char buf[1024]="";//��ʱbuf
	in.getline(buf,1024);//�ȵõ�������������� Ȼ�����buf��ʵ�ʴ�С���ٿռ䣬����1023���һλ��\0
	ob.str=new char [strlen(buf)+1];
	strcpy(ob.str,buf);
	ob.size=strlen(buf);
	return in;
}
int main(){
	MyString a("hx is handsone,"),b("while cyb is stupid.");
	a+=b;
	cout << a;
	return 0;
} 
