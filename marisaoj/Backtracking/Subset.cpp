/*
Liệt kê các tập con độ dài k của tập S=1,2,...,n.

Input - Một dòng gồm hai số nguyên n,k.

Output - Liệt kê các tập con theo thứ tự từ điển.

Điều kiện - 1≤k≤n≤20.

Ví dụ 
Input: 4 2
Output: 12 13 14 23 24 34
*/

#include <iostream>

using namespace std;

int * arr;
int n, k;

void process(int pos = 0, int idx = 0) {
    if (pos == k) {
        for (int i = 0; i < k; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = idx + 1; i <= n; i++) {
        arr[pos] = i;

        process(pos + 1, i);
    }
}

int main() {
    cin >> n >> k;
    arr = new int[k];
    process();

    delete[] arr;
    return 0;
}