#include <iostream>
#include <iomanip>

using std::cout;



// Function to print the employee performance scores
// Here I use a constant reference to the scores array to prevent modification of the original data
// I also need to specify the size of the array in the reference or else the ranged based for loop will not work
// This function takes two parameters:
// 1. A constant pointer to an array of integers (the scores)
// 2. An integer representing the size of the array
static void printScores(const int(&scores)[10], int size) {
	// I use a ranged base for loop to iterate through the array since I am just reading through the values
	for (int score : scores) {
		cout << score << " ";
	}
}

int main() {

	// Variable that holds the size of the array 
	const int SIZE = 10; 

	// Array of int scores holding all the employee performance scores
	int scores[SIZE] = { 75, 88, 62, 95, 50, 82, 70, 91, 45, 78 };

	// Variable to hold the bonus amount
	int bonus = 10;

	// Function to print the original employee scores 
	printScores(scores, SIZE);





	return 0;
}