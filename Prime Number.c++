//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPrime(int n) {
        // code here
         if (n <= 1) return false; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false; // Divisible by another number
    }
    return true; // Prime if no divisors are found
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << (ob.isPrime(N) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
