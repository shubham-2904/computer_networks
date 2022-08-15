#include "bits/stdc++.h"
using namespace std;

vector<int> generatingHammingCode(vector<int> msgBits, int m, int r) {
	// creating the code of size r + m (that is msgBit(m) + redundant(r))
	vector<int> hammingCode(r + m);

	// finding the position of redundatn bits (parity bits)
	for (int i = 0; i < r; ++i) {
		// placing the parity bit to -1
		hammingCode[pow(2, i) - 1] = -1;
	}

	int j = 0;
	// creating the data that is msgBit + redundant
	for (int i = 0; i < (r + m); ++i) {
		if (hammingCode[i] != -1) {
			hammingCode[i] = msgBits[j];
			++j;
		}
	}

	for (int i = 0; i < (r + m); ++i) {
		if (hammingCode[i] != -1) {
			continue;
		}

		int x = log2(i + 1);
		int one_count = 0;

		for (int j = i + 2; j <= (r + m); ++j) {
			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1) {
					one_count++;
				}
			}
		}

		if (one_count % 2 == 0) {
			hammingCode[i] = 0;
		}
		else {
			hammingCode[i] = 1;
		}
	}

	return hammingCode;
}

void findingHammingCode(vector<int> &msgBit) {
	// bit msg size
	int m = msgBit.size();
	int r = 0;
	
	while (pow(2, r) < (m + r + 1)) {
		r++;
	}
	
	// generationg code
	vector<int> ans = generatingHammingCode(msgBit, m, r);

	cout << "Message bits are : ";
	for (int i = 0; i < msgBit.size(); ++i) {
		cout << msgBit[i] << " ";
	}

	cout << "\nHamming code is : ";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
}

int main() {

	vector<int> msgBit;
	cout << "Enter message bit: " << endl;
	string data;
	cin >> data;
	for (auto element : data) {
		int d = element - '0';
		msgBit.push_back(d);
	}
	findingHammingCode(msgBit);
}