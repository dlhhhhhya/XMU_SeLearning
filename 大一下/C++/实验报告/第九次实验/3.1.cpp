#include <bits/stdc++.h> 
using namespace std;

class MyString {
	private:
		char* text;
	public:
		MyString(const char* str = NULL);//��ͨ������ʽ
		~MyString();//�⹹��ʽ
		MyString(const MyString& other);//����������ʽ
		MyString& operator=(const MyString& other); //��ֵ��ʽ

	public:
		void print(); //��ӡ��˽�б���text;

};

MyString::MyString(const char* str) {
	cout<< "MyString(const char* str)" <<endl;
	if (str == NULL) {
		text = new char[1];
		*text = '\0';
	} else {
		int len = strlen(str);
		text = new char[len+1];
		strcpy(text, str);
	}
}

MyString::~MyString() {
	cout << "~MyString()"<< endl;
	delete []text;
	text = NULL;
}

MyString::MyString(const MyString& other) {
	cout<< "MyString(const MyString& other)"<<endl;
	int len = strlen(other.text);
	text = new char[len + 1];
	strcpy(text, other.text);

}

MyString& MyString::operator=(const MyString& other) {
	cout << "MyString& operator=(continue MyString& other)" << endl;
	if (&other == this) {
		return *this;
	}

	else {
		delete []text;
		text = NULL;
		int len = strlen(other.text);
		text = new char[len + 1];
		strcpy(text, other.text);
		return *this;
	}
}

void MyString::print() {
	cout << "text="<< text << "  "<< strlen(text) << endl;
}

int main() {

	MyString mystr("this is mystring"); //��ͨ���캯�� 

	MyString str1(mystr); //��ֵ���캯�� 
	MyString str2 = mystr; //��ֵ���캯�� 

	MyString str3;
	str3 = str2;

	str3.print();

	return 0;



}
