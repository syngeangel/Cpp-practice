#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class CShape{
public:
	virtual double Area() = 0;//=0���麯��
	virtual void PrintInfo() = 0;

};

class CRectangle :public CShape{
public:
	int w, h;
	virtual double Area();
	virtual void PrintInfo();
};

class CCircle :public CShape{
public:
	int r;
	virtual double Area();
	virtual void PrintInfo();
};

class CTriangle :public CShape{
public:
	int a, b, c;
	virtual double Area();
	virtual void PrintInfo();
};

double CRectangle::Area(){
	return w*h;
}

void CRectangle::PrintInfo(){
	cout << "Rectangle:" << Area() << endl;
}

double CCircle::Area(){
	return 3.14*r*r;
}

void CCircle::PrintInfo(){
	cout << "Circle:" << Area() << endl;
}

double CTriangle::Area(){
	double p = (a + b + c) / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));	//���׹�ʽ�����������
}

void CTriangle::PrintInfo(){
	cout << "Triangle:" << Area() << endl;
}

CShape *pShapes[100];
int MyCompare(const void *s1, const void *s2);

int main(){
	int i, n;
	CRectangle *pr; CCircle *pc; CTriangle *pt;
	cout << "������Ҫ�Աȵ�ͼ�θ���" << endl;
	cin >> n;
	cout << "����ͼ������ĸ(R��C��T)" << endl;
	for (i = 0; i < n; i++){
		char c;
		cin >> c;
		switch (c)
		{
		case'R':
			pr = new CRectangle();
			cout << "����w��h" << endl;
			cin >> pr->w >> pr->h;
			pShapes[i] = pr;
			break;
		case'C':
			pc = new CCircle();
			cout << "����r" << endl;
			cin >> pc->r;
			pShapes[i] = pc;
			break;
		case'T':
			pt = new CTriangle();
			cout << "����������������" << endl;
			cin >> pt->a >> pt->b >> pt->c;
			pShapes[i] = pt;
			break;
		default:
			break;
		}
		qsort(pShapes, n, sizeof(CShape*), MyCompare);
		for (i = 0; i < n; i++){
			pShapes[i]->PrintInfo();
		}
	}
}
int MyCompare(const void *s1, const void *s2){
	double a1, a2;
	CShape **p1; //s1,s2��void*,����д*s1�����s1ָ�������
	CShape **p2;
	p1 = (CShape**)s1;
	p2 = (CShape**)s2;
	a1 = (*p1)->Area();
	a2 = (*p2)->Area();
	if (a1 < a2) return -1;
	else if (a1 > a2) return 1;
	else return 0;
}

