//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
       
         // Step 1: Sort intervals by starting time
        sort(arr.begin(), arr.end());

        // Declare merged vector to store the merged intervals
        vector<vector<int>> merged;
        
        // Step 2: Traverse the intervals
        for (const auto& interval : arr) {
            // If merged is empty or the current interval doesn't overlap with the last interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval); // Add the current interval
            } else {
                // Merge intervals by updating the end time of the last interval
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
