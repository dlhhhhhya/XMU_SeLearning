#include <iostream>
#include <string>
using namespace std;
class vehicle { //������
	protected:
		string* name;
		string* color;
	public:
		vehicle();
		~vehicle() {
			delete name;
			delete color;
		}
		virtual istream & operator>>(istream &in) =0;
		virtual ostream & operator<<(ostream &out) =0;
};
vehicle::vehicle() {
	name = new string;
	color = new string;
}
class car:public vehicle { //С������
		int passenger;//������
	public:
		virtual istream & operator>>(istream &in){
			in >> *name >> *color >> passenger;
			return in;
		}
		virtual ostream & operator<<(ostream &out){
			out << "С������" << *name << endl << "��ɫ��" << *color << endl << "��������" << passenger <<endl;
			return out; 
		}
};

class truck:public vehicle { //������
		int payload;//������
	public:
		virtual istream & operator>>(istream &in){
			in >> *name >> *color >> payload;
			return in;
		}
		virtual ostream & operator<<(ostream &out){
			out << "��������" << *name << endl << "��ɫ��" << *color << endl << "��������" << payload <<endl;
			return out;
		}

};

int main() {
	car a;
	truck b;
	a.operator>>(cin);
	b.operator>>(cin);
	a.operator<<(cout);
	b.operator>>(cin);
	system("pause");
	return 0;
}


