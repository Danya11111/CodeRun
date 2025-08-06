#pragma once
#include <iostream>
using namespace std;
int prog3() {
    int N;
    int M;
    cin >> N;
    cin >> M;
    int** mas = new int* [N + 2];
    char** masb = new char* [N];
    for (int i = 0; i < N; i++) {
        masb[i] = new char[M];
    }
    for (int i = 0; i < N + 2; i++) {
        mas[i] = new int[M + 2];
    }
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < M + 2; j++) {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
                mas[i][j] = -1;
            }
        }
    }
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            cin >> mas[i][j];
        }
    }
    //vivod(mas, N, M);
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < M + 1; j++) {
            if (mas[i][j - 1] == -1 && mas[i - 1][j] != -1) {
                mas[i][j] += mas[i - 1][j];
                masb[i - 1][j - 1] = 'D';
            }
            else if (mas[i][j - 1] != -1 && mas[i - 1][j] == -1) {
                mas[i][j] += mas[i][j - 1];
                masb[i - 1][j - 1] = 'R';
            }
            else if (i != 1 && j != 1) {
                if (mas[i][j - 1] > mas[i - 1][j]) {
                    mas[i][j] += mas[i][j - 1];
                    masb[i - 1][j - 1] = 'R';
                }
                else {
                    mas[i][j] += mas[i - 1][j];
                    masb[i - 1][j - 1] = 'D';
                }
            }
        }
    }
    cout << mas[N][M] << endl;
    int cnt = N + M - 2;
    int cnt2 = N + M - 2;
    char* masc = new char[N + M - 2];
    while (cnt != 0) {
        cnt--;
        masc[cnt] = masb[N - 1][M - 1];
        if (masb[N - 1][M - 1] == 'D') {
            N--;
        }
        else {
            M--;
        }
    }
    for (int i = 0; i < cnt2; i++) {
        cout << masc[i] << " ";
    }
    return 0;
}
