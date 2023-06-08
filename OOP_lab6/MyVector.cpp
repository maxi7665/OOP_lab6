#include <vector>
#include <limits>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include "MyVector.h"
#include "AddFunctor.h"

#define NUMBER_LENGTH 3

#define m1 -10
#define m2 10

MyVector::MyVector(int size)
{
	this->vector = new std::vector<int>(size);

	srand((unsigned)time(NULL));

	for (int i = 0; i < vector->size(); i++)
	{
		vector->at(i) = (rand() % (abs(m1 - m2) + 1)) + m1;
	}
}

MyVector::~MyVector()
{
	delete this->vector; 
}

std::string MyVector::getVectorStr()
{
	std::stringstream ss;

	std::vector<int>::iterator iter = this->vector->begin();

	for (iter; iter < this->vector->end(); iter++)
	{
		ss << std::setw(NUMBER_LENGTH) << *iter << " ";
	}
	
	ss << std::endl;

	return ss.str();
}

template <class T> T findMax(std::vector<T>* vector, T minValue)
{
	T maxValue = minValue;

	for (int i = 0; i < vector->size(); i++)
	{
		if (vector->at(i) > maxValue)
		{
			maxValue = vector->at(i);
		}
	}

	return maxValue;
}

int MyVector::max()
{
	int max = findMax<int>(vector, std::numeric_limits<int>::min());

	return max;
}

void MyVector::addMax()
{
	AddFunctor add{};

	int max = this->max();

	for (int i = 0; i < vector->size(); i++)
	{
		add(&(vector->at(i)), max);	
	}
}

bool intSortCriterion(const int int1, const int int2)
{
    return abs(int1) <= abs(int2);
}

void mergeArray(std::vector<int>* vector, int left, int middle, int right, bool(*op)(int, int))
{
    int leftArrayLength = middle - left + 1;
    int rightArrayLength = right - middle;
    std::vector<int>* leftTempArray = new std::vector<int>(leftArrayLength);
    std::vector<int>* rightTempArray = new std::vector<int>(rightArrayLength);

    int i, j;

    for (i = 0; i < leftArrayLength; i++)
    {
        leftTempArray->at(i) = vector->at(left + i);
    }
    for (j = 0; j < rightArrayLength; j++)
    {
        rightTempArray->at(j) = vector->at(middle + 1 + j);
    }

    i = 0;
    j = 0;
    int k = left;

    while (i < leftArrayLength
        && j < rightArrayLength)
    {
        if (op(leftTempArray->at(i), rightTempArray->at(j)))
        {
            vector->at(k++) = leftTempArray->at(i++);
        }
        else
        {
            vector->at(k++) = rightTempArray->at(j++);
        }
    }

    while (i < leftArrayLength)
    {
        vector->at(k++) = leftTempArray->at(i++);
    }

    while (j < rightArrayLength)
    {
        vector->at(k++) = rightTempArray->at(j++);
    }

    delete leftTempArray;
    delete rightTempArray;
}

std::vector<int>* sort(std::vector<int>* vector, int left, int right, bool(*op)(int, int))
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        sort(vector, left, middle, op);
        sort(vector, middle + 1, right, op);
        mergeArray(vector, left, middle, right, op);
    }

    return vector;
}

std::vector<int>* mergeSort(std::vector<int>* vector, bool(*op)(int, int))
{
    if (vector->size() == 0
        || vector->size() == 1)
    {
        return new std::vector<int>(*(vector));
    }

    std::vector<int>* ret = new std::vector<int>(*(vector));

    ret = sort(ret, 0, ret->size() - 1, op);

    return ret;     
}

void MyVector::sortByAbs()
{
    std::vector<int>* prevVector = this->vector;

    this->vector = mergeSort(this->vector, intSortCriterion);

    delete prevVector;
}

void MyVector::standardDescSort()
{
    std::sort(
        this->vector->begin(),
        this->vector->end(),
        [](int a, int b) {
            return a > b;
        });
}

