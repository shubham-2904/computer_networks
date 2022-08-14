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

void encode(string data, string key) {
	int l_key = key.length();
	string append_data = (data + string(l_key - 1, '0'));
	string remainder = mod2div(append_data, key);
	string codeword = data + remainder;

	cout << "Remainder: " << remainder << endl;
	cout << "Encoded data (data + remiander): " << codeword << endl;
}

int main() {
	string data = "100100";
	string key = "1101";

	encode(data, key);
	return 0;
}