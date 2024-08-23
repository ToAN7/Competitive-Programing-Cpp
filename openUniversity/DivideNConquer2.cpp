/*
Cho hình vuông có cạnh n = 2^k (2 ≤ k ≤ 10) và bị khuyết phần tư góc trên phải. Sử dụng các viên gạch hình thước thợ tạo bởi 3 ô vuông đơn vị, hãy lát gạch cho nền nhà dạng hình vuông trên.
*/

#include <iostream>
#include <vector>

using namespace std;


int k = 3;
int n = 1 << k; // 2^k

vector<vector<int>> map(n, vector<int>(n));
int steps = 0;

// n is area of the map
// x, y is the cordinate of the top left of the brick
// d is the location of 1/4 part they missing. 1 is the top left, 2 is top right, 3 is bottom right, 4 is bottom left.

/*
Brick look like this

d = 1:
0 1
1 1
d = 2:
1 0
1 1
d = 3:
1 1
1 0
d = 4:
1 1
0 1

*/

void flooring(int x, int y, int d) {
	steps++;
	if (d != 1) {
		map[x][y] = steps;
	}
	if (d != 2) {
		map[x][y+1] = steps;
	}
	if (d != 3) {
		map[x+1][y+1] = steps;
	}
	if (d != 4) {
		map[x+1][y] = steps;
	}
}

void process(int n, int x, int y, int d) {
	if (n == 2) {
		flooring(x, y, d);
	}
	else {
		int p = n/2;
		switch (d) {
			case 1:
				process(p, x, y + p, 4);
				process(p, x + p, y + p, 1);
				process(p, x + p/2, y + p/2, 1);
				process(p, x + p, y, 2);
			break;
			case 2:
				process(p, x, y, 3);
				process(p, x + p, y, 2);
				process(p, x + p/2, y + p/2, 2);
				process(p, x + p, y + p, 1);
			break;
			case 3:
				process(p, x, y + p, 4);
				process(p, x, y, 3);
				process(p, x + p/2, y + p/2, 3);
				process(p, x + p, y, 2);
			break;
			case 4:
				process(p, x, y, 3);
				process(p, x + p/2, y + p/2, 4);
				process(p, x, y + p, 4);
				process(p, x + p, y + p, 1);
			break;
		}
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << '\t';
		}
		cout << endl;
	}
}

int main() {
	process(n, 0, 0, 4);
	output();
	return 0;
}
