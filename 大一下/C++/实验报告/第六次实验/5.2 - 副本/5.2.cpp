#include <bits/stdc++.h>
#include "date.h"
//#include "date.cpp" 
using namespace std;
int main() {
	Date d;
	d.setdate(); 
	while(1) {
		cout<<"-----------------------\n";
		cout<<"-----�����趨ϵͳ------\n";
		cout<<"-----------------------\n";
		cout<<"--------[1]�趨--------\n";
		cout<<"--------[2]���--------\n";
		cout<<"------[Ctrl+C]�˳�-----\n";
		cout<<"-----------------------\n";
		int a;
		cin >> a;
		if(a==1) {
			cout<<"�����룺(Ĭ��Ϊ2010 12 25) �ո�ָ�"<<endl;
			int y,m,da;
			cin >> y >> m >> da;
			d.setdate(y,m,da);
		}
		if(a==2) {
			cout<<"���������ģʽ����1-3��"<<endl;
			int mod;
			cin >> mod;
			if(mod == 1){
				d.display1();
			}
			if(mod == 2){
				d.display2();
			}
			if(mod == 3){
				d.display3();
			}
		}
	}
	return 0;
}
