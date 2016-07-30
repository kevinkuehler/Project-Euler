/*
Project Euler Problem 19
Kevin Kuehler
https://github.com/kevinkuehler/Project-Euler

*****************************************************************************

Prompt:
You are given the following information, but you may prefer to do some research for yourself.

• 1 Jan 1900 was a Monday.
• Thirty days has September,
  April, June and November.
  All the rest have thirty-one,
  Saving February alone,
  Which has twenty-eight, rain or shine.
  And on leap years, twenty-nine.
• A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <iostream>

using namespace std;

int isLeapYear(int);
int getMonthLength(int, int);
int nextMonthStartDay(int, int, int);

int main() {
	int day = 2, year = 1901, month = 1, sundays = 0; 

	for (year; year <= 2000; year++) {
		for (int month = 1; month <= 12; month++) {
			if (!day) sundays++;
			day = nextMonthStartDay(day, month, year);
		}
	}
	cout << sundays << endl;
}

/*
	Returns 1 if the year is a leap year and 0 if not. 
*/
int isLeapYear(int year) {
	return (!(year % 100) ? !(year%400) : !(year%4));
}


int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
/*
	Returns the days in each month, leap years accounted for. 
*/
int getMonthLength(int month, int year) {
	return (month == 2) ? months[month - 1] + isLeapYear(year) : months[month - 1];
}

/*
	Returns the day of the week the next month starts on.
*/
int nextMonthStartDay(int startday, int month, int year) {
	return (startday + getMonthLength(month,year)) % 7;
}
