#include<iostream>
using namespace std;

class CRectangle
{
public:
	CRectangle(int w_, int h_);
	~CRectangle();
	static void PrintTotal();

private:
	int w, h;
	static int nTotalArea;
	static int nTotalNumber;

};
//外部初始化
int CRectangle::nTotalArea = 0;
int CRectangle::nTotalNumber = 0;

CRectangle::CRectangle(int w_,int h_)
{
	w = w_;
	h = h_;
	nTotalNumber++;
	nTotalArea += w*h;
}

CRectangle::~CRectangle()
{
	nTotalNumber--;
	nTotalArea -= w*h;
}

void CRectangle::PrintTotal()
{
	cout << nTotalNumber << "," << nTotalArea << endl;
	getchar();
}

//主入口
int main()
{
	CRectangle r1(3, 3), r2(2, 2);
	CRectangle::PrintTotal();
	r1.PrintTotal();
	return 0;
}