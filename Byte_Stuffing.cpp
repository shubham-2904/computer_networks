#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define MAX_Size 100

void byteStuffing(int byteSize) {
    string bytes;
    cout << "Enter string : ";
    cin >> bytes;

    if (bytes.length() > byteSize) {
        cout << "string is out of bound" << endl;
        return;
    }

    int noOfFrame; 
    cout << "\nEnter number of frame you want to create: ";
    cin >> noOfFrame;
    
    int noOfCharPerFrame = bytes.length() / noOfFrame;

    // for adding padding
    int padding = bytes.length() % noOfFrame;
    if (padding != 0) {
        padding = noOfFrame - padding;
        string addPadding = "";
        for (int i = 0 ; i < padding; i++) {
            addPadding += "0";
        }
        // noOfFrame += 1;
        noOfCharPerFrame += 1;
        bytes.append(addPadding);
    }

    // creating frames
    vector<vector<string>> frames;
    int k = 0;

    // outer loop for frames
    for (int i = 0; i < noOfFrame; i++) {
        // for bits
        string str = "";
        vector<string> f;
        for (int j = 0; j < noOfCharPerFrame; j++) {
            str = str + bytes[k];
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
    
    return;
}

int main() {
    cout << "Enter the byte size of bits: ";
    int byteSize;
    cin >> byteSize;

    if (byteSize <= 0 && byteSize > MAX_Size) {
        cout << "\nError! enter valid bits bitSize\n";
    }
    else {
        byteStuffing(byteSize);
    }

    return 0;
}