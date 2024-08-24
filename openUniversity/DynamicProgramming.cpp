// nth Fibonanci number


#include <iostream>
#include <vector>

using namespace std;

int counter1 = 0, counter2 = 0, counter3 = 0;

int normalF(int n) {
	counter1++;
	if (n < 2) return 1;
	else return normalF(n-1)+normalF(n-2);
}


// Dynamic Programming are the way to solve the problem by saving each reasult value.

int dpF(int n) {
	vector<int> F(n+1);
	F[0] = F[1] = 1;

	for (int i = 2; i <= n; i++) {
		counter2++;
		F[i] = F[i-1] + F[i-2];
	}

	return F[n];
}

int main() {
	int n;
	cin >> n;

	cout << "The normal Fibonanci loop for " << normalF(n) << " is " << counter1 << endl;
	cout << "The dynamic programming Fibonanci loop for " << dpF(n) << " is " << counter2 << endl;
}
