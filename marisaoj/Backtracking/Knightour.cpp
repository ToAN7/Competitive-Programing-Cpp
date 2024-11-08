/*
Cho bàn cỡ vua kích cỡ n×m. 
Bạn được đặt một quân mã vào vị trí bất kì trên bàn cờ trống.
Hãy tìm đường đi qua tất cả các ô trên bàn cờ, mỗi ô đúng một lần.

Input

    Một dòng gồm hai số nguyên n,m.

Output

In ra một ma trận n dòng, m cột là thứ tự thăm các ô của con mã, bắt đầu từ 1.
Có thể in ra cách đi bất kì.

Điều kiện: 1≤n,m≤7.

Ví dụ:

Input:

5 5

Output:

  1   6  15  10  21 
 14   9  20   5  16
 19   2   7  22  11
  8  13  24  17   4
 25  18   3  12  23
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> c;
int n, m;
bool isAccess = false;
int moveX[4] = {-2, -1, 1, 2};
int moveY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void output() {
    for (auto x: board) {
        for (auto y: x) {
            cout << y << '\t';
        }
        cout << endl;
    }
}

bool check(int x, int y) {
    if (x < 0 || x >= n) return false;
    if (y < 0 || y >= m) return false;
    return true;
}

void process(int x = 0, int y = 0, int idx = 1) {
    if (idx == n*m + 1) {
        if (!isAccess) {
            isAccess = true;
            output();
        }
    }
    else {
        if (!isAccess && c[x][y] == false) {
            c[x][y] = true;
            board[x][y] = idx;

            for (int i = 0; i < 8; i++) {
                if (check(x + moveX[i/2], y + moveY[i])) {
                    process(x + moveX[i/2], y + moveY[i], idx + 1);
                }
            }
            
            board[x][y] = 0;
            c[x][y] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    // Ma tran n dong, m cot
    board.resize(n, vector<int>(m, 0));
    c.resize(n, vector<bool>(m, 0));

    process();
    return 0;
}
