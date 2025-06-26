using namespace std;
#include <iostream>
#include <vector>
#include <string>

int main() {
	int length;
	string str;
	cin >> length;
	cin >> str;
	int cur = 0;
	cout << (length / 2) * 3 << '\n';
	for (int i = length - 1; i >= 0; i--) {
		if (str[i] == 'S') {
			cur++;
			if (cur > 0) {
				cout << "UN";
			}
			else {
				cout << "N";
			}

		}
		else
		{
			cur--;
			if (cur < 0) {
				cout << "SN";
			}
			else {
				cout << "N";
			}
		}

	}

	return 0;
}