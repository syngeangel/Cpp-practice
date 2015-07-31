#include<iostream>
using namespace std;

class MyString
{
public:
	MyString() :str(NULL){}
	const char* c_str(){ return str; }
	char* MyString::operator=(const char* s);//重载operator=函数的声明
	MyString& operator=(const MyString& s);//更保险，能深度复制
	~MyString();

private:
	char* str;
};

char* MyString::operator=(const char* s)	//重载=
{
	if (str) delete[] str;
	if (s){
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
	else
	{
		str = NULL;
	}
	return 0;
}


MyString& MyString::operator=(const MyString& s){	//为了更安全
	if (str) delete[] str;
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
	return *this;
}

MyString::~MyString(){
	if (str) delete[] str;
}

int main(){
	MyString s1,s2;
	s1 = "Hello";
	s2 = "My";
	s1 = s2;
	cout << s1.c_str() << endl;
	getchar();
	return 0;

}