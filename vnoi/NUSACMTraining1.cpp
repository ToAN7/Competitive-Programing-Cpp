/*
Lũy thừa
Cho l,r sao cho 2 <= l <= r <= 10^12 Tìm số nguyên dương lớn nhất sao cho tồn tại số nguyên dương x để l <= x^k <= r

Input
Dòng đầu tiên là số lượng test.

Mỗi dòng tiếp theo chứa hai số nguyên l,r biểu thị một test.

Output
Đối với mỗi test in ra "Case #" + số hiệu test + ": " + số k lớn nhất tìm được.

Sample Input
4
5 20
10 12
2 100
1000000000000 1000000000000

Sample Output
Case #1: 4
Case #2: 1
Case #3: 6
Case #4: 12
*/

#include <iostream>

using namespace std;

long long largestK(long long l, long long r) {
	int x = 2;
	int best = 1;

	long long j = 1;

	// 10^12 < 2^40 so the loop max is 40
	for (int i = 1; i < 41; i++) {
		j = j * x;
		if (j >= l && j <= r) {
			if (i >= best) {
				best = i;
			}
		}
		else {
			// This if prevent case with assumption that greater x always have smaller k and if x > r will go into this else case 2e9 times
			// Ex 5 and 20 will give you 2^4
			// But when x is 3, then i will be 2
			// So it is better to break out of the loop
			if (i < best || x > r) {
				break;
			}
			if (j > r) {
				x++;
				i = 0;
				j = 1;
			}
		}

	}

	return best;
}

int main() {
	int n;
	long long l, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		cout << "Case #" << i+1 << ": " << largestK(l,r) << endl;
	}
	return 0;
}
