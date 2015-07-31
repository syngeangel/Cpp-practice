#include<iostream>
using namespace std;

class String
{
public:
	String():str(NULL){}
	const char* c_str(){ return str; }
	char* operator=(const char*s);//重载operator=函数的声明
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
	s = "王杰快点看书";
	cout << s.c_str() << endl;
	s = "大家好好学习！";
	cout << s.c_str() << endl;
	getchar();
	return 0;
}