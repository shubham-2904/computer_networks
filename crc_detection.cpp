#include "bits/stdc++.h"
using namespace std;

string xor1(string a, string b) {
	string result = "";
	int n = b.length();

 	for(int i = 1; i < n; i++) {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }

    return result;
}

string mod2div(string divident, string divisor) {
	int pick = divisor.length();
	int n = divident.length();

	string temp = divident.substr(0, pick);

	while (pick < n) {
		if (temp[0] == '1') {
			temp = xor1(divisor, temp) + divident[pick];
		}
		else {
	 		temp = xor1(string(pick, '0'), temp) + divident[pick];
		}

		pick += 1;
	}

	if (temp[0] == '1') {
		temp = xor1(divisor, temp);
	}
	else {
		temp = xor1(string(pick, '0'), temp);
	}


	return temp;
}

pair<string, string> encode(string data, string key) {
	int l_key = key.length();
	string append_data = (data + string(l_key - 1, '0'));
	string remainder = mod2div(append_data, key);
	string codeword = data + remainder;

	return {remainder, codeword};
}

int main() {
	string data, key;
	cout << "Enter data in 0's or 1's format: ";
	cin >> data;
	cout << "Enter the value of key: ";
	cin >> key;

	pair<string, string> result = encode(data, key);

	cout << "Remainder: " << result.first << endl;
	cout << "Encoded data (data + remiander): " << result.second << endl;
	return 0;
}