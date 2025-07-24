#include <bits/stdc++.h>
using namespace std;
class Person {
	private:
		char* pName;
	public:
		Person(char *pN="noName") {
			cout<<"������  "<<pN<<"\n";
			pName=new char[strlen(pN)+1];
			if (pName) strcpy(pName,pN);
		}
		Person(Person &a) {
			cout<<"����������  "<<a.pName<<"\n";
			pName=new char[strlen(a.pName)+1];
			if (pName) strcpy(pName,a.pName);
		}
		~Person(){
			cout<<"������������  "<<pName<<"\n";
			delete pName;
		}
};

int main() {
	Person * hx, *cyb;
	hx = new Person("˧��");
	cyb = new Person(*hx);
	delete cyb;
	return 0;
}
