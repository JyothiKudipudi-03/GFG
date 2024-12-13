//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n = arr.size();

        // Step 1: Find the maximum subarray sum using Kadane's algorithm
        int maxKadane = kadane(arr);

        // Step 2: Find the total sum of the array
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // Step 3: Find the minimum subarray sum using modified Kadane's algorithm
        // To find the minimum subarray sum, invert the signs of the elements
        int minKadane = kadaneForMin(arr);

        // Step 4: Calculate the circular subarray sum
        int maxCircular = totalSum - minKadane;

        // Step 5: Handle the special case where all elements are negative
        // If all elements are negative, the maximum circular sum will be equal to the maximum Kadane result.
        if (maxCircular == 0) {
            return maxKadane;
        }

        // Step 6: Return the maximum of the two cases
        return max(maxKadane, maxCircular);
    }

private:
    // Helper function to find maximum subarray sum using Kadane's algorithm
    int kadane(vector<int> &arr) {
        int maxSum = INT_MIN, currentSum = 0;
        for (int num : arr) {
            currentSum = max(num, currentSum + num);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }

    // Helper function to find minimum subarray sum using Kadane's algorithm
    int kadaneForMin(vector<int> &arr) {
        int minSum = INT_MAX, currentSum = 0;
        for (int num : arr) {
            currentSum = min(num, currentSum + num);
            minSum = min(minSum, currentSum);
        }
        return minSum;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends
