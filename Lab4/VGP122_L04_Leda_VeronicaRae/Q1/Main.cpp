/* Write a program to find the max value of an integer array data set. The program will ask the user
to input the number of data values in the set and each value. The program prints on screen a
pointer that points to the max value. */


#include <iostream>
using namespace std;

int* findMax(int array[], int arraySize) {
    int largest = 0;
    for (int i = 0; i < arraySize; i++) {
        if (array[i] > array[largest]) {
            largest = i;
        }
    }
    return &array[largest];
} 

int main() {
    const int SIZE = 10;
    int size; 
    cout << "Enter the amount of numbers to input: ";
    cin >> size;  
    int arr[SIZE]; 

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << "/" << size << endl;
        cin >> arr[i];
    }

    cout << "The largest number " << *findMax(arr, size) << " is located at " << findMax(arr, size) << endl; 
    return 0; 
}
