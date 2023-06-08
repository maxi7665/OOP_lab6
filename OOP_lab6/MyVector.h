#include <vector>
#include <string>

#pragma once
class MyVector
{
private:

	std::vector<int>* vector;

public:

	MyVector(int size);
	~MyVector();

	std::string getVectorStr();

	int max();
	void addMax();
	void sortByAbs();
	void standardDescSort();
};

