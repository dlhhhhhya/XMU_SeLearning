#include <iostream>
using namespace std;
class A {
	public:
		A() {
			f();
			cout << "A::A()" << endl;
		}
		virtual ~A() {
			cout << "~A"<< endl;
		}
		virtual void f() {
			cout << "A::f"<< endl;
		}
		void g() {
			cout << "A::g"<< endl;
		}
		void h() {
			f();
			g();
		}
};
class B: public A {
	public:
		B(){
			cout << "B::B()" << endl;
		}
		~B(){
				cout << "~B"<< endl;
			};
		void f() {
			cout << "B::f"<< endl;
		};
		void g() {
			cout << "B::g"<< endl;
		};
};
int main() {
	B b; //���� B::B(), A::A()�� A::f
//	A a;
	A *p;
	p=&b;
	p->f(); //���� B::f
	p->A::f(); //���� A::f
	p->g(); //���� A::g
	cout << endl;
	p->h(); //����_____(1)___
	cout << endl;
	p = new B; //����_____(2)___
	cout << endl;
	delete p; //����_____(3)___
	cout << endl;
}
