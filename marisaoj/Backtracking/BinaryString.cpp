/*
Hãy in ra toàn bộ những xâu nhị phân độ dài n.

Input
- Một dòng gồm một số nguyên số nguyên n.

Output
- In ra những xâu nhị phân có độ dài n. Bạn có thể in ra theo thứ tự bất kì.

Điều kiện
- 1≤n≤10.

Ví dụ
Input:
3
Output:
000
001
010
011
100
101
110
111
*/

#include <iostream>
#include <string>

using namespace std;

string s;

void output() {
    cout << s << endl;
}

void process(int n, int idx = 0) {
    if (idx == n) {
        output();
    }
    else for (int i = 0; i < 2; i++) {
        s.push_back(i + '0');

        process(n, idx+1);

        s.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    process(n);
    return 0;
}