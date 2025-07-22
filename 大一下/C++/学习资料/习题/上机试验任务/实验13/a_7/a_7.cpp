#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in_file;
	in_file.open("strings.txt", ios::in);
	
	if (!in_file.is_open())
	{
		cerr << "can't open the file";
		exit(-1);
	}

	string str;			//���ڴ�����Ҫ���ҵ��ַ���

	cout << "please input the string to find:" << endl;
	cin >> str;

	string file_line;	//���ļ��ж�ȡ��֮���ȡ�����ַ���
	int pos=0;
	int i = 0;

	getline(in_file, file_line);

	cout << "the position is: ";
	while ((pos=file_line.find(str,pos))!=string::npos)
	{
		cout << pos << " ";
		pos++;		//������ҵ��ˣ�pos�ᱻ��ֵΪ��һ�����ֵ�λ�ã�����֮���ٴβ��ң�ֱ���޷��ҵ�
		i++;
	}

	cout << endl << "�ܵĳ��ִ���:" << i << endl;

	in_file.close();
	return 0;
}