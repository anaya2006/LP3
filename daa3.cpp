#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;

        return r1 > r2;
    }

    double fractionalKnapsack(int W, vector<Item>& arr) {

        // Sort according to value/weight ratio
        sort(arr.begin(), arr.end(), comp);

        int curWeight = 0;
        double finalValue = 0.0;

        for (auto &item : arr) {

            // Take complete item
            if (curWeight + item.weight <= W) {
                curWeight += item.weight;
                finalValue += item.value;
            }
            else {
                // Take fractional part
                int remain = W - curWeight;

                finalValue +=
                    (item.value / (double)item.weight) * remain;

                break;
            }
        }

        return finalValue;
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

    double ans = obj.fractionalKnapsack(W, arr);

    cout << fixed << setprecision(2);
    cout << "The maximum value is: " << ans << endl;

    return 0;
}

/* OUTPUT 
admin1@admin1-V520-15IKL:~$ g++ fknap.cpp
admin1@admin1-V520-15IKL:~$ ./a.out
Enter number of items: 4
Enter capacity of knapsack: 90
Enter value and weight of each item:
Item 1: 100
20
Item 2: 60 10
Item 3: 100 50
Item 4: 200 50
The maximum value is: 380.00
admin1@admin1-V520-15IKL:~$ 
*/
