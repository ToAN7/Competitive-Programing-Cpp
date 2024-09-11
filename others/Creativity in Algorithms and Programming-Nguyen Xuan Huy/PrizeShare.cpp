/*
Cần chia hết m phần thưởng cho n học sinh sắp theo thứ tự từ giỏi trở xuống
sao cho mỗi bạn không nhận ít phần thưởng hơn bạn xếp sau mình.
1 <= m, n <= 70.
Hãy tính số cách chia.
*/

/*
Step 1: Analyse the content

Let i is the number of presents and j is the number of students

If there is 0 present then there is always have 1 way to share prize for n students

If there is 0 student then there is 0 way to share

If there exists i smaller than j then student from i + 1 goes on will not get any prize so the way to share the prize is (i, i)

But the main part is when i >= j:

If the present only distribute for j-1 then the number of way to distribute is (i, j-1) ways

If the present distribute for the j student then the prize is share equal to other j-1 student. Hence, there are (i-j, j) ways.

Combine two condition then we have:

(i, j) = (i, j-1) + (i-j, j)

If there are having 

Step 2: Using mathematic for describe the solution

Step 3: How to implement data structure in problem

Step 4: Code
*/

#include <iostream>

using namespace std;

int recursive(int i, int j) {
	if (j == 0) return 0;
	else if (i == 0) return 1;
	else if (i < j) return recursive(i, i);
	else return recursive(i, j-1) + recursive(i-j, j);
}

void optimize1() {

}

int main() {
	cout << recursive(7, 4) << endl;
	return 0;
}
