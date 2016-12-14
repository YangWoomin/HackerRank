#include "header.h"

template <>
struct Traits<Color> {
	static string name(int index) {
		if (index >= 0 && index < 3) {
			switch (static_cast<Color>(index)) {
			case Color::red:
				return "red";
			case Color::orange:
				return "orange";
			case Color::green:
				return "green";
			}
		}
		else {
			return "unknown";
		}
	}
};

template <>
struct Traits<Fruit> {
	static string name(int index) {
		if (index >= 0 && index < 3) {
			switch (static_cast<Fruit>(index)) {
			case Fruit::apple:
				return "apple";
			case Fruit::orange:
				return "orange";
			case Fruit::pear:
				return "pear";
			}
		}
		else {
			return "unknown";
		}
	}
};

void class_template_specialization() {
	int t = 0; std::cin >> t;

	for (int i = 0; i != t; ++i) {
		int index1; std::cin >> index1;
		int index2; std::cin >> index2;
		cout << Traits<Color>::name(index1) << " ";
		cout << Traits<Fruit>::name(index2) << "\n";
	}
}