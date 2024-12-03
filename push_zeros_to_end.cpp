#include <bits/stdc++.h>
using namespace std;
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
         int j = 0;  // Pointer to track the position for non-zero elements
        
        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            // If the current element is non-zero, move it to the 'j' position
            if (arr[i] != 0) {
                // Swap arr[i] with arr[j]
                swap(arr[i], arr[j]);
                j++;  // Move the 'j' pointer
            }
        }
    }
};
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
