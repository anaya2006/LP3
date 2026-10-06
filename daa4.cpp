#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:

    int knapsack01(int W, vector<Item>& arr) {

        int n = arr.size();

        // dp[i][w] = maximum value using first i items
        // with capacity w
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        // Build the DP table
        for (int i = 1; i <= n; i++) {

            for (int w = 1; w <= W; w++) {

                // If item weight is less than or equal to capacity
                if (arr[i - 1].weight <= w) {

                    // Maximum of:
                    // 1. Including the item
                    // 2. Excluding the item
                    dp[i][w] = max(
                        arr[i - 1].value +
                        dp[i - 1][w - arr[i - 1].weight],

                        dp[i - 1][w]
                    );
                }
                else {

                    // Cannot include the item
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[n][W];
    }
};

int main() {

    int n, W;

    // User input
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    vector<Item> arr(n);

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++) {

        cout << "Item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    Solution obj;

    int ans = obj.knapsack01(W, arr);

    cout << "The maximum value is: " << ans << endl;

    return 0;
}
/*OUTPUT 
C:\Users\HP\OneDrive\Desktop\sem7>g++ daa4.cpp

C:\Users\HP\OneDrive\Desktop\sem7>a.exe
Enter number of items: 4
Enter capacity of knapsack: 90
Enter value and weight of each item:
Item 1: 100 20
Item 2: 60 10
Item 3: 100 50
Item 4: 200 50
The maximum value is: 360

C:\Users\HP\OneDrive\Desktop\sem7>*/