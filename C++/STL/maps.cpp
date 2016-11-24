// https://www.hackerrank.com/challenges/cpp-maps
#include "header.h"

void maps() {
	multimap<string, int> mm;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int query, marks;
		string name;
		cin >> query;
		if (query == 1) {
			cin >> name >> marks;
			mm.insert(pair<string, int>(name, marks));
		}
		else if (query == 2) {
			cin >> name;
			if (mm.find(name) != mm.end()) {
				mm.erase(name);
			}
		}
		else {
			cin >> name;
			pair<multimap<string, int>::iterator, multimap<string, int>::iterator> p
				= mm.equal_range(name);
			int sum = 0;
			multimap<string, int>::iterator mi;
			for (mi = p.first; mi != p.second; mi++) {
				sum += mi->second;
			}
			cout << sum << endl;
		}
	}
}