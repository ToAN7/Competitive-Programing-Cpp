/*
Marisa có n lọ thuốc sắc màu xếp thành một hàng.
Lọ thuốc i có màu là Ai, nằm trong khoảng từ 0 đến 99.
Marisa muốn trộn hết n lọ thuốc vào với nhau.
Mỗi lượt cô sẽ chọn hai lọ thuốc liên tiếp a và b, trộn chúng lại và tạo thành một lọ thuốc mới có màu (a+b)mod100.
Lượng khói tỏa ra từ quá trình này là a×b.
Hãy xác định lượng khói ít nhất tỏa ra khi Marisa trộn hết n lọ thuốc.

Input
- Dòng đầu tiên gồm số nguyên n.
- Dòng thứ hai gồm n số nguyên Ai.

Output
- In ra lượng khói nhỏ nhất.

Điều kiện
- 1≤n≤500.

Ví dụ
Input:
3
40 60 20
Output: 2400
*/

#include <iostream>
#include <vector>

using namespace std;

int n = 1;
const int MOD = 100;

long long potionMixing(vector<int> A, int n) {
	int smoke = 3000000;

	vector<int> L(n + 1, 0);

	for (int i = 1; i < n + 1; i++) {
		L[i] = (A[i - 1] + L[i-1]) % MOD;
		
		int sm = A[i - 1] * L[i-1];
		smoke = ((sm < smoke) && (sm > 0))?sm:smoke;
	}

	for (auto x: L) cout << x << endl;

	return smoke;
}

int main() {
	cin >> n;
	vector<int> A(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cout << potionMixing(A, n) << endl;

	return 0;
}
