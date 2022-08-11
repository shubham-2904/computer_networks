#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define MAX_Size 100

void bitStuffing(int bitSize) {
    // here will perform the bits stuffing program main program logic
    string bits;
    cout << "Enter string of 0's and 1's: ";
    cin >> bits;

    if(bits.length() > bitSize) {
        cout << "string is to long";
        return;
    }

    int sizeOfFrame;  // size of frame
    cout << "\nEnter size of frame: ";
    cin >> sizeOfFrame;

    int noOfFrame = bits.length() / sizeOfFrame;

    // for adding padding
    int padding = bits.length() % sizeOfFrame;
    if (padding != 0) {
        padding = sizeOfFrame - padding;
        string addPadding = "";
        for (int i = 0 ; i < padding; i++) {
            addPadding += "0";
        }
        noOfFrame += 1;
        bits.append(addPadding);
    }
    
    // creating frames
    vector<vector<string>> frames;
    int k = 0;

    // outer loop for frames
    for (int i = 0; i < noOfFrame; i++) {
        // for bits
        string str = "";
        vector<string> f;
        for (int j = 0; j < sizeOfFrame; j++) {
            str = str + bits[k];
            k++;
        }
        f.push_back(str);
        frames.push_back(f);
    }

    // enter delimiter
    string delimiter;
    cout << "\nEnter delimiter: ";
    cin >> delimiter;
    vector<string> delimitFrame;

    for (vector<string> i: frames) {
        for (string s : i) {
            s = delimiter + s + delimiter;
            delimitFrame.push_back(s);
        }
    }

    cout << "\nFrames with delimiter: " << endl;
    for (string s: delimitFrame) {
        cout << s << endl;
    }

    vector<string> result;
    for (int i = 0; i < delimitFrame.size(); i++) {
        int counter0 = 0;
        int counter1 = 0;
        string str = "";
        for (int j = 0; j < delimitFrame[i].size(); j++) {
            str += delimitFrame[i][j];
            if (delimitFrame[i][j] == '0') {
                counter0++;
                counter1 = 0;
            }
            if (delimitFrame[i][j] == '1') {
                counter1++;
                counter0 = 0;
            }

            if (counter0 == 5) {
                str = str + "1";
                counter0 = 0;
            }
            if (counter1 == 5) {
                str += "0";
                counter1 = 0;
            }
        }

        result.push_back(str);
    }

    // displaying frame data with delimiter
    cout << "\nFrame data => \n";
    for (string i : result) {
        cout << i << " ";
    }
    

    return;
}

int main() {
    cout << "Enter the bitSize of bits: ";
    int bitSize;
    cin >> bitSize;

    if (bitSize <= 0 && bitSize > MAX_Size) {
        cout << "\nError! enter valid bits bitSize\n";
    }
    else {
        bitStuffing(bitSize);
    }
    return 0;
}