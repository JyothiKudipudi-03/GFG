//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
          int i = 0, j = arr.size() - 1; // Two pointers
        int count = 0; // To store the count of valid pairs

        while (i < j) {
            int sum = arr[i] + arr[j];

            if (sum == target) {
                if (arr[i] == arr[j]) {
                    // Case: All elements between i and j are identical
                    int freq = j - i + 1; // Total identical elements
                    count += (freq * (freq - 1)) / 2; // nC2 = n * (n-1) / 2
                    break;
                }

                // Count duplicates for arr[i]
                int countLeft = 1;
                while (i + 1 < j && arr[i] == arr[i + 1]) {
                    countLeft++;
                    i++;
                }

                // Count duplicates for arr[j]
                int countRight = 1;
                while (j - 1 > i && arr[j] == arr[j - 1]) {
                    countRight++;
                    j--;
                }

                // Add pairs formed by these duplicates
                count += countLeft * countRight;

                // Move both pointers after counting
                i++;
                j--;
            } else if (sum < target) {
                i++; // Increase the sum
            } else {
                j--; // Decrease the sum
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
