//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
         int i = 0;                // Left pointer
        int j = arr.size() - 1;   // Right pointer
        int count = 0;            // To store the count of pairs
        
        while (i < j) {
            int sum = arr[i] + arr[j];
            
            if (sum == target) {
                // Count duplicates for arr[i] and arr[j]
                int countLeft = 1, countRight = 1;
                
                while (i + 1 < j && arr[i] == arr[i + 1]) {
                    countLeft++;
                    i++;
                }
                while (j - 1 > i && arr[j] == arr[j - 1]) {
                    countRight++;
                    j--;
                }
                
                if (arr[i] == arr[j]) {
                    // If both pointers point to the same value
                    count += (countLeft * (countLeft - 1)) / 2;
                } else {
                    count += countLeft * countRight;
                }
                
                // Move pointers after counting
                i++;
                j--;
            } else if (sum < target) {
                i++;    // Increase the sum
            } else {
                j--;    // Decrease the sum
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
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
