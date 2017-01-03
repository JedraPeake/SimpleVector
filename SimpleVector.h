#pragma once
#include<iostream>

class SimpleVector {
private:
	int *_array;
	int _numElements;
	int _capacity;
	void extend(); //extend is only called in the class and not from the main so it can be private as the main does not need to access it
public:
	SimpleVector(); //default constructors creates an array of size 10
	
	SimpleVector(int x); // default constructors creates an array of a given integer size

	void push_back(int x);
	
	int size() //Checking how many _numElements in the _array
	{return _numElements;}
	
	void reverse();
	
	void set(int x, int i);
	
	void clear() //remove all _numElements from the array, therefore set _numElements=0
	{_numElements = 0;}
	
	int empty();

	void pop_back();//shorten _numElements by 1 

	int insert(int x, int i);

	void print();

	int& operator[](int i);
	
	const int& operator[](int i) const;

	~SimpleVector(); //Deletes all the heap memory
};

