/* Create a class called Date that includes three pieces of information as data members—a month
(type int), a day (type int) and a year (type int). Your class should have a constructor with three
parameters that uses the parameters to initialize the three data members. For the purpose of this
exercise, assume that the values provided for the year and day are correct, but ensure that the
month value is in the range 1–12; if it isn’t, set the month to 1. Provide a set and a get function for
each data member. Provide a member function displayDate that displays the month, day and year
separated by forward slashes (/). Write a test program that demonstrates class Date’s capabilities. */

#include <iostream> 
using namespace std;

class Date {
	private: 
		int month;
		int day; 
		int year; 

	public:
		Date() { // Constructor 
			cout << "Enter MM DD YYYY" << endl; 
			int m, d, y; 
			bool invalid = true; 
			while(invalid) {
				cin >> m;
				if (m > 0 && m < 13) {
					invalid = false; 
				}
				else {
					cout << "Enter valid month." << endl;
				}
			}
			setMonth(m); 
			cin >> d; 
			setDay(d);
			cin >> y; 
			setYear(y); 
		}

		//SETTERS
		void setMonth(int m){
			month = m; 
		}

		void setDay(int d) {
			day = d; 
		}
		
		void setYear(int y) {
			year = y;
		}
		//GETTERS
		int getMonth() {
			return month; 
		}

		int getDay(int d) {
			return day; 
		}

		int getYear(int y) {
			return year; 
		}
		void displayDate() {
			cout << month << "/" << day << "/" << year << endl;
		}

};

int main() {
	Date myBirthday; 
	myBirthday.displayDate();  
	return 0;
}