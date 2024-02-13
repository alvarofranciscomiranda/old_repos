#include<iostream>
#include<vector>
#include<string>

using namespace std;

template <typename T>
	
void showVector(string vName,const vector<T> &v)
{
	cout << vName << "[] = { ";
	for(vector<T>::const_iterator vPtr = v.begin(); vPtr != v.end(); vPtr++)
		cout << *vPtr << " ";
	cout <<	"} \n ";
}
int main(){
	const int SIZE = 5;
	int a[SIZE] = { 1,2,3,4,5 };
	vector<int> v1(a, a + SIZE);
	// initializing a vector from an array vector<double> v2(10, 0.1);
	// 10 elements, all equal to 0.1
	showVector("v1", v1);
	for
		(	vector<	int>::iterator vPtr = v1.begin(); vPtr != v1.end(); vPtr++)
		*vPtr = *vPtr * 10;
	showVector(	"v1", v1);
	/*showVector("v2", v2);*/
	// what is the result of this cycle ?
		for
			(vector<double>::iterator vPtr =v2.begin() + 1; vPtr != v2.end();vPtr++)
			*vPtr = *vPtr + *(vPtr - 1);
	//vector supportsRANDOM ITERATORS
		/*showVector("v2", v2);*/
	return 0;
}