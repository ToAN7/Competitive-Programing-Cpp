/*
Hãy in ra những xâu độ dài n chỉ gồm ba loại kí tự A, B, và C và
không có hai kí tự cạnh nhau nào được giống nhau.
Ví dụ xâu ABBC là không thỏa mãn do có hai kí tự B đứng cạnh nhau.

Input
- Một dòng gồm một số nguyên n.

Output
- In ra toàn bộ những xâu thỏa mãn, có thể in ra theo thứ tự bất kì.

Điều kiện
- 1≤n≤10.

Ví dụ
Input: 2
Output:
AB
BA
BC
CB
AC
CA
 */

#include <iostream>
#include <string>

using namespace std;

string s;
void output() {
    cout << s << endl;
}

bool check(int idx, char a) {
    if (a == s[idx-1]) return true;
    return false;
}

void process(int n, int idx = 0) {
    if (idx == n) {
        output();
    }
    else for (int i = 0; i < 3; i++) {
        if (idx > 0 && check(idx, 'A' + i)) continue;
        s.push_back('A' + i);

        process(n, idx + 1);

        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    process(n);
    return 0;
}