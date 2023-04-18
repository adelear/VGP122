/* Write a single C++ statement or line that accomplishes each of the following:
a. Print the message "Enter two numbers".
b. Input two integer values from the keyboard into integer variables b and c.
c. Assign the product of variables b and c to variable a.
d. Print the value of variable a. */

//
#include <iostream>

using namespace std;

int main(){

    int a;
    int b;
    int c;
    cout << "Enter two numbers:" << endl;
    cin >> b; 
    cin >> c; 

    a = b*c; 

    cout << "Product is " << a;

    return 0;
}