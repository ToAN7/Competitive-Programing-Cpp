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
	for (int i = 2; i < )	
}

int main() {
	int n;
	long long l, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		cout << "Case #" << i+1 << ": " << largestK(l,r);
	}
	return 0;
}
