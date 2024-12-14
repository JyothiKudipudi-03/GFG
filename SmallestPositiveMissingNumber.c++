//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
         int n = arr.size();
        
        // Step 1: Replace negatives and out-of-range numbers with a placeholder (n + 1)
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0 || arr[i] > n) {
                arr[i] = n + 1;
            }
        }
        
        // Step 2: Mark the indices corresponding to existing numbers
        for (int i = 0; i < n; i++) {
            int val = abs(arr[i]); // Take the absolute value to handle previously marked indices
            if (val <= n) {
                arr[val - 1] = -abs(arr[val - 1]); // Mark the value as visited (negate)
            }
        }
        
        // Step 3: Find the first positive index
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                return i + 1; // Missing number is index + 1
            }
        }
        
        // Step 4: If all numbers are present, return n + 1
        return n + 1;
    }
};


//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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

        Solution ob;
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
