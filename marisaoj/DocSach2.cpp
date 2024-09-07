/*
Marisa có n kệ sách, kệ thứ i có Ai cuốn sách. Cô muốn lấy ra k quyển để đọc.
Mỗi kệ sách, cô sẽ không lấy quá 1 quyển.
Hỏi có bao nhiêu cách để lấy ra k cuốn sách?

Input
- Dòng đầu tiên gồm 2 số nguyên n,k.
- Dòng thứ hai gồm n số nguyên Ai.

Output
- In ra một số nguyên, số lượng modulo 109+7.

Điều kiện
- 1≤k≤n≤1000.
- 1≤Ai≤109.

Ví dụ
Input:

3 2
1 2 1

Output: 5

Chú ý:
Có 5 cách:
- (11,21)
- (11,22)
- (11,31)
- (21,31)
- (22,31)
với xy là cuốn sách thứ y của kệ thứ x.
*/

#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int n, k;
vector<long long> A;
vector<long long> dp; // The number of way to read from deak 1 to n

int main() {
	cin >> n >> k;
	A.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	dp.resize(n+1);
	dp[0] = 1; // There 1 way to choose from 0 deck
	
	for(int i = 0; i < n; i++) { //  A[i]*dp[j-1] is a number of way to read
		for (int j = k; j > 0; j--) {
			dp[j] = (dp[j] + dp[j-1]*A[i]) % MOD;
		}
	}


	
	cout << dp[k] << endl;
	return 0;
}
