// Divide and conquer is the two-step process in order to minimize the loop process.
// First is divide, you make sure that the smaller problems are having the same process with the bigger one
// Finally is conquer, you merge smaller problems to give the answer for the bigger one
// One of those examples are the power function. Using the for loop take the time complexity of O(n).
// But using divide and conquer take the time complexity of O(logn(n))

#include <iostream>

using namespace std;

int counter1 = 0, counter2 = 0;

long long power1(int a, int n) {
	long long t = 1;
	for (int i = 0; i < n; i++) {
		counter1++;
		t*=a;
	}
	return t;
}

// This divide and conquer came in fact that a^n = a^k*a^k with k = n/2 and n%2 == 0 or a^n = a^k*a^k*a
// So we only need to calculate for the half of n and store it into an variable for the multiply
// The recursive are being used for divide the k into half each time
// So the power2 loop log2(n) times

long long power2(int a, int n) {
	counter2++;
	if (n == 1) {
		return a;
	}
	long long t = power2(a, n/2);
	if (n % 2 == 0) {
		return t*t;
	}
	else {
		return t*t*a;
	}
}

int main() {
	int a, n;
	cin >> a >> n;
	cout << (power1(a,n) == power2(a,n)) << endl;
	cout << "This is a normal power function loop: " << counter1 << endl;
	cout << "This is a divide and conquer power function loop: " << counter2 << endl;
	return 0;
}
