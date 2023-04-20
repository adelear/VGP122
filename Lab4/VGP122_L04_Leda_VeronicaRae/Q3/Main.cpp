/* Write a program to count the number of vowels and consonants in a character array, using
pointers. */


// use for loop to separate a string by character 
// if i == "a" or "e" or "i" or "u" = vowels+=1
// else{ consonants +=1


#include <iostream>
#include <string> 

using namespace std; 

void findConsAndVowels(char array[], int* cons, int* vowels) { 
	int conNum = 0;
	int vowNum = 0;
	for (int i = 0; i < strlen(array); i++) {
		if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u' || array[i] == 'A' || array[i] == 'E' || array[i] == 'I' || array[i] == 'O' || array[i]=='U') {
			vowNum += 1;
		}
		else { 
			conNum += 1; 
		}
	}
	*vowels = vowNum;
	*cons = conNum; 
}


int main() {

	
	cout << "Enter a word: "; 
	string word; 
	cin >> word; 
	char wordArray[100];
	strcpy_s(wordArray, sizeof(wordArray), word.c_str()); 

	int cNum, vNum; 
	findConsAndVowels(wordArray, &cNum, &vNum); 

	cout << "Vowels: " << vNum << endl;
	cout << "Consonants: " << cNum << endl;

	return 0;
}