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
const long long  MOD = 1e9 + 7;

int main() {
	cin >> n;

	vector<long long> L(n+1, 0);

	L[0] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= 3; j++)
			if (i >= j)
				L[i] = (L[i] + L[i-j]) % MOD;

	cout << L[n] << endl;

	return 0;
}
