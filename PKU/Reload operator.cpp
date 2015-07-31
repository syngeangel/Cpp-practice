#include<iostream>
using namespace std;

class String
{
public:
	String():str(NULL){}
	const char* c_str(){ return str; }
	char* operator=(const char*s);//����operator=����������
	~String();

private:
	char* str;
};


String::~String()
{
	if (str) delete[] str;
}

char* String::operator=(const char* s)
{
	if (str) delete[] str;
	if (s){
		str = new char[strlen(s) + 1];
		strcpy(str,s);
	}
	else
	{
		str = NULL;
	}
	return 0;
}

int main(){
	String s;
	s = "���ܿ�㿴��";
	cout << s.c_str() << endl;
	s = "��Һú�ѧϰ��";
	cout << s.c_str() << endl;
	getchar();
	return 0;
}