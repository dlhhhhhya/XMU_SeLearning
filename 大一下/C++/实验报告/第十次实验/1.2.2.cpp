#include <iostream>
using namespace std;
class Date {
	public:
		Date(int y,int m,int d);
		void showDate( );
	private:
		const int year;
		const int month;
		const int day;
};
Date::Date(int y,int m,int d):year(y),month(m),day(d){    } //��������Ϊ��
void Date::showDate( )  {
	cout<<year<<"."<<month<<"."<<day<<endl;
}
int main() {
	Date date1(2009,10,15);
	date1.showDate(); //��contst��Ա�������Է���const�����ݳ�Ա
	return 0;
}

