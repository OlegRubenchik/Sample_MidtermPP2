#pragma once
#include <iostream>
#include <string>
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
	int rev = 0,num = n;
	while (num > 0) {
		rev = 10 * rev + num % 10;
		num /= 10;
	}
	return rev == n;
}
/*(b) Write the main program that will prompt the user to enter an integer number and display a message
whether or not is a palindrome.*/
void MIDSAMP_EX2() {
	int num;
	cout << "Enter a number: ";
	cin >> num;
	if (palindrome(num)) cout << "\nIt's a palindrome!";
	else cout << "It's not a palindrome.";

}
/*Question 3:
(a) Define an enumerated type ‘days’ to represent the days of the week (Mon, Tue, Wed, Thu, Fri, Sat,
Sun).
*/
enum days {Mon, Tue, Wed, Thu, Fri, Sat, Sun};
/*(b) Write a void function “initialize” that will take an array of days (20 positions) and will initialize
all its positions to the value Sun.
void initialize(days d[20])*/
void initialize(days d[20]) {
	for (int i = 0; i < 20; i++) {
		d[i] = Sun;
	}
}
/*(c) Write a function “weekend” that will take an array of days (20 positions) and will return the number
of times that Sat and Sun appear in the array.*/
int weekend(days d[20]) {
	int count = 0;
	for (int i = 0; i < 20; i++) {
		if (d[i] == Sun or d[i] == Sun) {
			count++;
		}
	}
	return count;
}
/*(d) Write a function “tomorrow” that will take a variable d of type days and will return the day after d.
(HINT: (days)(Tue+1) = Wed )
days tomorrow(days d)*/
days tomorrow(days d) {
	return days((d + 1) % 7);
}
/*Question 4:
(a) Write a void function reverse(char *str1, char *str2) that takes a null-terminated string
str1 and stores its characters in reverses in str2. For example if str1 is "Hello", str2 must become
"olleH". You may use function strlen(), defined in <cstring>, but no other function of the
cstring library.*/
void reverse(char* str1, char* str2) {
	int size;
	for (size = 0; str1[size] != '\0'; size++);
	for (int i = 0; i < size; i++) {
		str2[i] = str1[size - 1 - i];
	}
	str2[size] = '\0';
}
/*(b) Write a second void function mirrorPrint(char *str), that uses reverse() to display its string
argument in forward and reverse order. So, if str is "Hello", the output will be "HelloolleH".*/
void mirror(char* str) {
	char revstr[256];
	int size;
	for (size = 0; str[size] != '\0'; size++);
	reverse(str, revstr);
	for (int i = 0; i < size; i++) {
		str[size + i] = revstr[i];
	}
	str[size*2] = '\0';
}
void mirrorPrint(char* str)
{
	char str2[256];
	reverse(str, str2);
	cout << str << str2 << endl;
}
/*Use the function mirrorPrint() to implement a void function display(char *str) to print
lines of its string argument in forward and reverse order as shown below (on every line the last
character is missing, and notice the indentation):
*/
void display(char str[]) {
	int size,count = 0;
	for (size = 0; str[size] != '\0'; size++);
	while (size >= 1) {
		for (int i = 0; i < count; i++) cout << ' ';
		mirror(str);
		cout << str << '\n';
		str[size - 1] = '\0';
		size--;
		count++;
	}
}
/*Question 5:
(a) Show the output of the following program fragment:*/

void MIDSAMP_EX5_A() {
	char s1[] = "Welcome to C++";
	char* s2, * s3;
	s2 = &s1[9];
	s3 = new char[4];
	for (int i = 0; i < 4; i++)
		s3[i] = s2[i + 2];
	s1[5] = '\0';
	cout << s1 << endl << s2 << endl << s3 << endl;
}
/*(b) Show the output of the following program:*/
void one(int A[], int n)
{
	for (int i = 0; i < n; i++)
		A[i] = n - i;
}
int MIDSAMP_EX5_B()
{
	int M[4][5], i;
	for (i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			M[i][j] = 0;
	for (i = 0; i < 4; i++)
		one(M[i], 5 - i);
	for (i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*Question 6:
(a) Declare a structure (class) called “student” that has the following public data members:
name (string)
year (int)
CPA (float)
*/
class student {
public:
	string name;
	int year;
	float CPA;
};

/*(b) Hence write the following functions:
(i) void readStudents(student s[], int n) that prompts the user to enter the
information of n students.*/
void readStudents(student s[], int n) {
	for (int i = 0; i < n; i++) {
	
		cout << "STUDENT " << i << '\n';
		cout << "NAME: ";
		getline(cin, s[i].name);
		cout << "YEAR: ";
		cin >> s[i].year;
		cout << "CPA: ";
		cin >> s[i].CPA;
		cin.ignore();
	}
}
/*(ii) float averageCPA(student s[], int n) that calculates and returns the average CPA
of n students.
*/
float averageCPA(student s[], int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg += s[i].CPA;
	}
	return avg / n;
}
/*(iii) The main() program that has an array of 100 students and uses the above functions to
read the information of 100 students and display their average CPA.*/
void MIDSAMP_EX6() {
	const int n = 2;
	float average;
	student studs[n];
	readStudents(studs, n);
	average = averageCPA(studs, n);
	cout << "Average CPA: " << average;
}