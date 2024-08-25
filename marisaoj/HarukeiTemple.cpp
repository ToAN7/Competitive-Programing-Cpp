/*
Marisa cần phải trèo n bậc thang mới có thể đến được đền Hakurei trên ngọn núi. Nếu cô bước 1, 2 hoặc 3 bước mỗi lần, có bao nhiêu cách để cô có thể đến ngôi đền?

Input - Dòng đầu tiên gồm số nguyên n.
Output - In ra một số nguyên, modulo 10^9+7 do đáp án có thể rất lớn.
Điều kiện -1 ≤ n ≤ 10^5.

Ví dụ
Input: 4
Output: 7
Chú ý:
Có 7 cách để Marisa có lên tới đền: (1,1,2),(1,2,1),(2,1,1),(1,3),(3,1),(2,2),(1,1,1,1)
*/

#include <iostream>
#include <vector>

using namespace std;

int n = -1;

int main() {
	cin >> n;

	// L[i][j] it a matrix of the ways to create value i using only 1 to j
	vector<vector<long long>> L;
	L.resize(n+1, vector<long long> (3,0));

	for (int i = 0; i < 3; i++) {
		L[0][i] = 1;
	}

	for (int s = 0; s < 3; s++) {
		for (int i = 1; i < n + 1; i++) {
			if (i < s + 1) {
				L[i][s] = L[i][s-1];
			}
			else {
				for (int j = 0; j < s + 1; j++) {
					L[i][s] += L[i-j-1][s];
				}
				L[i][s] %= 1000000007;
			}
		}
	}

	cout << L[n][3-1] << endl;

	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "L[" << i << "][" << j << "]"<< L[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
