// https://www.hackerrank.com/challenges/magic-spells
#include "header.h"

class Spell {
private:
	string scrollName;
public:
	Spell() : scrollName("") { }
	Spell(string name) : scrollName(name) { }
	virtual ~Spell() { }
	string revealScrollName() {
		return scrollName;
	}
};

class Fireball : public Spell {
private: int power;
public:
	Fireball(int power) : power(power) { }
	void revealFirepower() {
		cout << "Fireball: " << power << endl;
	}
};

class Frostbite : public Spell {
private: int power;
public:
	Frostbite(int power) : power(power) { }
	void revealFrostpower() {
		cout << "Frostbite: " << power << endl;
	}
};

class Thunderstorm : public Spell {
private: int power;
public:
	Thunderstorm(int power) : power(power) { }
	void revealThunderpower() {
		cout << "Thunderstorm: " << power << endl;
	}
};

class Waterbolt : public Spell {
private: int power;
public:
	Waterbolt(int power) : power(power) { }
	void revealWaterpower() {
		cout << "Waterbolt: " << power << endl;
	}
};

class SpellJournal {
public:
	static string journal;
	static string read() {
		return journal;
	}
};
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
	Fireball *fireball = dynamic_cast<Fireball*>(spell);
	if (fireball != NULL) {
		fireball->revealFirepower();
		return;
	}
	Frostbite *frostbite = dynamic_cast<Frostbite*>(spell);
	if (frostbite != NULL) {
		frostbite->revealFrostpower();
		return;
	}
	Thunderstorm *thunderstorm = dynamic_cast<Thunderstorm*>(spell);
	if (thunderstorm != NULL) {
		thunderstorm->revealThunderpower();
		return;
	}
	Waterbolt *waterbolt = dynamic_cast<Waterbolt*>(spell);
	if (waterbolt != NULL) {
		waterbolt->revealWaterpower();
		return;
	}

	string scrollName = spell->revealScrollName();
	string journal = SpellJournal::read();
	int **cache = new int*[scrollName.length()];
	for (int i = 0; i < scrollName.length(); i++) {
		cache[i] = new int[journal.length()];
		for (int j = 0; j < journal.length(); j++) {
			cache[i][j] = 0;
		}
	}
	/* // timeout
	class Recursive {
	public:
		int recursive(string str1, string str2, int **cache) {
			if (cache[str1.length() - 1][str2.length() - 1] != -1) {
				return cache[str1.length() - 1][str2.length() - 1];
			}
			int result1 = 0, result2 = 0;
			if (str1.length() > 1) {
				result1 = recursive(str1.substr(1), str2, cache);
				int index = str2.find(str1[0]);
				if (index >= 0) {
					if(index + 1 < str2.length())
						result2 = recursive(str1.substr(1), str2.substr(index + 1), cache) + 1;
					else result2 = 1;
				}
			}
			else {
				int index = str2.find(str1[0]);
				if (index >= 0) {
					result1 = 1;
				}
			}
			cache[str1.length() - 1][str2.length() - 1] = result1 > result2 ? result1 : result2;
			return cache[str1.length() - 1][str2.length() - 1];
		}
	};
	Recursive r;
	cout << r.recursive(scrollName, journal, cache) << endl;*/

	for (int i = 0; i < scrollName.length(); i++) {
		for (int j = 0; j < journal.length(); j++) {
			if (scrollName[i] == journal[j]) {
				if (i > 0 && j > 0) {
					cache[i][j] = cache[i - 1][j - 1] + 1;
				}
				else {
					cache[i][j] = 1;
				}
			}
			else {
				if (i > 0 && j > 0) {
					cache[i][j] = cache[i - 1][j] > cache[i][j - 1] ? cache[i - 1][j] : cache[i][j - 1];
				}
				else if (i > 0) {
					cache[i][j] = cache[i - 1][j];
				}
				else if (j > 0) {
					cache[i][j] = cache[i][j - 1];
				}
			}
		}
	}
	cout << cache[scrollName.length() - 1][journal.length() - 1] << endl;
	for (int i = 0; i < scrollName.length(); i++) {
		delete cache[i];
	}
	delete cache;
}

class Wizard {
public:
	Spell *cast() {
		Spell *spell;
		string s; cin >> s;
		int power; cin >> power;
		if (s == "fire") {
			spell = new Fireball(power);
		}
		else if (s == "frost") {
			spell = new Frostbite(power);
		}
		else if (s == "water") {
			spell = new Waterbolt(power);
		}
		else if (s == "thunder") {
			spell = new Thunderstorm(power);
		}
		else {
			spell = new Spell(s);
			cin >> SpellJournal::journal;
		}
		return spell;
	}
};

int main() {
	int T;
	cin >> T;
	Wizard Arawn;
	while (T--) {
		Spell *spell = Arawn.cast();
		counterspell(spell);
	}
	return 0;
}