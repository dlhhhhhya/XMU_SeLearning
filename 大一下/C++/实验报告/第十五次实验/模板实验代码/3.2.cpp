#include<iostream>
#define NO -1
using namespace std;
template<typename T>
class data {
		T *a;
		int n;
	public:
		data(T *t,int s):a(t),n(s) {}
		T sum() {
			T m=0;
			for(int i=0; i<n; i++)
				m+=a[i];
			return m;
		}
		int find(T s) {
			for(int i=0; i<n; i++)
				if(a[i]==s)
					return i;
			return NO;
		}
		void display() {
			for(int i=0; i<n; i++)
				cout<<a[i]<<" ";
		}
};
int main() {
	int a[]= {1,2,3,4,5,6,7,8,9};
	double b[]= {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
	int c;
	double d;
	data<int> m(a,9);
	data<double> n(b,9);
	cout<<"����m�е�����Ԫ��Ϊ��";
	m.display();
	cout<<endl;
	cout<<"����n�е�����Ԫ��Ϊ��";
	n.display();
	cout<<endl;
	cout<<"����m�е�����Ԫ�صĺ�Ϊ��";
	cout<<m.sum()<<endl;
	cout<<"����n�е�����Ԫ�صĺ�Ϊ��";
	cout<<n.sum()<<endl;
	cout<<"��������m�е�Ԫ�أ�";
	cin>>c;
	cout<<"Ԫ������λ��Ϊ��"<<m.find(c)<<endl;
	cout<<"��������n�е�Ԫ�أ�";
	cin>>d;
	cout<<"Ԫ������λ��Ϊ��"<<n.find(d)<<endl;
}
