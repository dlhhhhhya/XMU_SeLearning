#include <iostream>
#include <string>
#include <vector> 
using namespace std;
vector<string> save; 
void encrypt(string s){
	string cache;
	save.push_back(s);
	for(auto i : s){ //	�൱��for(string::size_type i=0;s[i]!='\0';i++){
		cache.insert(cache.end(),i+8);
	} 
	cout << "�������ݣ�" << cache << endl;
}
void outcrypt(string s){
	string cache;
	for(auto i : s){ //	�൱��for(string::size_type i=0;s[i]!='\0';i++){
		cache.insert(cache.end(),i-8);
	}
	for(auto i : save){
		if(i == cache){
			cout << "���ܳɹ���" << cache << endl; 
			return;
		}
	}
	cout << "����ʧ�ܣ�" << endl;
}
int main() {
	while(1){
		cout<<"-----------------------\n";
		cout<<"-----�ַ�����ϵͳ------\n";
		cout<<"-----------------------\n";
		cout<<"--------[1]����--------\n";
		cout<<"--------[2]����--------\n";
		cout<<"------[Ctrl+C]�˳�-----\n";
		cout<<"-----------------------\n";
		int a;
		cin >> a;
		if(a==1){
			cout<<"�����룺"<<endl;
			string w;
			getline(cin,w);
			getline(cin,w);
			encrypt(w);
		} 
		if(a==2){
			cout<<"�����룺"<<endl;
			string w;
			getline(cin,w);
			getline(cin,w);
			outcrypt(w);
		} 
	}
	
}

