//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
             // Auxiliary array to help with merge sort
        vector<int> temp(arr.size());
        return mergeSort(arr, temp, 0, arr.size() - 1);
    }

private:
    // Helper function to implement merge sort and count inversions
    int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            invCount += mergeSort(arr, temp, left, mid);  // Count inversions in the left half
            invCount += mergeSort(arr, temp, mid + 1, right);  // Count inversions in the right half
            invCount += merge(arr, temp, left, mid, right);  // Count inversions during the merge step
        }
        return invCount;
    }

    // Merge function to merge two halves and count inversions
    int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left;
        int invCount = 0;

        // Merge the two halves
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1);  // All elements left in the left half are greater than arr[j]
            }
        }

        // Copy the remaining elements of left half, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of right half, if any
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the sorted subarray into the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return invCount;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
