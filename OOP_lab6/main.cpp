#include <iostream>
#include <iomanip>
#include "MyVector.h"

#define NUMBER_LENGTH 4

using namespace std;

int main()
{
	cout << "LR#6 VAR2" << endl << endl;

	MyVector* vector = new MyVector(20);

	cout << "Vector: " << endl << vector->getVectorStr() << endl << endl;

	cout << "Max: " << vector->max() << endl;

	vector->addMax();

	cout << "Max added to each element: " << endl << vector->getVectorStr() << endl;

	vector->sortByAbs();

	cout << "Vector sorted by absolute value: " << endl << vector->getVectorStr() << endl;

	vector->standardDescSort();

	cout << "Vector sorted in descending order by STL algorithm: " << endl << vector->getVectorStr() << endl;

	return 0;
}