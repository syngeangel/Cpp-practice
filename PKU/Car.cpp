class CTyre{
private:
	int radius;
	int width;
public:
	CTyre(int r, int w):radius(r), width(w){}
};

class CEngine{
};

class CCar
{
public:
	CCar(int p,int tr,int tw);
	~CCar();

private:
	int price;
	CTyre tyre;
	CEngine engine;
};

CCar::CCar(int p, int tr, int w) :price(p), tyre(tr,w)
{
}

CCar::~CCar()
{
}

int main(){
	CCar car(20000, 17, 226);
	return 0;
}