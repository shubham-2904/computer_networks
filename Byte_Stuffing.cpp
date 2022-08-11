#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define MAX_Size 100

bool checkFlag(char *ptr, string delimiter) {
    for (int i = 0; i < delimiter.size(); i++) {
        if (delimiter[i] != *(ptr++))
            return false;
    }
    return true;
}

void byteStuffing(int byteSize) {
   string byte;
   cout << "Enter the string: ";
   cin >> byte;

   cout << "\nEnter size of frame: ";
   int sizeOfFrame;
   cin >> sizeOfFrame;

   int noOfFrame = byte.length() / sizeOfFrame;

   // for adding padding
    int padding = byte.length() % sizeOfFrame;
    if (padding != 0) {
        padding = sizeOfFrame - padding;
        string addPadding = "";
        for (int i = 0 ; i < padding; i++) {
            addPadding += "0";
        }
        noOfFrame += 1;
        byte.append(addPadding);
    }

    // creating frames
    vector<vector<string>> frames;
    int k = 0;

    // outer loop for frames
    for (int i = 0; i < noOfFrame; i++) {
        // for byte
        string str = "";
        vector<string> f;
        for (int j = 0; j < sizeOfFrame; j++) {
            str = str + byte[k];
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
    for (auto f : delimitFrame) {
        cout << f << endl;
    }

    vector<string> result;
    for (int i = 0; i < delimitFrame.size(); ++i) {
        string str;
        for (int j = 0; j < delimitFrame[i].size(); ++j) {
            bool check = checkFlag(&delimitFrame[i][j], delimiter);
            if (check) {
                for (int k = 0; k < delimiter.size(); ++k) {
                    str += delimitFrame[i][j++];
                }
                str += delimiter;
                --j;
            }
            else {
                str += delimitFrame[i][j];
            }
        }
        result.push_back(str);
    }

    cout << "-------------------------------------" << endl;
    cout << "After byte stuffing" << endl;
    cout << "-------------------------------------" << endl;
    for (string f : result) {
        cout << f << "\n";
    }
    
}

int main() {
    cout << "Enter the byte size: ";
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