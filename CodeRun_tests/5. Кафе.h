#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int prog5()
{
    int n;
    cin >> n;

    if (n == 0) {
        cout << "0\n0 0";
        return 0;
    }

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    int coupons = 0;

    vector<vector<int>> dp(n + 1, vector<int>(102, -1));
    vector<vector<int>> dp_p(n + 1, vector<int>(102, -1));
    if (data[0] > 100) {
        dp[0][1] = data[0];
        coupons++;
    }
    else {
        dp[0][0] = data[0];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 100; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            if (data[i + 1] > 100) {
                if (dp[i + 1][j + 1] == -1 || dp[i + 1][j + 1] > dp[i][j] + data[i + 1]) {
                    dp[i + 1][j + 1] = dp[i][j] + data[i + 1];
                    dp_p[i + 1][j + 1] = 1;
                }
                if (j > 0) {
                    if (dp[i + 1][j - 1] == -1 || dp[i + 1][j - 1] > dp[i][j]) {
                        dp[i + 1][j - 1] = dp[i][j];
                        dp_p[i + 1][j - 1] = -1;
                    }
                }
            }
            else {
                if (dp[i + 1][j] == -1 || dp[i + 1][j] > dp[i][j] + data[i + 1]) {
                    dp[i + 1][j] = dp[i][j] + data[i + 1];
                    dp_p[i + 1][j] = 0;
                }
                if (j > 0) {
                    if (dp[i + 1][j - 1] == -1 || dp[i + 1][j - 1] > dp[i][j]) {
                        dp[i + 1][j - 1] = dp[i][j];
                        dp_p[i + 1][j - 1] = -1;
                    }
                }
            }
        }
    }

    int ans = dp[n - 1][0];
    int idx = 0;
    for (int i = 0; i < 101; i++) {
        if (ans == -1 || (dp[n - 1][i] > -1 && ans >= dp[n - 1][i])) {
            ans = dp[n - 1][i];
            idx = i;
        }
    }

    vector<int> days;
    for (int i = n - 1; i > 0; i--) {
        if (dp_p[i][idx] == 1) {
            coupons++;
            idx--;
        }
        else if (dp_p[i][idx] == -1) {
            idx++;
            days.push_back(i);
        }
    }

    if (days.size() > 0) {
        reverse(days.begin(), days.end());
    }

    cout << ans << '\n';
    cout << coupons - days.size() << ' ' << days.size() << '\n';
    for (auto day : days) {
        cout << day + 1 << ' ';
    }

    return 0;
}