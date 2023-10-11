#pragma once

#include <string>
using namespace std;



class Employee {
	protected:
		string name;
		int yearsWithCompany;
		const double weeksPerMonth = 4.34524;


	public:
		Employee(string _name, int _yearsWithCompany) : name(_name), yearsWithCompany(_yearsWithCompany) {}
		string get_name();
		virtual double calculate_weekly_salary() = 0;
		virtual double calculate_HC_contributions_week() = 0;
		virtual double calculate_vacation_days_week() = 0;
}; 

/*
Rules:
1. Professionals earn half as many vacation days per week as years they've been with the company, rounded down
2. Healthcare contributions for professionals is 100$ of weekly salary
*/
class Professional : public Employee {
	private:
		double monthlySalary;
		const double weeksPerMonth = 4.34524;
		
	public:
		Professional(string _name, int _yearsWithCompany, double _monthlySalary) : 
			Employee(_name, _yearsWithCompany), monthlySalary(_monthlySalary) {}
		double calculate_weekly_salary();
		double calculate_HC_contributions_week();
		double calculate_vacation_days_week();
};

/*
Rules:
1. Nonprofessionals earn 1 vacation day per 60 hours they work (not rounded), + 1 day for 
   every 3 years they've been with the company (rounded)
2. Healthcare contributions for nonprofessionals is 50$ of weekly salary
*/
class Nonprofessional : public Employee {
private:
	double hourlyRate;
	double hoursWorked;
	
public:
	Nonprofessional(string _name, int _yearsWithCompany, double _hourlyRate, double _hoursWorked) :
		Employee(_name, _yearsWithCompany), hourlyRate(_hourlyRate), hoursWorked(_hoursWorked) {}
	double calculate_weekly_salary();
	double calculate_HC_contributions_week();
	double calculate_vacation_days_week();
};