#include <iostream>
#include "Assignment-1.h"
#include <array>
#include<iostream>

using namespace std;

int indexOfNum(array<int, 20> arr, int num) {
	for (int i = 0; i < 20; i++) {
		if (arr[i] == num) {
			return i;
		}
	}
	return -1;
}

array<int, 2> replaceAtIndex(array<int, 20> &arr, int index, int newVal) {
	array<int, 2> oldNewArr;
	oldNewArr[0] = arr[index]; //sets old value
	oldNewArr[1] = newVal;
	arr[index] = newVal;
	
	return oldNewArr;
}

void addToEnd(array<int, 20> &arr, int newVal) {
	for (int i = 10; i < 18; i++) {
		if (arr[i] == 0) {
			arr[i] = newVal;
			break;
		}
	}
}

void removeElement(array<int, 20> &arr, int index) {
	for (int i = index; i < 18; i++) {
		arr[i] = arr[i + 1];
	}
	arr[19] = 0;
}

void outputArr(array<int, 20> arr) {
	for (int i = 0; i < 20; i++) {
		cout << arr[i] << endl;
	}
}

