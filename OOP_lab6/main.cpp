#include <iostream>
#include "MyVector.h"

using namespace std;

int main()
{
	cout << "LR#6 VAR2" << endl << endl;

	MyVector* vector = new MyVector(20);

	cout << "Vector: " << vector->getVectorStr() << endl << endl;

	cout << "Max: " << vector->max() << endl;

	vector->addMax();

	cout << "Max added to each element: " << vector->getVectorStr() << endl;

	vector->sortByAbs();

	cout << "Vector sorted by absolute value: " << vector->getVectorStr() << endl;

	return 0;
}