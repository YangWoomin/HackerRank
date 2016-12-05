#include "header.h"

Matrix& Matrix::operator+(Matrix& other) {
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.at(i).size(); j++) {
			a.at(i).at(j) += other.a.at(i).at(j);
		}
	}
	return *this;
}

void operator_overload() {
	int cases, k;
	cin >> cases;
	for (k = 0; k<cases; k++) {
		Matrix x;
		Matrix y;
		Matrix result;
		int n, m, i, j;
		cin >> n >> m;
		for (i = 0; i<n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j<m; j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (i = 0; i<n; i++) {
			vector<int> b;
			int num;
			for (j = 0; j<m; j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		result = x + y;
		for (i = 0; i<n; i++) {
			for (j = 0; j<m; j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
}