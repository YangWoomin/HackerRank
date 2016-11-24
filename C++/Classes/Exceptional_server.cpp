#include "header.h"

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) throw 0;
		real = (A / B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

void exceptional_server() {
	int T; cin >> T;
	while (T--) {
		long long A, B;
		cin >> A >> B;
		/* Enter your code here. */
		try {
			int result = Server::compute(A, B);
			cout << result << endl;
		}
		catch (const std::bad_alloc& ba) {
			cout << "Not enough memory" << endl;
		}
		catch (const std::invalid_argument& ia) {
			cout << "Exception: " << ia.what() << endl;
		}
		catch (logic_error le) {
			cout << "Exception: " << le.what() << endl;
		}
		catch (int other) {
			cout << "Other Exception" << endl;
		}
		catch (exception e) {
			cout << "Exception: " << e.what() << endl;
		}
	}
	cout << Server::getLoad() << endl;
}