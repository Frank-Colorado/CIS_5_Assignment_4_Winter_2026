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

	// Finally I return the total sum of the scores
	return sum;
}

// Function to calculate the average score of all employee performance scores
// Here I passed both parameters by value since they are just small integers and there is no need to modify the original data
// This function takes two parameters:
// 1. An integer representing the total sum of the scores
// 2. An integer representing the size of the array
static double calculateAverage(int sum, int size) {

	// I calculate the average by dividing the total score by the size of the array and return the result
	return static_cast<double>(sum) / size; // I cast totalScore to double to ensure we get a precise average
}

// Function to add a bonus to each employee performance score
// Here I don't use a constant pointer since I want to be able to modify the original scores array
// This function takes three parameters:
// 1. A pointer to an array of integers (the scores)
// 2. An integer representing the size of the array
// 3. An integer representing the bonus amount to be added
static void addBonus(int* scores, int size, int bonus) {
	// First I check to make sure that the scores pointer is not null
	if (scores == nullptr) return;


	// I use a traditional for loop to iterate through the array and add the bonus to each score
	for (int i = 0; i < size; ++i) {
		scores[i] += bonus; // This is equivalent to *(scores + i) = *(scores + i) + bonus; 
	}
}

// Function to find the minimum employee performance score
// Here I use a constant pointer again because I don't want to modify the original scores array
// This function takes two parameters:
// 1. A constant pointer to an array of integers (the scores)
// 2. An integer representing the size of the array
static int findMinimum(const int* scores, int size) {

	// I initialize a variable to hold the minimum score and set it to the first element of the array
	int minScore = scores[0]; // This is equivalent to int minScore = *(scores + 0);

	// I use a traditional for loop to iterate through the array and find the minimum score
	// I start at the first index since I already used the zeroth index to initialize minScore
	for (int i = 1; i < size; ++i) {
		// I use a conditional to check if the current score is less than the current minimum score
		if (scores[i] < minScore) {
			// If it is, I update minScore to the current score
			minScore = scores[i];
		}
	}

	// Finally I return the minimum score found
	return minScore;
}

// Function to count the number of high performing employees (defined as having a score greater than or equal to 80)
// Here I use a constant pointer again because I don't want to modify the original scores array
// This function takes two parameters:
// 1. A constant pointer to an array of integers (the scores)
// 2. An integer representing the size of the array
static int countHighPerformers(const int* scores, int size) {

	// I initialize a variable to hold the count of high performers
	int count = 0;

	// I use a traditional for loop to iterate through the array and count the number of high performers
	for (int i = 0; i < size; ++i) {
		// I use a conditional to check if the current score is greater than or equal to 80
		if (scores[i] >= 80) {
			// If it is, I increment the count variable
			++count;
		}
	}

	// Finally I return the count of high performers
	return count;
}

// ------------------------------------------------------------------------------------------------------------------------------------
// Main function
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
	cout << "Original Employee Performance Scores: ";
	printScores(scores, SIZE);

	// Calling the calculateSum function to get the sum of all the scores 
	int totalScore = calculateSum(scores, SIZE);

	// Calling the calculateAverage function to get the average score
	double averageScore = calculateAverage(totalScore, SIZE);

	// Printing the total and average scores with formatting
	cout << "\n\nTotal Employee Performance Score: " << totalScore;
	cout << "\nAverage Employee Performance Score: " << std::fixed << std::setprecision(2) << averageScore << "\n";

	// Calling the addBonus function to add the bonus to each employee score
	addBonus(scores, SIZE, bonus);

	// Calling printScores function to print out the new scores after adding the bonus
	cout << "\nEmployee Performance Scores after adding bonus of " << bonus << ": ";
	printScores(scores, SIZE);

	// Function to get the minimum score after adding the bonus
	int minScore = findMinimum(scores, SIZE);

	// Function to show the number of high performing employees (defined as having a score greater than or above 80)
	int highPerformers = countHighPerformers(scores, SIZE);

	// Then I print out the minimum score and number of high performers
	cout << "\n\nMinimum Employee Performance Score after bonus: " << minScore;
	cout << "\nNumber of High Performing Employees (Score >= 80): " << highPerformers << "\n";


	return 0;
}