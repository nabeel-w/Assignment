#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    int start = 0;
    int maxLen = 1;

    // Check for palindromes of odd length
    for (int i = 1; i < n; i++) {
        int left = i - 1;
        int right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    // Check for palindromes of even length
    for (int i = 1; i < n; i++) {
        int left = i - 1;
        int right = i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s = "madam";
    string longest = longestPalindrome(s);
    cout << "Longest palindrome in '" << s << "' is '" << longest << "'" << endl;
    return 0;
}