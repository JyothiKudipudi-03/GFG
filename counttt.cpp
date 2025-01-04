//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int n = arr.size();
        int count = 0;

        // Sort the array (if not already sorted)
        sort(arr.begin(), arr.end());

        // Iterate through the array
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1; // Start pointer for the second element
            int right = n - 1; // Start pointer for the third element

            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];

                if (currentSum == target) {
                    // Count all duplicates for arr[left] and arr[right]
                    if (arr[left] == arr[right]) {
                        // If both pointers point to the same value
                        int totalElements = right - left + 1;
                        count += (totalElements * (totalElements - 1)) / 2; // C(n, 2)
                        break; // No need to check further
                    } else {
                        // Count duplicates for left
                        int leftCount = 1;
                        while (left + 1 < right && arr[left] == arr[left + 1]) {
                            leftCount++;
                            left++;
                        }

                        // Count duplicates for right
                        int rightCount = 1;
                        while (right - 1 > left && arr[right] == arr[right - 1]) {
                            rightCount++;
                            right--;
                        }

                        // Add the number of combinations of left and right duplicates
                        count += leftCount * rightCount;

                        // Move both pointers
                        left++;
                        right--;
                    }
                } else if (currentSum < target) {
                    left++; // Increase the sum
                } else {
                    right--; // Decrease the sum
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
