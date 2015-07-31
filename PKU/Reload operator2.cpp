#include<iostream>
using namespace std;

class MyString
{
public:
	MyString() :str(NULL){}
	const char* c_str(){ return str; }
	char* MyString::operator=(const char* s);//����operator=����������
	MyString& operator=(const MyString& s);//�����գ�����ȸ���
	~MyString();

private:
	char* str;
};

char* MyString::operator=(const char* s)	//����=
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


MyString& MyString::operator=(const MyString& s){	//Ϊ�˸���ȫ
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