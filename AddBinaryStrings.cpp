//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
            while (s1.size() < s2.size()) s1 = "0" + s1;
        while (s2.size() < s1.size()) s2 = "0" + s2;

        string result = ""; // Store the final binary result
        int carry = 0; // Keep track of carry

        // Start adding from the rightmost end
        for (int i = s1.size() - 1; i >= 0; --i) {
            int bit1 = s1[i] - '0'; // Convert char to integer
            int bit2 = s2[i] - '0'; // Convert char to integer

            int sum = bit1 + bit2 + carry;
            result = char((sum % 2) + '0') + result; // Append the sum's least significant bit
            carry = sum / 2; // Update carry
        }

        // If there's still a carry left, prepend it to the result
        if (carry) {
            result = "1" + result;
        }

        // Remove leading zeros, if any
        while (result.size() > 1 && result[0] == '0') {
            result.erase(0, 1);
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
