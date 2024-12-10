//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
         int n = intervals.size();
        if (n == 0) return 0;

        // Sort intervals based on their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int removals = 0;
        int prevEnd = intervals[0][1]; // Track the end of the last non-overlapping interval

        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prevEnd) {
                // Current interval overlaps, so we remove it
                removals++;
            } else {
                // No overlap, update the previous end time
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
