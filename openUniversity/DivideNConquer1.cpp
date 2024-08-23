/*

Cho mảng nguyên a gồm n phần tử, tìm hai chỉ số i và j trong a sao cho a[j] – a[i] là lớn nhất trong số các chỉ số i, j thoả 0 ≤ i ≤ j ≤ n. Chẳng hạn, dãy số {4, 5, 3, 2, 8, 9} thì sự khác nhau lớn nhất là 7.

*/

#include <iostream>

using namespace std;

int a[6] = {4, 5, 3, 2, 8, 9};

void maxDiff(int i, int j, int &min, int &max, int &mx_diff) {
	if (i == j) {
		min = max = a[i];
		mx_diff = 0;
	}
	else {
		int min1, max1, mx_diff1;
		maxDiff(i, (i+j)/2, min1, max1, mx_diff1);
		int min2, max2, mx_diff2;
		maxDiff((i+j)/2 + 1, j, min2, max2, mx_diff2);
		
		min = (min1 < min2)?min1:min2;
		max = (max1 > max2)?max1:max2;
		
		mx_diff = max - min;
		if (mx_diff < mx_diff1) {
			mx_diff = mx_diff1;
		}
		if (mx_diff < mx_diff2) {
			mx_diff = mx_diff2;
		}
	}
}

int main() {
	int min = 0, max = 0, mx_diff = 0;
	maxDiff(0, 5, min, max, mx_diff);
	cout << mx_diff;
	return 0;
}
