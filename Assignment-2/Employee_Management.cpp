#pragma once

#include <string>
#include "Employee_Management.h"
using namespace std;

string Employee::get_name() {
	return name;
}

double Professional::calculate_weekly_salary() {
	return monthlySalary / weeksPerMonth;
}

double Professional::calculate_HC_contributions_week() {
	if (this->calculate_weekly_salary() > 100) return 100.0;
	else return this->calculate_weekly_salary();
}

double Professional::calculate_vacation_days_week() {
	return yearsWithCompany / 2;
}

double Nonprofessional::calculate_weekly_salary() {
	return hourlyRate * hoursWorked;
}

double Nonprofessional::calculate_HC_contributions_week() {
	if (this->calculate_weekly_salary() > 50) return 50.0;
	else return this->calculate_weekly_salary();
}

double Nonprofessional::calculate_vacation_days_week() {
	return (hoursWorked / 60) + int(yearsWithCompany / 3);
}