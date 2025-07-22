#include <iostream>
#include <string.h>
using namespace std;
class String {
	public:
		String(const char *str=NULL); // ��ͨ���캯��
		String(const String &other); // �������캯��
		~String(); // ��������
		String& operator=(const String &other); // ��ֵ����
		void show() {
			cout<<m_data<<endl;
		}
		friend ostream& operator<<(ostream&out,String &ob);//���ⲻҪ�� �������ԣ���Ԫ��������<<����Ԫ����
		friend istream& operator>>(istream&in,String &ob);//���ⲻҪ�� �������ԣ���Ԫ��������>>����Ԫ����
	private:
		char *m_data; // ���ڱ����ַ���
};
//under this is my answer
#define SIZE 50
String::String(const char *str){
	m_data = new char [SIZE];
} 
String::String(const String &other){
	m_data = new char [strlen(other.m_data)+1];
	for(int i=0;i<=strlen(other.m_data);i++){
		m_data[i] = other.m_data[i];
	}
}
String::~String(){
	delete [] m_data; 
}
String& String::operator=(const String &other){ //����thisָ�� 
	if(strlen(other.m_data)>=50){
		delete []m_data;
		m_data = new char [strlen(other.m_data)+1];
	}
	for(int i=0;i<=strlen(other.m_data);i++){
		m_data[i] = other.m_data[i];
	}
}
ostream& operator<<(ostream&out,String &ob) {//���ⲻҪ�� �������ԣ�
	out<<ob.m_data;
	return out;
}

istream &operator>>(istream &in, String &ob) {//���ⲻҪ�� �������ԣ�
	//�ǵý�ԭ�����ݲ���
	if(ob.m_data!=NULL) {
		delete ob.m_data;
		ob.m_data=NULL;
	}
	char buf[SIZE]="";//��ʱbuf
	in.getline(buf,SIZE);//�ȵõ�������������� Ȼ�����buf��ʵ�ʴ�С���ٿռ䣬����1023���һλ��\0
	ob.m_data=new char [strlen(buf)+1];
	strcpy(ob.m_data,buf);
	return in;
}
int main(){
	String a;
	cin >> a;
	String b=a;
	String* d = new String;
	cout << a << endl;//���ⲻҪ�� �������ԣ�
	cout << b << endl;//���ⲻҪ�� �������ԣ�
	delete d;
}
// Ҳ�����˺ü���bug�ŸĶ�...���Ե�ʱ��д����ſ�ܼ��� ��ʦ�������� ���� 
