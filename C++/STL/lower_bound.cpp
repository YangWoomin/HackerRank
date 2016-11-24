// https://www.hackerrank.com/challenges/cpp-lower-bound
#include "header.h"

void lower_bound() {
	unsigned long long *number;
	int N;
	cin >> N;
	number = new unsigned long long[N + 1];
	for (int i = 1; i <= N; i++) {
		unsigned long long temp;
		cin >> temp;
		number[i] = temp;
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int temp;
		cin >> temp;
		int start = 1, end = N, mid = end % 2 == 0 ? (start + end) / 2 : (start + end) / 2 + 1;
		bool flag = false;
		while (start <= end) {
			if (temp == number[mid]) {
				while (mid > 0 && number[mid] == number[mid - 1]) {
					mid--;
				}
				cout << "Yes " << mid << endl;
				flag = true;
				break;
			}
			else if (temp > number[mid]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
			mid = (start + end) % 2 == 0 ? (start + end) / 2 : (start + end) / 2 + 1;
		}
		if (!flag) {
			cout << "No " << start << endl;
		}
	}
}