//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        int i = 0; // Pointer to traverse the string
        int sign = 1; // To store the sign of the number
        long result = 0; // Result to handle overflow/underflow
        
        // Step 1: Skip leading whitespaces
        while (s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits and construct the number
        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Handle overflow and underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }

        // Step 5: Return the final result with the correct sign
        return result * sign;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
