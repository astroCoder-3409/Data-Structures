// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Single_Linked_List.h"
#include "Employee_Management.h"
using namespace std;

int main()
{
    
    Single_Linked_List<int> myList;
    myList.push_back(1);
    myList.push_front(2);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.pop_front();
    myList.pop_back();

    myList.insert(3, 9);
    
    int pos = myList.find(3);
    myList.remove(pos);

    cout << "Front value: " << to_string(myList.front()) << endl;
    cout << "Back value: " << to_string(myList.back()) << endl;

    cout << "Full linked list: " << endl;
    int i = 0;
    while (myList.item_at(i) != NULL) {
        cout << to_string(myList.item_at(i)) << endl;
        i++;
    }
    
    //Employee classes testing:
    string name;
    string yearsWithCompany;
    string monthlySalary;
    
    cout << endl << "Enter a name for your Professional employee: " << endl;
    cin >> name;
    cout << "Enter how many years your Professional employee has been with the company: " << endl;
    cin >> yearsWithCompany;
    cout << "Enter your Professional employee's monthly salary: " << endl;
    cin >> monthlySalary;
    cout << endl;
    
    Professional profEmployee(name, stoi(yearsWithCompany), stod(monthlySalary));

    string hourlyRate;
    string hoursWorked;

    cout << "Enter a name for your Nonprofessional employee: " << endl;
    cin >> name;
    cout << "Enter how many years your Nonprofessional employee has been with the company: " << endl;
    cin >> yearsWithCompany;
    cout << "Enter your Nonprofessional employee's hourly rate: " << endl;
    cin >> hourlyRate;
    cout << "Enter how many hours your Nonprofessional employee worked this week: " << endl;
    cin >> hoursWorked;
    cout << endl << endl;


    Nonprofessional nonProfEmployee(name, stoi(yearsWithCompany), stod(hourlyRate), stod(hoursWorked));

    cout << "--- " << profEmployee.get_name() << " ---" << endl;
    cout << "Weekly salary: " << to_string(profEmployee.calculate_weekly_salary()) << endl;
    cout << "Health care contributions from this week: " << to_string(profEmployee.calculate_HC_contributions_week()) << endl;
    cout << "Vacation days earned this week: " << to_string(profEmployee.calculate_vacation_days_week()) << endl;
    cout << endl;
    cout << "--- " << nonProfEmployee.get_name() << " ---" << endl;
    cout << "Weekly salary: " << to_string(nonProfEmployee.calculate_weekly_salary()) << endl;
    cout << "Health care contributions from this week: " << to_string(nonProfEmployee.calculate_HC_contributions_week()) << endl;
    cout << "Vacation days earned this week: " << to_string(nonProfEmployee.calculate_vacation_days_week()) << endl;
}
