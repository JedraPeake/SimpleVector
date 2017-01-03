#pragma warning(disable:4996)
#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main() {

	//checking Constructors
	SimpleVector sv1;
	SimpleVector sv2(20);

	//checking both are empty and of size 0
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 0 and empty is true
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 0 and empty is true

	sv1.push_back(5);
	sv2.pop_back();// this should not crash 
	sv1.print();// this should print Element at position 0 is 5
	sv2.print();//nothing should be printed here
	cout << "adding 0-9 to sv1 and sv2" << endl;
	for (int i = 0; i < 10; i++) 
	{
		sv1.push_back(i);
		sv2.push_back(i);
	}
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 11 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out sv2 is size 10 and empty is false
	sv1.print();// should contain 5 then 0-9
	sv2.print();// should contain 0-9

	//checking insert
	cout << "popping elements off sv1 and sv2 then inserting elements" << endl;
	for (int i = 0; i < 5; i++) {
	sv1.pop_back();
	sv2.pop_back();
	}
	cout << "this should be 0 " << sv1.insert(-999, 0) << endl;// should not error should print out 0
	cout << "this should be 1 " << sv2.insert(-999, 5) << endl;// should not error should print out 1
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 7 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out sv2 is size 5 and empty is false
	cout << "sv1 is now" << endl;
	sv1.print();// should be -999 then 5 then 0-4
	cout << "sv2 is now" << endl;
	sv2.print();// should be 0-4

	//checking set and [] operator
	cout << "setting elements" << endl;
	sv1.set(-777, 0);//start of sv1 should now be -777
	sv2.set(-777, 4);//end of sv2 should now be -777
	sv1[sv1.size() - 1] = -777;//end of sv1 should now be -777
	sv2[0] = -777;//end of sv2 should now be -777
	sv1.print();
	sv2.print();

	//checking clear
	sv1.clear();
	sv2.clear();
	cout << "there should be nothing but this sentence here" << endl << endl;
	sv1.print();
	sv2.print();
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 0 and empty is true
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 0 and empty is true

	cout << endl;

	//checking reverse
	for (int i = 0; i < 10; i++) {
	sv1.push_back(i);
	sv2.push_back(i);
	}
	sv1.reverse();
	sv2.reverse();
	cout << "these should be backwards order" << endl;
	sv1.print();
	cout << endl;
	sv2.print();
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 10 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 0 and empty is false



	//making large to check to make sure extend is being called properly
	sv1.clear();
	sv2.clear();
	for (int i = 0; i < 1000; i++) {
	sv1.push_back(i);
	sv2.push_back(i);
	}
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 1000 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 1000 and empty is false

	cout << "if we got here with no errors we are probably ok" << endl;
}

SimpleVector::SimpleVector()	//default constructors creates an array of size 10
{
	_numElements = 0;
	_capacity = 10;
	_array = new int[_capacity];
}

SimpleVector::SimpleVector(int x)		// default constructors creates an array of a given integer size
{
	_numElements = 0;
	_capacity = x;
	_array = new int[_capacity];
}

void SimpleVector::push_back(int x)
{
	if (_numElements >= _capacity) //only extend array if numelements >= capacity
	{
		extend();
	}
	_array[_numElements] = x;
	_numElements++; //counter because numElements has incrased by one
}

void SimpleVector::reverse()
{
	int temp = 0; //value to record the value of the array at i in the loop below
	for (int i = 0; i < _numElements / 2; i++)
	{
		temp = _array[_numElements - 1 - i];
		_array[_numElements - 1 - i] = _array[i];//sets value of array at i to be the value of array at _numElements-i-1  
		_array[i] = temp;//set value at array i to be the temp value, therfore these elements have been swapped.
	}
}

void SimpleVector::set(int x, int i)
{
	if (_numElements > i > 0)//check that the index is in the range
	{
		_array[i] = x;//index i in the array equals x
	}
	else
	{
		std::cout << "Index out of bounds" << std::endl;
	}

}

int SimpleVector::empty()//if _numElements==0, the array is empty even though it's capacity>0
{
	if (_numElements == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void SimpleVector::pop_back()
{
	_array[_numElements];
	if (_numElements > 0)//Check to make sure _numElements < 0.
	{
		_numElements--;
	}
}

void SimpleVector::extend()
{
	int *_array2; //creating a new array dynamically, with double the _capacity
	_array2 = new int[2 * _capacity];

	for (int i = 0; i < _capacity; ++i)
	{
		_array2[i] = _array[i];//copy old array into new one
	}

	_capacity = 2 * _capacity; //reseting the _capacity to be double
	delete[] _array;//delete the old array
	_array = _array2;
}

int SimpleVector::insert(int x, int i)
{
	if (_numElements > i > 0)//check that the index is in the range
	{
		push_back(0); //called to ensure there is enough size in the array, because it will increase the size by 1

		for (int j = _numElements - 1; j > i; --j)//move all the elements up one position
		{
			_array[j] = _array[j - 1];
		}

		_array[i] = x;//put x into the array
		return 0;
	}
	else
	{
		return 1;
	}
}

void SimpleVector::print()
{
	for (int i = 0; i < _numElements; ++i)
	{
		std::cout << "Element at position " << i << " " << _array[i] << std::endl;
	}
}

int& SimpleVector:: operator[](int i) 
{
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}

const int& SimpleVector::operator[](int i) const 
{
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}

SimpleVector::~SimpleVector() //Destructor
{
	delete[] _array;
}





