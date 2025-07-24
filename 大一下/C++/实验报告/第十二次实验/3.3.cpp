#include<bits/stdc++.h>
using namespace std;
class Vehicle {
	protected:
		int wheel;
		int weight;
		bool state;
	public:
		Vehicle(int w1,int w2) {
			wheel = w1;
			weight = w2;
			state = false;
		}
		bool change(bool s) {
			if(s == state) {
				cout << "----- Error -----" << endl;
				cout << " �Ѿ����ڴ�״̬��" << endl;
				cout << "----- Admin -----" << endl << endl;
			} else {
				state = s;
				cout << "----- Succ ------" << endl;
				cout << "�޸�state:" << state << "�ɹ�!" << endl;
				cout << "----- Admin -----" << endl << endl;
			}
		}
		int getwheel() {
			return wheel;
		}
		int getweight() {
			return weight;
		}
};
class Car:public Vehicle {
	private:
		int passenger;
	public:
		Car(int w1,int w2,int p):Vehicle(w1,w2) {
			passenger = p;
		}
		Car(const Car &oth):Vehicle(oth.wheel,oth.weight) {
			passenger = oth.passenger;
		}
		Car& operator+(Car &a);
		void display() {
			cout << "----- State -----" << endl;
			cout << "����" << endl;
			cout << "������:" << wheel << endl;
			cout << "����:" << weight << endl;
			cout << "*�ؿ���:" << passenger << endl;
			if(state == 1) {
				cout << "����״̬:����" << endl;
			} else {
				cout << "����״̬:�ر�" << endl;
			}
			cout << "----- Admin -----" << endl << endl;
		}
};
Car& Car::operator+(Car &a) {
	cout << this->wheel << " " << weight << " " << passenger<< endl;
	static Car tmp=Car(wheel+a.wheel,weight+a.weight,passenger+a.passenger);
	return tmp;
} //�����Ե�дһ������
class Truck:public Vehicle {
	private:
		int carriage;
	public:
		Truck(int w1,int w2,int p):Vehicle(w1,w2) {
			carriage = p;
		}
		Truck operator+(Truck a) {
			return Truck(wheel+a.wheel,weight+a.weight,carriage+a.carriage);
		} //�����Ե�дһ������
		void display() {
			cout << "----- State -----" << endl;
			cout << "����" << endl;
			cout << "������:" << wheel << endl;
			cout << "����:" << weight << endl;
			cout << "*������:" << carriage << endl;
			if(state == 1) {
				cout << "����״̬:����" << endl;
			} else {
				cout << "����״̬:�ر�" << endl;
			}
			cout << "----- Admin -----" << endl;
		}
};
int main() {
	cout << "Loading..." << endl;
	vector<Car> car;
	vector<Truck> tru;
	cout << "Success!" << endl;
	while(1) {
		cout << "-- Main manage --" << endl;
		cout << " - 1 -  ��ӳ��� " << endl;
		cout << " - 2 -  �ϲ����� " << endl;
		cout << " - 3 -  ���س��� " << endl;
		cout << " - 4 -  �г�����" << endl;
		cout << " - CTRL+C - �˳� " << endl;
		cout << "----- Admin -----" << endl;
		int a;
		cin >> a;
		if(a==1) {
			cout << "--- Car added ---" << endl;
			cout << "����������(1:Car 2:Truck):";
			int b;
			cin >> b;
			if(b==1) {
				int w1,w2,p;
				cin >> w1 >> w2 >> p;
				car.push_back(Car(w1,w2,p));
				cout << "��ӳɹ���" << endl << endl;
			}
			if(b==2) {
				int w1,w2,p;
				cin >> w1 >> w2 >> p;
				tru.push_back(Truck(w1,w2,p));
				cout << "��ӳɹ���" << endl << endl;
			}
		}
		if(a==2) {
			cout << "--- Car conbined ---" << endl;
			cout << "����������(1:Car 2:Truck):";
			int b;
			cin >> b;
			if(b==1) {
				int w1,w2;
				cin >> w1 >> w2;
				car.push_back(car[w1-1]+car[w2-1]);
				car.erase(car.begin()+w2-1);
				car.erase(car.begin()+w1-1);
				cout << "�ϲ��ɹ���" << endl << endl;
			}
			if(b==2) {
				int w1,w2;
				cin >> w1 >> w2;
				tru.push_back(tru[w1-1]+tru[w2-1]);
				tru.erase(tru.begin()+w2-1);
				tru.erase(tru.begin()+w1-1);
				cout << "�ϲ��ɹ���" << endl << endl;
			}
		}
		if(a==3) {
			cout << "--- Car seted ---" << endl;
			cout << "����������(1:Car 2:Truck) ��� ����״̬:";
			int b,c,d;
			cin >> b >> c >> d;
			if(b==1) {
				car[c-1].change(d);
			}
			if(b==2) {
				tru[c-1].change(d);
			}
		}
		if(a==4) {
			cout << "------ CAR ------" << endl;
			for(int i = 0; i != car.size(); i++) {
				cout << i+1 << ":" << endl;
				car[i].display();
			}
			cout << "------ TRU ------" << endl;
			for(int i = 0; i != tru.size(); i++) {
				cout << i+1 << ":" << endl;
				tru[i].display();
			}
			cout << "-----------------" << endl << endl;
		}
	}
	return 0;
}
