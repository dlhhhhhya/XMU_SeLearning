#include <iostream>
#include <string>
using namespace std;

int main()
{
	string* p;
	
	try
	{
		if ((p = new string) == NULL)throw 'e';
	}
	catch (char)
	{
		cout << "�޷������ڴ棡" << endl;
	}

	return 0;
}