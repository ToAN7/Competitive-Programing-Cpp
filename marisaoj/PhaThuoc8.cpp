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

int potionMixing(vector<int> A, int n) {
	vector<int> L(n, 0);
	vector<int> newPotion(n,0);
	
	newPotion[0] = A[0];
	for (int i = 1; i < n + 1; i++) {
		L[i] = min(L[i-1]+(A[i]*A[i-1]),L[i-2]+newPotion[i-1]*A[i-1]);
		if(L[i] == L[i-1]+(A[i]*A[i-1])) {
			newPotion[i] = (A[i] + A[i-1])%MOD;
		}
		else {
			newPotion[i] = (newPotion[i-1] + A[i-1])%MOD;
		}
	}

	for (auto x: L) cout << x << endl;

	return L[n-1];
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
