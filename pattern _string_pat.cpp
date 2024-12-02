/*Problem Statement
Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices.

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
If there is no occurrence of the pattern, return an empty list.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int pat_len = pat.size();
        int txt_len = txt.size();
        
        // Compute the prefix-suffix array (lps) for the pattern
        vector<int> lps(pat_len, 0);
        int j = 0;  // length of the previous longest prefix suffix
        for (int i = 1; i < pat_len; i++) {
            while (j > 0 && pat[i] != pat[j]) {
                j = lps[j - 1];
            }
            if (pat[i] == pat[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // KMP algorithm to search the pattern in the text
        j = 0;  // index for pat[]
        for (int i = 0; i < txt_len; i++) {
            while (j > 0 && txt[i] != pat[j]) {
                j = lps[j - 1];
            }
            if (txt[i] == pat[j]) {
                j++;
            }
            if (j == pat_len) {
                result.push_back(i - pat_len + 1);  // Pattern found, store index
                j = lps[j - 1];  // Prepare for next possible match
            }
        }
        return result;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.empty())
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
