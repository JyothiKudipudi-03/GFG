#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Create a new string with separator to avoid overlap between the original and reversed string
        string combined = s + "#" + rev_s;
        
        // KMP algorithm to compute longest prefix suffix (LPS array)
        int n = combined.size();
        vector<int> lps(n, 0);
        
        // Fill the LPS array
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // The longest palindromic prefix of s will be the value in the LPS array for the last character of combined
        int longest_palindrome_suffix = lps[n - 1];
        
        // To make the string a palindrome, we need to add characters before the string
        return s.size() - longest_palindrome_suffix;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

