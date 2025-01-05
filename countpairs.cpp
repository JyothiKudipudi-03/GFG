//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
          sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left < right) {
            if (arr[left] + arr[right] < target) {
                // All pairs between left and right are valid
                count += (right - left);
                left++;  // Move the left pointer to the next position
            } else {
                // Decrease the sum by moving the right pointer left
                right--;
            }
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
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
