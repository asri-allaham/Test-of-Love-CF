#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> res(t);

    for (int j = 0; j < t; j++) {
        int n, m, k;
        // The length of the river,
        cin >> n;
        // The distance ErnKor can jump
        cin >> m;
        // The number of meters ErnKor can swim without freezing
        cin >> k;
        // Save the original k
        int temp = k;

        string a;
        // What the river has..
        cin >> a;

        int i = 0;
        bool canCross = false;

        while (i < n) {
            // If ErnKor reaches the end safely
            if (i >= n) {
                canCross = true;
                break;
            }

            // ErnKor cannot land in a segment with a crocodile in any way.
            if (a[i] == 'C') {
                canCross = false;
                break;
            }

            /*
            If he is on the surface (i.e., on the bank or on a log), he can jump forward for no more than m (1≤m≤10)
            meters (he can jump on the bank, on a log, or in the water).
            */
            if (a[i] == 'L' || i == 0) {
                temp = k;
                i += m;  // Jump
                continue;
            }

            // If he is in the water, he can only swim to the next river segment (or to the bank if he is at the n-th meter).
            if (a[i] == 'W') {
                i++;  // Swim forward
                temp--;  // Reduce swimming ability

                if (temp < 0) {
                    canCross = false;
                    break;
                }
            }
        }

        res[j] = canCross ? "YES\n" : "NO\n";
    }

    // Print the results
    for (const string &r : res) {
        cout << r;
    }

    return 0;
}
