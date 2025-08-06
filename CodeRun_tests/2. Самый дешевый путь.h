#pragma once
#include <iostream>
using namespace std;

int prog2() {
    int N;
    int M;
    cin >> N;
    cin >> M;
    int** mas = new int* [N];
    for (int i = 0; i < N; i++) {
        mas[i] = new int[M];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mas[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j != 0) {
                mas[i][j] += mas[i][j - 1];
            }
            if (j == 0 && i != 0) {
                mas[i][j] += mas[i - 1][j];
            }
            if (i != 0 && j != 0) {
                if (mas[i - 1][j] < mas[i][j - 1]) {
                    mas[i][j] += mas[i - 1][j];
                }
                else {
                    mas[i][j] += mas[i][j - 1];
                }
            }
        }
    }
    cout << mas[N - 1][M - 1] << endl;
    
    return 0;
}
