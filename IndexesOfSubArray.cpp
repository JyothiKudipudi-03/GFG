//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
         int n = arr.size();
        int currentSum = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            // Add the current element to the running sum
            currentSum += arr[end];

            // If the sum exceeds the target, move the start pointer
            while (currentSum > target && start <= end) {
                currentSum -= arr[start];
                start++;
            }

            // If the sum equals the target, return the indices (1-based)
            if (currentSum == target) {
                return {start + 1, end + 1};
            }
        }

        // If no subarray is found, return [-1]
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
