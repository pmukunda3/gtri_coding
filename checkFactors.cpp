//Problem 2: Write a function that returns true if all integers in an array are factors of a number, and false otherwise.
//
//Show the results for these inputs :
//
//checkFactors([2, 3, 4], 12)
//
//checkFactors([1, 2, 3, 8], 12)
//
//checkFactors([1, 2, 50], 100)
//
//checkFactors([3, 6], 9)

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

/// <summary>
/// Returns true if all integers in an array are factors of a number, and false otherwise.
/// </summary>
/// <param name="factors">- Input array</param>
/// <param name="size">- Size of input array</param>
/// <param name="target">- Number to check that all elements in array are factors of</param>
/// <returns>True if all elements in <c>factors</c> are factors of <c>target</c>, and false otherwise.</returns>
bool checkFactors(int* factors, int size, int target) {
	
	// Iterate over factors
	for (int i = 0; i < size; i++) {

		// Return false if target modulo any of the factors is non-zero
		if (target % factors[i] != 0) return false;
	}

	// Return true if target modulo all the factors is zero
	return true;
}

/// <summary>
/// Main function.
/// </summary>
/// <returns>Code 0 if program runs successfully</returns>
int main() {

	// Initialize inputs
	int* inputs[4];
	inputs[0] = new int[3] { 2,3,4 };
	inputs[1] = new int[4] { 1,2,3,8 };
	inputs[2] = new int[3] { 1,2,50 };
	inputs[3] = new int[2] { 3,6 };
	int targets[4] = { 12,12,100,9 };
	int size[4] = { 3,4,3,2 };

	for (int i = 0; i < 4; i++) {

		// Print input
		cout << "Input: [";
		for (int j = 0; j < size[i]; j++) {
			cout << inputs[i][j] << ", ";
		}
		cout << "\b \b\b \b], " << targets[i] << endl;

		// Print output
		cout << "Output: " << (checkFactors(inputs[i], size[i], targets[i]) ? "true" : "false") << "\n" << endl;
	}
	return 0;
}