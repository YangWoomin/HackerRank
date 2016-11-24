// https://www.hackerrank.com/challenges/deque-stl
#include "header.h"

int findMax(deque<int> dq, int k) {
	int max = 0, index = 0;
	for (int i = 0; i < k; i++) {
		if (dq.at(i) > max) {
			index = i;
			max = dq.at(i);
		}
	}
	cout << max << " ";
	return index;
}

void printKMax(int arr[], int n, int k) {
	//Write your code here.
	deque<int> dq;
	for (int i = 0; i < k; i++) {
		dq.push_back(arr[i]);
	}
	int p = k;
	while (p <= n) {
		int index = findMax(dq, k);
		dq.push_back(arr[p++]);
		dq.pop_front();
		index--;
		while (index >= 0) {
			if (p <= n) {
				if (dq.at(index) > arr[p - 1]) {
					cout << dq.at(index) << " ";
				}
				else {
					cout << arr[p - 1] << " ";
					index = k - 1;
				}
				dq.push_back(arr[p++]);
				dq.pop_front();
				index--;
			}
			else {
				break;
			}
		}
	}
	cout << endl;
}

void deque_stl() {
	int t;
	cin >> t;
	while (t>0) {
		int n, k;
		cin >> n >> k;
		int i;
		int *arr = new int[n];
		for (i = 0; i<n; i++)
			cin >> arr[i];
		printKMax(arr, n, k);
		t--;
	}
}