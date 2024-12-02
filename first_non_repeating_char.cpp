/* Problem Statement

Given a string `s` consisting of lowercase Latin letters, your task is to find the **first non-repeating character** in the string. If no such character exists, return `'$'`. This can be solved efficiently by counting the frequency of characters and identifying the first character with a count of 1.

Approach
1. Traverse the string to count the frequency of each character.
2. Traverse the string again to find the first character with a frequency of 1.
3. Return that character, or `'$'` if no non-repeating character is found.

Example
Input: `"geeksforgeeks"`
Output: `'f'`

Input: `"aabbccc"`
Output: `-1`

Code: */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq;
        
        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Find the first character that appears only once
        for (char ch : s) {
            if (freq[ch] == 1) {
                return ch;
            }
        }

        // Return '$' if no non-repeating character is found
        return '$';
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);
        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}
/* Explanation

1. First Traversal: The frequency of each character is calculated using an unordered map.
2. Second Traversal: We check each character in the string in order, and return the first character with a frequency of 1.
3. Edge Case: If no non-repeating character is found, return `'$'`. */
