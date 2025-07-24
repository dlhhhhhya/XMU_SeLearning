#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX_NUM_OF_COURSES=30;
const int MAX_ID_LEN=10;
const int MAX_NAME_LEN=8;
class StudentScores {
	public:
		StudentScores() {
			initialized = false;
		}
		bool data_is_ok() const {
			return initialized;
		}
	private:
		int scores[MAX_NUM_OF_COURSES],num_of_courses;
		char id[MAX_ID_LEN+1],name[MAX_NAME_LEN+1];
		bool initialized;
		friend istream &operator >>(istream &in, StudentScores &x);
		friend ostream &operator <<(ostream &out, StudentScores &x);
};
istream &operator >>(istream &in, StudentScores &x){
	//����ʱ����bug ��Ӱ��ʹ�� ������ 
	cout << "������ѧ�ţ�" ;
	in >> x.id;
	cout << "������������" ;
	in >> x.name;
	cout << "������ѡ��������";
	in >> x.num_of_courses;
	if(x.num_of_courses>MAX_NUM_OF_COURSES){
		cout << "ѡ�γ�������������޸�Ϊ30����";
		x.num_of_courses = MAX_NUM_OF_COURSES; 
	}
	for(int i=1;i<=x.num_of_courses;i++){
		cout << "�������" << i << "�ſεĳɼ���"; 
		in >> x.scores[i];
	}
	x.initialized = true;
	return in;
}
ostream &operator <<(ostream &out, StudentScores &x){
//	�汾1���ʺϿ��Ե�ʱ��д�ģ�����ʦ���Ƚ��������ʵ�����Ǵ�ģ��Ƽ�����д���֣� ���� 
	out << endl << "ѧ��������" << x.name << endl << "ѧ�ţ�" << x.id << endl << "ѡ��������" << x.num_of_courses << endl;
	for(int i=1;i<=num_of_courses;i++){
		out << "��" << i << "�ſΣ�" << scores[i] << "points." << endl; 
	}
	return out; 
//	�汾2����ȷ����ʹ�õİ汾�� 
	out << x.id << endl << x.name << endl << x.num_of_courses << endl;
	for(int i=1;i<=x.num_of_courses;i++){
		out << x.scores[i] <<  endl; 
	}
	return out; 
}
int main() {
	//ʵ���� ����̫�鷳�� ��д��ȡһ��ѧ���ĳ��򡣡���
	StudentScores tmp;
	ifstream fout("F:\\temp.ini");
	if(!fout){
		cout << "δ�����ļ��洢��ѧ����Ϣ����ֱ�ӿ�ʼд�룡" << endl; 
	} else{
		//�����л�����ֵ���� ��������� 
		fout >> tmp;
		cout << endl << tmp;
	}
	fout.close();
	ofstream readin("F://temp.ini");
	cin >> tmp;
	readin << tmp;
}
