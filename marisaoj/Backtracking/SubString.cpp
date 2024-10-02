/*
Cho mảng A có n phần tử. Hãy xác định xem có tồn tại một tập con của A mà có tổng bằng k không.

Input
- Dòng đầu tiên gồm hai số nguyên n,k.
- Dòng thứ hai gồm n số nguyên Ai.

Output
- In ra YES nếu tồn tại một tập con của A mà tổng của nó bằng k, ngược lại in ra NO.

Điều kiện
- 1≤n≤20.
- 1≤Ai,k≤10^18.

Ví dụ
Input:
4 7
1234

Output: YES
*/

#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
vector<bool> pass;
bool e = false;
unsigned long long sum = 0;

void process(long long k, int idx = 0) {
    if (sum == k) e = true;
    else for (int i = idx; i < arr.size(); i++) {
        if(pass[i] == false && sum + arr[i] <= k) {
            sum += arr[i];
            pass[i] = true;

            process(k, i + 1);

            pass[i] = false;
            sum -= arr[i];
        }
        if (e) return;
    }
}

int main() {
    long long n, k;
    cin >> n >> k;
    
    arr.resize(n);
    pass.resize(n, false);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    process(k);

    if (e) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}