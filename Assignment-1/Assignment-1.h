#pragma once
#include <array>

using namespace std;
/**
* returns: index of given value. -1 if value is not present in array
*/
int indexOfNum(array<int, 20> arr, int num);

/**
* returns: int array of length 2. First value is the old value, second value is the new value.
*/
array<int, 2> replaceAtIndex(array<int, 20> &arr, int index, int newVal);

/**
* Sets first zero element to given value.
* pre: empty entries must be 0. Will not effect "zero" entries before index 10.
*/
void addToEnd(array<int, 20>& arr, int newVal);

/**
* removes an element by shifting the later elements backwards in the array. Sets the last element to 0.
*/
void removeElement(array<int, 20>& arr, int index);

/**
*  helper function to dump array contents
*/
void outputArr(array<int, 20> arr);

