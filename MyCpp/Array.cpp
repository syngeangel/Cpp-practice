#include<iostream>

using namespace std;
typedef double array[10];
void main(){
	array a{ 12, 34, 56, 78, 90, 76, 54, 43, 32, 21 };
	array &b = a;
	a[2] = 100;
	for (int i = 0; i < 10; i++){
		cout << b[i] << " ";
	}
	getchar();
}
