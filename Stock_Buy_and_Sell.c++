//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
         int minPrice = INT_MAX;
        // Initialize maximum profit to 0
        int maxProfit = 0;

        // Iterate through the prices array
        for (int price : prices) {
            // Update the minimum price so far
            minPrice = min(minPrice, price);
            // Calculate the current profit
            int currentProfit = price - minPrice;
            // Update the maximum profit if current profit is greater
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
