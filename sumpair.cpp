//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if (arr.size() < 2) return {};

        // Sort the array
        sort(arr.begin(), arr.end());

        // Initialize variables to store the closest pair
        int closestDiff = INT_MAX; // To track the minimum difference
        vector<int> result;        // To store the resulting pair

        // Two pointers
        int i = 0, j = arr.size() - 1;

        while (i < j) {
            int sum = arr[i] + arr[j];
            int diff = abs(sum - target);

            // If the current pair is closer to the target
            if (diff < closestDiff || 
                (diff == closestDiff && abs(arr[j] - arr[i]) > abs(result[1] - result[0]))) {
                closestDiff = diff;
                result = {arr[i], arr[j]};
            }

            // Adjust pointers based on the current sum
            if (sum < target) {
                i++; // Increase the sum
            } else {
                j--; // Decrease the sum
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
