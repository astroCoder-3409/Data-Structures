#include "withoutTryCatch.cpp"
#include "tryCatchVersion.cpp"
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "Assignment-1.h"

using namespace std;

const bool USING_TRY_CATCH = true;

int main()
{
    fstream dataFile;

    dataFile.open("data.txt", ios::in);

    array<int, 20> data;
    string tempStr;

    if (dataFile.is_open()) {

        //initialize, build, and output the starting array
        for (int i = 0; i < 10; i++) {
            if (getline(dataFile, tempStr)) {
                data[i] = stoi(tempStr);
                cout << tempStr << endl;
            }
        }
        dataFile.close();
    }
    //set the next 10 elements to 0
    for (int i = 10; i < 20; i++) {
        data[i] = 0;
        cout << to_string(data[i]) << endl;
    }

    string tempInput[2]; //an array so that we can hold two temp values
    array<int, 2> tempInt;


    cout << "1) Enter a number to check the index of: ";
    cin >> tempInput[0];
    cout << endl << "The index is " << to_string(indexOfNum(data, stoi(tempInput[0]))) << endl;

    cout << "2) Enter an index of an element to replace with a new number: ";
    try {
        cin >> tempInput[0];
        if (stoi(tempInput[0]) > 19 || stoi(tempInput[0]) < 0) {
            throw out_of_range("The index you have entered is out of bounds.");
        }
    }
    catch (out_of_range& err) {
        cerr << err.what() << endl;
    }
    cout << endl << "2) Now enter what you want the element at your index to be replaced with: ";
    cin >> tempInput[1];
    tempInt = replaceAtIndex(data, stoi(tempInput[0]), stoi(tempInput[1]));
    cout << endl << "2) You have replaced " << to_string(tempInt[0]) << " with " << to_string(tempInt[1]) << " at index " << tempInput[0] << endl;
    cout << "Here is the modified array: " << endl;
    outputArr(data);

    cout << endl << "3) Enter a number to add to the array: " << endl;
    try {
        cin >> tempInput[0];
        if (stoi(tempInput[0]) == 0) {
            throw "The input can't be zero.";
        }
    }
    catch (string err) {
        cout << err << endl;
    }
    addToEnd(data, stoi(tempInput[0]));
    cout << "Here is the modified array: " << endl;
    outputArr(data);

    cout << endl << "4) Enter the index of the element which you want to remove: ";
    cin >> tempInput[0];
    removeElement(data, stoi(tempInput[0]));
    cout << "Here is the modified array: " << endl;
    outputArr(data);

}