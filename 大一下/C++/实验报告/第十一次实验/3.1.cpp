#include<iostream>
using namespace std;
class Complex {
	private:
		double real;
		double im;
	public:
		Complex() {}
		Complex(double r, double i) {
			real=r;
			im=i;
		}
		Complex(const Complex &t) {
			real=t.real;
			im=t.im;
			cout<<"HAHA    ";
		}
		double getReal() const {
			return real;
		}
		Complex& operator+(Complex& other);//Ҫ��д������ʵ�ָ����ļӣ���"+"��������
		friend istream& operator>>(istream &input,Complex &in) { ///Ҫ��д������ʵ�ֶ�Complex�����>>��<<����
			input >> in.real >> in.im ;
			return input;
		}
		friend ostream& operator<<(ostream &output,Complex &out) {
			output << "(" << out.real << "+" << out.im << "i)" << endl;
			return output;
		}
//		friend ostream& operator<<(ostream &output,Complex out) { //Ϊ�����䷵��ֵΪ�����cout 
//			output << "(" << out.real << "+" << out.im << "i)" << endl;
//			return output;
//		}
		Complex& operator++();
		Complex& operator+=(Complex oth);
};
Complex tmp;
Complex& Complex::operator+(Complex& other) { //Ҫ��д������ʵ�ָ����ļӣ���"+"��������
	tmp.real = real+other.real;
	tmp.im = im+other.im;
	return tmp;
}
Complex& Complex::operator++() {
	tmp.real = real;
	tmp.im = im;
	real++;
	return tmp;
}
Complex& Complex::operator+=(Complex oth){
	real += oth.real;
	im += oth.im;
	return *this;
}
int main() {
	Complex a,b,c;
	cin >> a >> b;
	cout << (b+=a);
	return 0;
}
