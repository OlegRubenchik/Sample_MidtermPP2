#pragma once
#include <iostream>
using namespace std;
/*Question 1:
(a) Write a void function readArray that takes a one-dimensional array A and an integer number n and
promps the user to enter n values and stores them in the array.
*/
void readArray(int A[],int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter " << i << " value: ";
		cin >> A[i];
	}
}
/*(b) Write a void function calculate that takes an array A and an integer number n, and returns through
2 reference formal parameters the average of the n values in the array, along with the biggest value. If
n is 0 the two reference parameters should be set to 0.
*/
void calculate(int A[],int n,int &average,int &max) {
	if (n == 0) {
		average = 0;
		max = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			average += A[i];
			if (max < A[i]) max = A[i];
		}
		average /= n;
	}
}
/*(c) Write a main program and declare an array with 100 integers called numbers. Hence, ask the user for
the value of n and by calling the functions you wrote above read n values in the array. Then, display
their average and the biggest value.*/
void MIDSAMP_EX1() {
	const int SIZE = 100;
	int numbers[SIZE],n;
	int average = 0,max = 0;

	cout << "How much values you will enter: ";
	cin >> n;
	readArray(numbers, n);
	calculate(numbers, n, average, max);
	cout << "Average: " << average << '\n' << "Max: " << max;
}

/*Question 2:
(a) A palindrome is a number or word that is the same when read forward or backward. For example, 12321
and savvas are palindromes. Write a function “palindrome” to determine whether or not (true or
false) an integer N is a palindrome. Note that all the one-digit numbers are palindromes. Assume that
N is a positive integer.*/
bool palindrome(int n) {

}