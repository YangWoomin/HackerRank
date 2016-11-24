// https://www.hackerrank.com/challenges/box-it
#include "header.h"

class Box {
private:
	long long length, breath, height;
public:
	Box() {
		length = breath = height = 0;
	}
	Box(int length, int breath, int height) {
		this->length = length;
		this->breath = breath;
		this->height = height;
	}

	int getLength() {
		return length;
	}
	int getBreath() {
		return breath;
	}
	int getHeight() {
		return height;
	}
	Box(Box &box) {
		length = box.getLength();
		breath = box.getBreath();
		height = box.getHeight();
	}
	long long CalculateVolume() {
		return length * breath * height;
	}
	bool operator<(Box& ref) {
		if (this->length < ref.getLength()) {
			return true;
		}
		else if (this->breath < ref.getBreath() && this->length == ref.getLength()) {
			return true;
		}
		else if (this->height < ref.getHeight() && this->breath == ref.getBreath() && this->length == ref.getLength()) {
			return true;
		}
		else {
			return false;
		}
	}
};

ostream& operator<<(ostream& o, Box& box) {
	o << to_string(box.getLength()) << " " << to_string(box.getBreath()) << " " << to_string(box.getHeight());
	return o;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i<n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox<temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}