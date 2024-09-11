/*
Tìm tất cả các số tự nhiên hai chữ số mà khi đảo trật tự của hai chữ số đó sẽ thu được một số nguyên tố cùng nhau với số đã cho.
*/

/*
Step 1: Understanding the content
Assuming x = ab (where a and b is digit from 0 to 9)
So x' is the parallel from x is ba

Relative prime can be defined by
using greatest common divisor of a and b equal to 1.

Some example is
(13,31) = 1 is a coprime
(20, 2) = 2 is not a coprime

Step 2: Using mathematic language to describe the problem
x = ab (a>0, b>0)
x' = 10*(ab mod 10) + ab div 10

gcd(x, x') = 1
for gcd is the euclid algorithms. It state that:
	Step 1: r are the number of continuous subtraction of a with b (if a > b)
	Step 2: replace a with b and b with r
	Step 3: repeat from step 1 until b = 0 then a is the gcd that we looking for

Step 3: Identify data structure for the problem
If (x, x') = 1 then save x in array for later use i.e. (31, 13) and (13, 31) are the same comparision.
*/

#include <iostream>
#include <chrono>

using namespace std;

int arr[90];

void init() {
	for (int i = 0; i < 90; i++) {
		if (arr[i] != 0) {
			arr[i] = 0;
		}
	}
	cout << endl;
}

inline int revertNum(int x) {
	return 10*(x%10) + x/10;
}

int gcd(int a, int b) {
	int r = 0;
	while (b != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

void output() {
	for (int i = 0; i < 90; i++) {
		if (arr[i] != 0) {
			cout << arr[i] << ' ';
		}
	}
	cout << endl;
}

void find1() {
	init();
	
	auto start = chrono::high_resolution_clock::now();

	int d = 0;

	for (int i = 10; i < 100; i++) {
		if (gcd(i, revertNum(i)) == 1) arr[d++] = i;
	}

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution time: " << duration.count() << " microseconds" << endl;

	output();
}

/*
But there is even better way to execute the program:

Noticing that there is a loop in some case i.e. (31, 13) and (25, 52)

So we can find once and input both of x and x' into the array

Let's reanalyse the x = ab. We can find the missing number later by using one rule a > b >= 0 and

If b = 0, we have x = 10a and x' = a and gcd(10a, a) = a = 1 only a = 1. So 10

*/

void find2() {
	init();
	
	auto start = chrono::high_resolution_clock::now();

	int d = 0;
	arr[d++] = 10;
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < a + 1; b++) {
			if (gcd(a*10+b, b*10+a) == 1) {
				arr[d++] = a*10+b;
				arr[d++] = b*10+a;
			}
		}
	}

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "Execution time: " << duration.count() << " microseconds" << endl;

	output();
}

int main() {
	find1();
	find2();
	return 0;
}
