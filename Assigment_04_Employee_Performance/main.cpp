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

// Function to calculate the sum of all employee performance scores
// Here I used a constant pointer to the scores array to prevent modification of the original data
// This function takes two parameters:
// 1. A constant pointer to an array of integers (the scores)
// 2. An integer representing the size of the array
static int calculateSum(const int* scores, int size) {
	// Here I initialize a variable to hold the sum of the scores
	int sum = 0;
	// I use a traditional for loop to loop through the array and calculate the sum
	for (int i = 0; i < size; ++i) {
		// I add each score to the sum variable
		sum += scores[i]; // This is equivalent to sum = sum + *(scores + i); Because of how arrays and pointers work I can use either notation
	}
	return sum;
}

// Function to calculate the average score of all employee performance scores
// Here I passed both parameters by value since they are just small integers and there is no need to modify the original data
// This function takes two parameters:
// 1. An integer representing the total sum of the scores
// 2. An integer representing the size of the array
double calculateAverage(int sum, int size) {
	// I calculate the average by dividing the total score by the size of the array and return the result
	return static_cast<double>(sum) / size; // I cast totalScore to double to ensure we get a precise average
}

int main() {

	// Variable that holds the size of the array 
	const int SIZE = 10; 

	// Array of int scores holding all the employee performance scores
	int scores[SIZE] = { 75, 88, 62, 95, 50, 82, 70, 91, 45, 78 };

	// Variable to hold the bonus amount
	int bonus = 10;


	// Just like in the lab exercise I pass "scores" into almost all my functions. I learned that this is because in C++ arrays decay to pointers when passed into functions.
	// So "scores" is the same as "&scores[0]" or a reference to the first element of the array.
	// Because scores is "technically" already a reference I don't need to use the "&" operator when passing it into functions that take pointer parameters.

	// Function to print the original employee scores 
	printScores(scores, SIZE);

	// Calling the calculateSum function to get the sum of all the scores 
	int totalScore = calculateSum(scores, SIZE);

	// Calling the calculateAverage function to get the average score
	int averageScore = calculateAverage(totalScore, SIZE);





	return 0;
}