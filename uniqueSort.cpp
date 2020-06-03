//  Problem 4: Given an array of numbers, write a function that returns an array that :
//
//	·  Has all duplicate elements removed.
//
//	·  Is sorted from least value to greatest value.
//
//	Show results for these inputs
//
//	uniqueSort([1, 2, 4, 3]) ➞[1, 2, 3, 4]
//
//	uniqueSort([1, 4, 4, 4, 4, 4, 3, 2, 1, 2]) ➞[1, 2, 3, 4]
//
//	uniqueSort([6, 7, 3, 2, 1]) ➞[1, 2, 3, 6, 7]

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;

/// <summary>
/// Modified binary search. Takes a vector of ints as input. 
/// Returns position of target if found, if not found, returns position where target should be inserted.
/// </summary>
/// <param name="vec">- The input vector of ints</param>
/// <param name="l">- First index to search</param>
/// <param name="r">- Last index to search</param>
/// <param name="target">- Value to search for</param>
/// <returns>Position of target if found, if not found, returns position where target should be inserted.</returns>
int binarySearch(vector<int> vec, int l, int r, int target)
{
    if (r > l) {
        int mid = l + (r - l) / 2;

        if (vec[mid] == target)
            return mid;

		if (vec[mid] > target)
            return binarySearch(vec, l, mid - 1, target);

        return binarySearch(vec, mid + 1, r, target);
    }
	return target <= vec[l] ? l : l + 1;
}

/// <summary>
/// Given an array of numbers, returns the array sorted with duplicates removed.
/// </summary>
/// <param name="input">- Input array</param>
/// <param name="inSize">- Size of input array</param>
/// <returns>Tuple where first element is output array and second element is size of output array</returns>
tuple<int*,int> uniqueSort(int* input, int inSize)
{
	int insertPos = 0, outSize;

	// Initialize set numSet to hold unique values
	set<int> numSet = set<int>();

	// Initialize temporary vector temp to hold output
	vector<int> temp = vector<int>();

	// Iterate over elements of input array
	for (int i = 0; i < inSize; i++) {
		
		// Insert first element into numSet and temp 
		if (i == 0) {
			numSet.insert(input[i]);
			temp.push_back(input[i]);
			continue;
		}

		// If numSet contains element, continue
		if (numSet.count(input[i]) > 0) continue;

		// Insert element into numSet
		numSet.insert(input[i]);

		// Using binary search, find position at which to insert element into temp (Binary search Insertion sort)
		outSize = (int)temp.size();
		insertPos = binarySearch(temp, 0, outSize-1, input[i]);

		// Insert element into temp at insertPos
		if(insertPos == outSize) 
			temp.push_back(input[i]);
		else 
			temp.insert(temp.begin() + insertPos, input[i]);
	}

	// Convert output from vector to array
	outSize = (int)temp.size();
	int* output = new int[outSize];
	for (int i = 0; i < outSize; i++) {
		output[i] = temp[i];
	}

	// Return output array and output array size
	return make_tuple(output,outSize);
}

/// <summary>
/// Main function.
/// </summary>
/// <returns>Code 0 if program runs successfully</returns>
int main()
{
	// Initialize inputs
	int* inputs[3];
	inputs[0] = new int[4] { 1, 2, 4, 3 };
	inputs[1] = new int[10] { 1, 4, 4, 4, 4, 4, 3, 2, 1, 2 };
	inputs[2] = new int[5] { 6, 7, 3, 2, 1 };
	int size[3] = { 4,10,5 };
	
	// Declare variable to store output
	tuple<int*, int> output;

	for (int i = 0; i < 3; i++) {

		// Print input array
		cout << "Input: [";
		for (int j = 0; j < size[i]; j++) {
			cout << inputs[i][j] << ", ";
		}
		cout << "\b \b\b \b]" << endl;

		// Apply function
		output = uniqueSort(inputs[i], size[i]);

		// Extract output array and output array size from tuple 
		int* outArray = get<0>(output);
		int outSize = get<1>(output);

		// Print output array
		cout << "Output: [";
		for (int i = 0; i < outSize; i++ ) {
			cout << outArray[i] << ", ";
		}
		cout << "\b \b\b \b]\n" << endl;
	}

	// Exit with code 0
	return 0;
}