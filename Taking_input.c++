// Taking input
/* Before implementing any algorithm, we should be thorough with taking inputs. Here, we will learn how to read inputs.
You are given two inputs: a(integer), and b(string). You need to take the input and print a and b separated by a space.
Note: You have to print a new line at the end after prinintg a and b.
Example 1:
Input:
a = 5
b = Hello
Output:
5 Hello  */

#include <bits/stdc++.h>
using namespace std;

class Taking_input {
  public:
    void inputData() {
         int a ;
         string b;
         cin>>a>>b;
         cout << a << " " << b<<endl;    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        Solution obj;

        obj.inputData();
    }
}

// } Driver Code Ends
