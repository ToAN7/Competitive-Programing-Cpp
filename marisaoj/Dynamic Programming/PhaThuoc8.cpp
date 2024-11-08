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
#include <math.h>

using namespace std;

int n = 1;
const int MOD = 100;

int potionMixing(vector<int> p, int n) {
    vector<int> n_p(n);
    int sum = 0;

    for (int l = 1, r = n-1; l <= r;) {
        int sml = 9999, index = 1;
        for (int i = l; i <= r; i++) {
            n_p[i] = min(sml, (p[i]+p[i-1])%MOD);
            if (n_p[i] < sml) {
                sml = n_p[i];
                index = i;
            }
        }
        sum += p[index]*p[index-1];
        cout << endl;
        for (auto x: p) {
            cout << x << '\t';
        }
        cout << endl;
        for (auto x: n_p) {
            cout << x << '\t';
        }
        cout << endl;
        cout << l << "-" << r << " "<<index << ":" << sum << endl;
        if (index <= (l+r)/2) {
            p[l] = n_p[index];
            l++;
            cout << "enter l"<< endl;
        }
        else {
            r--;
            p[index-1] = n_p[index];
            cout << "enter r"<< endl;
        }
    }

    return sum;
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
