//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> charIndex; // To store the last index of every character
        int maxLength = 0; // To store the maximum length of substring
        int start = 0; // Left boundary of the sliding window

        for (int end = 0; end < s.size(); ++end) {
            char currentChar = s[end];

            // If the character is already in the map and its index is within the current window
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= start) {
                // Move the start of the window to the right of the previous occurrence of the character
                start = charIndex[currentChar] + 1;
            }

            // Update the last index of the current character
            charIndex[currentChar] = end;

            // Calculate the length of the current window
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
