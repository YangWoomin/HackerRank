#include "header.h"

void bit_array() {
	/* // timeout, O(N^2 * NlogN)
	int *a, i, count = 0, modulo = 0x7fffffff;
	int N, S, P, Q;
	cin >> N >> S >> P >> Q;
	a = new int[N];
	a[0] = S & modulo;
	for (i = 1; i < N; i++) {
		a[i] = (a[i - 1] * P + Q) & modulo;
	}
	sort(a, a + N); // O(NlogN)
	i = 0;
	while (i < N) {
		int j = i + 1;
		while (a[j] == a[i]) j++;
		i = j;
		count++;
	}
	cout << count << endl;
	delete a;*/

	// referenced by http://ideone.com/L5Qnkh, maybe O(N)
	int *a, modulo = 0x7fffffff, count = 1;
	a = new int[modulo / 32 + 1];
	memset(a, 0, (modulo / 32 + 1) * sizeof(int));
	int N, S, P, Q;
	cin >> N >> S >> P >> Q;
	S = S & modulo; 
	a[S / 32] |= (1 << (S % 32));
	for (int i = 1; i < N; i++) {
		S = (S * P + Q) & modulo;
		if (!(a[S / 32] & (1 << (S % 32)))) {
			a[S / 32] |= (1 << (S % 32));
			count++;
		}
	}
	cout << count << endl;
	delete a;
}