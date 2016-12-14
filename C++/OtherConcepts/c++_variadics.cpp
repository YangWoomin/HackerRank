// https://www.hackerrank.com/challenges/cpp-variadics
#include "header.h"

template <bool... args> int reversed_binary_value() {
	array<bool, sizeof...(args)> ar{ args... };
	bitset<sizeof...(args)> bs;
	for (int i = 0; i < ar.size(); i++) {
		bs[i] = ar[i];
	}
	return bs.to_ulong();
}

template <int n, bool...digits>
struct CheckValues {
	static void check(int x, int y)
	{
		CheckValues<n - 1, 0, digits...>::check(x, y);
		CheckValues<n - 1, 1, digits...>::check(x, y);
	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
	static void check(int x, int y)
	{
		int z = reversed_binary_value<digits...>();
		std::cout << (z + 64 * y == x);
	}
};

void variadics() {
	int t; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int x, y;
		cin >> x >> y;
		CheckValues<6>::check(x, y);
		cout << "\n";
	}
}