//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
         int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns
        
        int left = 0, right = n * m - 1;
        
        // Binary search in conceptual 1D array
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Map mid index back to 2D matrix
            int row = mid / m;
            int col = mid % m;
            
            if (mat[row][col] == x) {
                return true; // Element found
            } else if (mat[row][col] < x) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        
        return false; // Element not found
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
