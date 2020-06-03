// Problem 3: Create a function that takes an array of numbers and returns the sum of the two lowest positive numbers.
//
// Show results for these inputs :
//
// sumTwoSmallestNums([19, 5, 42, 2, 77])
//
// sumTwoSmallestNums([10, 343445353, 3453445, 3453545353453])
//
// sumTwoSmallestNums([2, 9, 6, -1])
//
// sumTwoSmallestNums([879, 953, 694, -847, 342, 221, -91, -723, 791, -587])
//
// sumTwoSmallestNums([3683, 2902, 3951, -475, 1617, -2385])

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

/// <summary>
/// Given an array of numbers, returns the sum of the two lowest positive numbers.
/// </summary>
/// <param name="nums">- Input array</param>
/// <param name="size">- Size of input array</param>
/// <returns>Sum of the two lowest positive numbers</returns>
int64_t sumTwoSmallestNums(int64_t* nums, int size) {
	
	// Initialize two variables min1 and min2 to max value
	int64_t min1 = INT64_MAX;
	int64_t min2 = INT64_MAX;

	// Iterate over array elements
	for (int i = 0; i < size; i++) {
		int64_t num = nums[i];
		
		// Discard if negative
		if (num < 0) continue;

		// If num greater than min1, shift min1 value to min2 and set min1 to num
		if (num < min1) {
			min2 = min1;
			min1 = num;
		}

		// If num less than min1 but greater than min2, set min2 to num
		else if (num < min2) {
			min2 = num;
		}
	}

	// Return sum of min1 and min2 
	return min1 + min2;
}

/// <summary>
/// Main function.
/// </summary>
/// <returns>Code 0 if program successful</returns>
int main() {

	// Initialize inputs
	int64_t* inputs[5];
	inputs[0] = new int64_t[5] { 19,5,42,2,77 };
	inputs[1] = new int64_t[4] { 10, 343445353, 3453445, 3453545353453 };
	inputs[2] = new int64_t[4] { 2, 9, 6, -1 };
	inputs[3] = new int64_t[10] { 879, 953, 694, -847, 342, 221, -91, -723, 791, -587 };
	inputs[4] = new int64_t[6] { 3683, 2902, 3951, -475, 1617, -2385 };
	int size[5] = { 5,4,4,10,6 };

	for (int i = 0; i < 5; i++) {

		// Print input array
		cout << "Input: [";
		for (int j = 0; j < size[i]; j++) {
			cout << inputs[i][j] << ", ";
		}
		cout << "\b \b\b \b]" << endl;

		// Print output
		cout << "Output: " << sumTwoSmallestNums(inputs[i], size[i]) << "\n" << endl;
	}

	// Exit with code 0
	return 0;
}