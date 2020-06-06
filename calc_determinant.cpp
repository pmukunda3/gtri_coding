// Problem 1: Create Program with the function to calculate the determinant of a 2 x 2 matrix
//
// calc_determinant([
//	 [1, 2],
//	 [3, 4]
//
// calc_determinant([
//	 [5, 3],
//   [3, 1]
//
// calc_determinant([
//	 [1, 1],
//   [1, 1]

#include <cstdio>
using namespace std;

/// <summary>
/// Given a 2x2 matrix, returns its determinant
/// </summary>
/// <param name="matrix">- Input matrix in the for of 2x2 array</param>
/// <returns>Determinant of the input matrix</returns>
int calc_determinant(int matrix[2][2])
{
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

/// <summary>
/// Main function.
/// </summary>
void main()
{
	// Initialize input
	int matrix[2][2] = { 1,2,3,4 };

	// Print first input and output 
	printf("Input: [[%d,%d],[%d,%d]]\nOutput: %d\n\n", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1], calc_determinant(matrix));

	// Change input 
	matrix[0][0] = 5;
	matrix[0][1] = 3;
	matrix[1][0] = 3;
	matrix[1][1] = 1;

	// Print second input and output 
	printf("Input: [[%d,%d],[%d,%d]]\nOutput: %d\n\n", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1], calc_determinant(matrix));

	// Change input 
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	matrix[1][1] = 1;

	// Print third input and output 
	printf("Input: [[%d,%d],[%d,%d]]\nOutput: %d\n\n", matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1], calc_determinant(matrix));
}