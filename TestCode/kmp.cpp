#include<iostream>
#include<vector>
using namespace std;

vector<int> getNext(string p) {
    int i = 0, j = -1;
    vector<int> next = vector<int>();
    next.push_back(-1);
    while (i < p.length()) {
        if (j == -1 || p[i] == p[j]) {
            ++i;
            ++j;
            next.push_back(j);
        }
        else {
            j = next[j];
        }
    }
    for (int index = 0; index < next.size(); ++index) {
        cout << index << " " << next[index] << endl;
    }

    return next;
}

int getFindIndex(string s, string p) {
    int i = 0, j = 0;
    vector<int> next = getNext(p);
    // string common = "";
    // length返回的是非负数，如果跟负数做比较会溢出，需要转一下
    int sizeS = s.length();
    int sizeP = p.length();
    while(i < sizeS && j < sizeP) {
        if (j == -1 || s[i] == p[j]) {
            ++i;
            ++j;
            // if (j > common.length()) {
            //     common = p.substr(0, j);
            // }
        }
        else {
            j = next[j];
        }
    }
    if (j == sizeP) {
        return i - j;
    }
    else {
        return -1;
    }
}

int main() {
    // cout << getLongestCommon("abababca", "fdasfababdf");
    cout << getFindIndex("dabab", "bac");
    // cout << getLongestCommon("babad", "dabab");
    return 0;
}