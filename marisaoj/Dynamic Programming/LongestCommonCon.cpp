/*
Cho một mảng A gồm n phần tử, tìm dãy con tăng dài nhất (LIS) của dãy A.
Nói cách khác, tìm k lớn nhất sao cho tồn tại k chỉ số i1<i2<...<ik mà Ai1<Ai2<...<Aik. 

Input
- Dòng đầu tiên gồm số nguyên n.
- Dòng thứ hai gồm n số nguyên Ai.

Output
- In ra độ dài LIS.

Điều kiện
- 1≤n≤1000
- 1≤Ai≤109.

Ví dụ
Input:
5
3 7 2 1 8

Output:
3

Chú ý:
LIS là (3,7,8).
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int n;
vector<int> A;
vector<int> dp;

int main() {
	cin >> n;

	A.resize(n+2);
	A[0] = INT_MIN;
	A[n+1] = INT_MAX;
	for (int i = 1; i < n+1; i++) {
		cin >> A[i];
	}

	dp.resize(n+2,0);
	dp[0] = 1;

	for (int i = 1; i <= n + 1; i++) {
		int jmax = 0; // Make the first position as the longest increament
		for (int j = i - 1; j >= 0; j--) { // Search the largest dp in range A[0] to A[i-1]
			if (A[j] < A[i] && dp[j] > dp[jmax]) { // Save the largest dp that have A[j] lower than A[i]
				jmax = j;
			}
		}
		dp[i] = dp[jmax] + 1;
	}

	for(auto x: dp) cout << x << ' ';
	cout << endl;

	cout << dp[n] << endl;
	
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int n;
vector<int> A;
vector<int> dp;

int main() {
	cin >> n;

	A.resize(n+1);
	A[0] = -INT_MAX;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	dp.resize(n+1,0);
	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (A[j] > A[i]) {
				dp[j] = max(dp[j], dp[i] + 1);
			}
		}
	}

	cout << dp[n]-1 << endl;
	
	return 0;
}
*/
