#include "header.h"

void print_pretty() {
	int T; cin >> T;
	cout << setiosflags(ios::showbase) << hex;
	cout << setw(0xf) << internal;
	while (T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		unsigned long long _A = A;
		cout << setw(0) << internal;
		cout << resetiosflags(ios::uppercase);
		cout << setiosflags(ios::showbase) << hex;
		cout << _A << endl;
		cout << setiosflags(ios::showbase) << dec;

		unsigned long long _B = B;
		unsigned long long digit = 0;
		do {
			_B /= 10;
			digit++;
		} while (_B != 0);

		cout << setw(15 - digit - 4) << setfill('_');
		cout << "";
		cout << setw(0);
		cout << setiosflags(ios::showpos);
		cout << setprecision(digit + 2);
		cout << setiosflags(ios::showpoint);
		cout << B << endl;
		cout << resetiosflags(ios::showpoint);
		cout << resetiosflags(ios::showpos);
		cout << setprecision(9);
		cout << setiosflags(ios::uppercase);
		cout << setiosflags(ios::scientific);
		cout << C << endl;
		cout << resetiosflags(ios::uppercase);
		cout << resetiosflags(ios::scientific);
	}
}