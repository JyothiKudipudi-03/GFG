//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
          // Map to store groups of anagrams
        unordered_map<string, vector<string>> anagramGroups;
        vector<string> order; // To maintain the order of first appearance of keys

        // Traverse each string in the array
        for (const string& str : arr) {
            // Sort the string to generate a key
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // If it's a new key, add to the order vector
            if (anagramGroups.find(sortedStr) == anagramGroups.end()) {
                order.push_back(sortedStr);
            }

            // Group the original string using the sorted key
            anagramGroups[sortedStr].push_back(str);
        }

        // Extract grouped anagrams into a vector of vectors in the order of appearance
        vector<vector<string>> result;
        for (const string& key : order) {
            result.push_back(anagramGroups[key]);
        }

        return result;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
