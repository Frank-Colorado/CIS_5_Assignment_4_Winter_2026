# CIS_5_Assignment_4_Winter_2026

**Functions & Parameter Passing: Employee Performance Scores**

## Program Goal
Create a C++ program that manages 10 employee performance scores (0–100) using functions with **pass by value**, **pass by pointer**, and **pass by reference**.

## Requirements

- Hard-code a fixed-size array of 10 integer scores:
  - int ary[10] = {75, 88, 62, 95, 50, 82, 70, 91, 45, 78}

Define and use these functions:

1. `int calculateSum(const int scores[], int size)`  
2. `double calculateAverage(int sum, int size)`  
3. `void addBonus(int scores[], int size, int bonus)`  
4. `int findMinimum(const int* scores, int size)`  
5. `int countHighPerformers(const int scores[], int size)`  

In `main()`:

- Print original scores
- Show sum and average
- Add bonus and print updated scores
- Show minimum score
- Show number of high performers (≥80)

## Expected Output Format
```
Original scores: 75 88 62 95 50 82 70 91 45 78
Sum: 736
Average: 73.60
Scores after +10 bonus: 85 98 72 105 60 92 80 101 55 88
Minimum score: 55
High performers (>=80): 6
```

## Implementation Hints
- Use `<iostream>` and `<iomanip>` (for fixed + setprecision(2))
- Add comments explaining each parameter passing method
- Use loops to print arrays and perform calculations
- Choose pointer or reference style consistently (but show both where possible)

## Submission
- File: `main.cpp`
- Upload to Canvas + GitHub repo

Here is the link to my demonstration video for this assignment: 

https://vimeo.com/1161301084?share=copy&fl=sv&fe=ci 
