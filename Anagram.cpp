//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
         // Step 1: Check if lengths are different
        if (s1.size() != s2.size()) {
            return false;
        }
        
        // Step 2: Frequency array to count character occurrences
        vector<int> freq(26, 0);
        
        // Step 3: Update frequency array
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++; // Increment count for s1
            freq[s2[i] - 'a']--; // Decrement count for s2
        }
        
        // Step 4: Check if all counts are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends  
