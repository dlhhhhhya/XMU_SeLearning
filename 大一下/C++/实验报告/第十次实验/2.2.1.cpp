#include <iostream>
using namespace std;
class Time {
	public:
		Time(int,int,int);
		friend void display(Time &t);
		void prin();
	private:
		int hour;
		int minute;
		int sec;
};

Time::Time(int h,int m,int s) {
	hour=h;
	minute=m;
	sec=s;
}

void Time:: prin(){
	cout<<hour<<minute<<sec;
}

void display(Time &t) {
	cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;   //ֱ����������hour��minute��sec
}

int main() {
	Time t1(10,13,56);
	display(t1);
	t1.prin(); //��Ա�����ĵ���
	return 0;
}

