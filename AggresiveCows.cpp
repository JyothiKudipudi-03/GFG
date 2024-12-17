//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        // Step 1: Sort the stalls
        sort(stalls.begin(), stalls.end());
        
        // Step 2: Initialize binary search bounds
        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls.front(); // Maximum possible distance
        int result = 0; // To store the maximum minimum distance
        
        // Step 3: Binary search for the maximum minimum distance
        while (low <= high) {
            int mid = low + (high - low) / 2; // Midpoint distance
            
            // Step 4: Check if we can place cows with at least 'mid' distance
            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Update result
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }
        
        return result; // Return the maximum minimum distance found
    }
    
private:
    // Helper function to check if we can place cows with at least 'minDist' distance
    bool canPlaceCows(vector<int> &stalls, int k, int minDist) {
        int count = 1; // Place the first cow
        int lastPosition = stalls[0]; // Position of the last placed cow
        
        for (int i = 1; i < stalls.size(); i++) {
            // If the current stall is at least 'minDist' away from the last placed cow
            if (stalls[i] - lastPosition >= minDist) {
                count++; // Place another cow
                lastPosition = stalls[i]; // Update the last position
                
                // If we have placed all cows, return true
                if (count == k) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
