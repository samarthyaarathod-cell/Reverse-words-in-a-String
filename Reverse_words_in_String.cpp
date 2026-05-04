#include <bits/stdc++.h>
using namespace std;

// Helper to reverse a part of string
void reverseStr(string &s, int left, int right) {
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

string reverseWords(string s) {
    int n = s.size();
    int i = 0, j = 0;

    // Step 1: Remove extra spaces
    while (j < n) {
        while (j < n && s[j] == ' ') j++; // skip spaces
        while (j < n && s[j] != ' ') s[i++] = s[j++]; // copy word
        while (j < n && s[j] == ' ') j++; // skip spaces
        if (j < n) s[i++] = ' '; // add single space
    }
    s.resize(i);

    // Step 2: Reverse whole string
    reverseStr(s, 0, s.size() - 1);

    // Step 3: Reverse each word
    int start = 0;
    for (int end = 0; end <= s.size(); end++) {
        if (end == s.size() || s[end] == ' ') {
            reverseStr(s, start, end - 1);
            start = end + 1;
        }
    }

    return s;
}

int main() {
    string s = "The sky is blue.";
    cout << reverseWords(s);
    return 0;
}