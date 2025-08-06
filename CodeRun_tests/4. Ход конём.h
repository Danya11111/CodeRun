#pragma once
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

int hod(int x, int y, int xx, int yy) {
    if (x > xx || y > yy) {
        return 0;
    }
    if (x == xx && y == yy) {
        return 1;
    }
    if (memo[x][y] != -1) {
        return memo[x][y];
    }
    int ways = hod(x + 2, y + 1, xx, yy) + hod(x + 1, y + 2, xx, yy);

    memo[x][y] = ways;
    return ways;
}

int prog4() {
    int x, y;
    cin >> x >> y;

    memo = vector<vector<int>>(x + 1, vector<int>(y + 1, -1));

    int cnt = hod(1, 1, x, y);
    cout << cnt << endl;

    return 0;
}
