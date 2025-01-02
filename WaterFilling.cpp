/*  Water Filling
Chef has three water bottles. At any point, if at least two of them are empty, she will fill them up. But if at most one bottle is empty,
she will wait, and not fill them up now.
You are given three integers - B1,B2, and B3.
If B1=1, it means that the first bottle is full.
If B1=0, it means that the first bottle is empty.
Similarly, B2 denotes whether the second bottle is full or empty, and B3 denotes it for the third bottle.
Output "Water filling time", if Chef has to fill the bottles now. If not, output "Not now".   */

#include <bits/stdc++.h>
using namespace std;
int main() {
        // your code goes here
        int t;
        cin >> t;
        while (t--) {
                int B1, B2, B3;
                cin >> B1 >> B2 >> B3;
                if ((B1 == 0 && B2 == 0) || (B2 == 0 && B3 == 0) || (B1 == 0 && B3 == 0)) {
                        cout << "Water filling time" << endl;
                }
                else {
                        cout << "Not now" << endl;
                }
        }
}
