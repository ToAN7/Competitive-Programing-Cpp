/*
Có N người sắp hàng mua vé dự buổi hoà nhạc. Ta đánh số họ từ 1 đến N theo thứ tự đứng trong hàng. Mỗi người cần mua một vé, song người bán vé được phép bán cho mỗi người tối đa hai vé. Vì thế, một số người có thể rời hàng và nhờ người đứng trước mình mua hộ vé. Biết ti là thời gian cần thiết để người i mua xong vé cho mình. Nếu người i+1 rời khỏi hàng và nhờ người i mua hộ vé thì thời gian để người thứ i mua được vé cho cả hai người là ri.

Yêu cầu: Xác định xem những người nào cần rời khỏi hàng và nhờ người đứng trước mua hộ vé để tổng thời gian phục vụ bán vé là nhỏ nhất.
Dữ liệu

    Dòng đầu tiên chứa số N (1 ≤ N ≤ 60000).
    Dòng thứ 2 ghi N số nguyên dương t1, t2, ..., tN. (1 ≤ ti ≤ 30000)
    Dòng thứ ba ghi N-1 số nguyên dương r1, r2, ..., rN-1. (1 ≤ ri ≤ 30000) 

Kết qủa

In ra tổng thời gian phục vụ nhỏ nhất. 

Dữ liệu:
5
2 5 7 8 4
4 9 10 10 

Kết qủa
18

Dữ liệu:
4
5 7 8 4
50 50 50 

Kết qủa
24
*/

#include <iostream>
#include <vector>

using namespace std;

int n = 1;

void output(vector<int> L) {
	cout << L[L.size()-2] << endl;
}

void process(vector<int> &t, vector<int> &r, vector<int> &L) {
	for (int i = 2; i < n + 2; i++) {
		L[i] = min((L[i-2] + r[i-2]),(L[i-1] + t[i-1]));
	}
}

int main() {
	cin >> n;

	vector<int> t(n);
	vector<int> r(n-1);
	
	// Li is an array of sum of smallest time to buy ticket
	vector<int> L(n + 2,0);

	for (int i = 0; i < n; i++)
		cin >> t[i];

	for (int i = 0; i < n - 1; i++)
		cin >> r[i];
	
	L[1] = t[0];
	process(t, r, L);
	output(L);
}
