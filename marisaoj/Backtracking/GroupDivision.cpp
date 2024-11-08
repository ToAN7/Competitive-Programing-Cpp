/*
Cho dãy A gồm n số nguyên. Hãy tìm cách chia dãy thành k nhóm
mà các nhóm có tổng bằng nhau. Mỗi nhóm phải có ít nhất một phần tử.

Input

    Dòng đầu tiên gồm hai số nguyên n,k.
    Dòng thứ hai gồm n số nguyên Ai.

Output

    In ra n số nguyên, số nguyên thứ i là nhóm của phần tử thứ i. 
    Nếu có nhiều đáp án, in ra đáp án bất kì.
    Nếu không tồn tại đáp án, in ra ze.

Điều kiện

    2≤k<n≤10.
    1≤Ai≤100.

Ví dụ

Input:

5 3
1 4 6 9 10

Output:

1 3 3 1 2

Giải thích:

    Nhóm đầu tiên gồm hai phần tử A2+A3=4+6=10.
    Nhóm thứ hai gồm một phần tử A5=10.
    Nhóm thứ ba gồm hai phần tử A1+A4=1+9=10.

Đáp án 1 2 2 1 3 hay 3 1 1 3 2 cũng là một đáp án được chấp nhận. 
*/
#include <vector>
#include <iostream>

using namespace std;

vector<int> a;
vector<int> b;
vector<bool> c;
int sum = 0;

void output() {
    for (auto x: b) cout << x << ' ';
    cout << endl;
}

bool isValid() {
    for (auto x: b) {
        if (x == 0) return false;
    }
    return true;
}

void process(int n, int k, int s = 0) {
    for (int i = 0; k&&i < n; i++) {
        if (a[i] + s <= sum && c[i] == 0) {
            c[i] = true;
            s += a[i];
            b[i] = k;

            // Search until find a group
            if (sum == s) {
                k--;
                // Go to next group
                process(n, k, 0);
            }
            else process(n, k, s);

            if (isValid()) return;
            
            b[i] = 0;
            s -= a[i];
            c[i] = false;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    a.resize(n, 0);
    b.resize(n, 0);
    c.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sum = sum / k;

    process(n, k);
    if (isValid()) output();
    else cout << "ze" << endl;

    return 0;
}
