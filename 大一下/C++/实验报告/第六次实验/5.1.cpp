#include <bits/stdc++.h>
using namespace std;
class Date {
	private:
		int year,month,day;
	public:
		void display1() {
			cout << month << "-" << day << "-" << year%100 << endl;
		}
		void display2() {
			string monthchar[12]= {"January","February","March","April","May","June",
			                       "July","August","September","October","November","December"};
			                      cout << monthchar[month-1] << " " << day << "," << year << endl;
		}
		void display3() {
			string monthchar[12]= {"January","February","March","April","May","June",
			                       "July","August","September","October","November","December"};
			                      cout <<  day << " " << monthchar[month-1] << " " << year << endl;
		}
		int setdate(int y=2010,int m=12,int d=25) {
			if(d < 1 || d > 31) {
				cout << "day num error" << endl;
				return -1;
			}
			if(m < 1 || m > 12) {
				cout << "month num error" << endl;
			}
			year = y;
			month = m;
			day = d;
		}

};
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
