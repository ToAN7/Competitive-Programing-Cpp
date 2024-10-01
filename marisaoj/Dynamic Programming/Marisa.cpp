/*
Cho xâu S, hãy đếm số lượng xâu con không nhất thiết liên tiếp của S tạo thành xâu marisa.

Input
- Một dòng gồm xâu S.

Output
- In ra một số nguyên là số lượng xâu con không nhất thiết liên tiếp của S là xâu marisa, modulo 10^9+7.

Giới hạn - 1≤|S|≤105.

Ví dụ
Input: marisa
Output: 1
*/

//#include <bits/stdc++.h>


// BAI CUA THAY DUONG HUU THANH
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const string target = "marisa";
const int len = (int) target.length();

long countSubsequences(const string &S) {
	vector<long long> dp(len + 1, 0);
	dp[0] = 1;
	int counter = 0;

	for (char c : S) {
		for (int i = len; i >= 1; --i) {
			if (c == target[i - 1]) {
				dp[i] = (dp[i] + dp[i - 1]) % MOD;
			}
		}
	}

	return dp[len];
}

int main() {
	string S;

	getline(cin,S);

	    cout << countSubsequences(S) << endl;
	return 0;
}
