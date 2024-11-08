/*
Mỗi ô của một bàn cờ 8×8 ghi một số nguyên dương không quá 32000. Hãy xếp 8 quân hậu lên bàn cờ sao cho không quân hậu nào ăn quân hậu nào và tổng số các ô các quân hậu đang đứng là lớn nhất. 
Dữ liệu đầu vào trong tập tin queens.inp là bàn cờ có trọng số kích thước 8×8.
Dữ liệu đầu ra ghi trong tập tin queens.out như sau:
- Dòng đầu là dãy 8 số, trong đó số thứ i là vị trí cột đặt quân hậu trên dòng i.
- Dòng thứ hai là tổng trị 8 quân hậu đứng.
queens.inp 
1 2 4 9 3 2 1 4 
6 9 5 4 2 3 1 4 
3 6 2 3 4 1 8 3 
2 3 7 3 2 1 4 2 
1 2 3 2 3 9 2 1 
2 1 3 4 2 4 2 8 
2 1 3 2 8 4 2 1 
8 2 3 4 2 3 1 2 
queens.out
3 1 6 2 5 7 4 0
66
*/

#include <iostream>
#include <vector>

using namespace std;

int arr[8][8] = {
	{1, 2, 4, 9, 3, 2, 1, 4},
	{6, 9, 5, 4, 2, 3, 1, 4},
	{3, 6, 2, 3, 4, 1, 8, 3},
	{2, 3, 7, 3, 2, 1, 4, 2},
	{1, 2, 3, 2, 3, 9, 2, 1},
	{2, 1, 3, 4, 2, 4, 2, 8},
	{2, 1, 3, 2, 8, 4, 2, 1},
	{8, 2, 3, 4, 2, 3, 1, 2}
};

// Create vector queen have type int contain column values
vector<int> queen(8,0);

vector<int> best(8,0);

int sum = 0;

int bestSum = 0;

int counter = 0;

// Row i, column j
bool canPutQueen(int i, int j) {
	// Check each queen from 0 to i valid
	for (int k = 0; k < i; k++) {
		// Check if column j match each queen
		// If there are a queen on primary diagonal has location (a,b)
		// then b - a equal to j - i
		// But when exist a queen on the other diagonal
		// then b + a equal to j + i
		// So b - j = a - i (primary case) = i - a (other case)
		// or in my case i - a = abs(b - j) because i always greater than a
		if (queen[k] == j || i - k == abs(j - queen[k])) {
			return false;
		}
	}
	return true;
}

void update() {
	if (sum > bestSum) {
		bestSum = sum;
		best = queen;
	}
}

void outputWeight() {
	for (auto x: best) {
		cout << x << ' ';
	}
	cout << endl << bestSum << endl;
}

int chooseBest(int row) {
	int max = 0;
	int colMax = -1;
	for (int i = 0; i < 8; i++) {
		if (arr[row][i] > max && canPutQueen(row, i) == true) {
			max = arr[row][i];
			colMax = i;
		}
	}
	return colMax;
}

// in each column idx find a way to put queen in column j
// so that each queen are in unique row
void process(int idx = 0) {
	counter++;
	int tmp = chooseBest(idx);
	if (tmp == -1) return;
	queen[idx] = tmp;
	sum += arr[idx][tmp];

	if (idx == 7) {
		update();
	}
	else {
		process(idx + 1);
	}

	sum -= arr[idx][tmp];
}

int main() {
	process();
	outputWeight();
	cout << "recursive times: " << counter << endl;
	cout << "NeggaTon is here!!!\n";
}
