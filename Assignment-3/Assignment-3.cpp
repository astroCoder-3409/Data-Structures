// Assignment-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include "Infix_To_Postfix.h";
#include "ListQueue.h";

using namespace std;

int main()
{   

    /*
    * 
    * QUEUE TESTING:
    ListQueue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << queue.frontThenPop() << endl;
    cout << queue.frontThenPop() << endl;
    cout << queue.frontThenPop() << endl;

    queue.empty() ? cout << "Queue is Empty" : cout << "Queue is not Empty";
    cout << endl;

    */
    
    Infix_To_Postfix converter;

    cout << "Enter expressions to be converted, or press Return when done\n";
    string expression;
    cout << "Infix: ";
    while (getline(cin, expression)) {
        if (expression == "") break;
        try {
            string result = converter.convert(expression);
            cout << "Postfix: " << result << endl;
        }
        catch (invalid_argument ex) {
            cout << "Error: " << ex.what() << endl;
        }
        cout << endl << "Moving on to next expression..." << endl;
        cout << "Infix: ";
    }


}

