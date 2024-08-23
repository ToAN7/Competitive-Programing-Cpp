/*
AP vốn dĩ là một người thích vẽ nên trước khi khai giảng AP đã kịp mua một bộ màu với 43252003274489856000 cây bút màu khác nhau. Tuy nhiên AP lại không phải là người có năng khiếu hội họa nên anh đã làm hỏng gần hết và chỉ còn lại 200000 cây bút. Biết tới niềm yêu thích hội họa của AP, thầy giáo môn đồ thị đã đố AP bài toán như sau :
    Cho đồ thị có hướng gồm n đỉnh và m cạnh, hãy tìm cách tô màu cho m cạnh trên đồ thị để không có chu trình nào gồm toàn các cạnh được tô cùng 1 màu.

    Vì sợ AP làm hỏng thêm bút và không thể hoàn thành câu đố nên thầy giáo muốn số màu bút mà cậu sử dụng là ít nhất.

AP đang bận đi khai giảng nên mọi người hãy giúp cậu nhé !! Mai là AP vào lớp một rồi.

Input

Dòng đầu tiên gồm hai số nguyên n và m là số đỉnh và số cạnh của đồ thị. (1 <= n <= 20000, 0 <= m <= 20000)

dòng tiếp theo, mỗi dòng chứa hai số nguyên u,v thể hiện có cạnh từ đỉnh u tới đỉnh v (1 <= u,v <= 20000, u != v)

Output

Dòng đầu tiên chứa số nguyên k là số màu ít nhất cần dùng để giải bài toán của thầy giáo.

dòng tiếp theo, mỗi dòng chứa một số nguyên thể hiện màu được dùng để tô cạnh thứ i.

Các màu khác nhau được đánh số lần lượt là 1,2,...,k

Sample Input

6 6
1 2
2 3
3 4
4 1
1 5
1 6

Sample Output

2
1
2
2
2
2
2

*/

#include <iostream>

using namespace std;

bool map[20000][20000];

void output() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void findLock() {
}

int main() {
	int n, m;
	cin >> n >> m;
	
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		map[u-1][v-1] = true;
	}
}
