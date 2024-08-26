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

#include <iostream>
#include <vector>

using namespace std;

vector<char> marisa = {'m', 'a', 'r', 'i', 's', 'a'};

int process(string S) {
	long long counter = 0;
	vector<long long> count(6, 0);
	
	int j = 0;
	for (long long i = 0; i < S.length(); i++) {
		if (S[i] == marisa[j]) {
			count[j]++;
		}
		else if (S[i] == marisa[j+1] && j < 6) {
			j++;
			count[j]++;
		}
		if ((S[i] == 'm' || i == S.length() - 1) && j == 5) {
			j = 0;
			int temp = 1;
			for (int k = 0; k < 6; k++) {
				temp*=count[k];
				count[k] = 0;
			}
			counter += temp;
		}
	}

	return counter;
}

int main() {
	// string S = "moarpissa marisa";
	string S = "";

	getline(cin, S);

	vector<vector<int>> L(S.length() + 1, vector<int> (marisa.size()+1));

	cout << process(S) << endl;
	
	return 0;
}
