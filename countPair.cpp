//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
            unordered_map<int, int> freqMap; // Hash map to store frequencies
        int count = 0;

        for (int num : arr) {
            int complement = target - num; // Calculate the complement
            if (freqMap.find(complement) != freqMap.end()) {
                count += freqMap[complement]; // Increment count by the frequency of the complement
            }
            freqMap[num]++; // Add the current number to the hash map
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
