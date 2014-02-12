#include <iostream>

using namespace std;

const int COIN_TYPE = 8;
int coins[COIN_TYPE] = {10, 20, 50, 100, 200, 1, 2, 5};
int coinways[201][COIN_TYPE];
// Top-down DP
int coinsum(int n) {
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j < COIN_TYPE; j++)
            coinways[i][j] = 0;
    for (int i = 0; i < COIN_TYPE; i++)
        coinways[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < COIN_TYPE; j++) {
            int x = i - coins[j] >= 0 ? coinways[i-coins[j]][j] : 0;
            int y = j >= 1 ? coinways[i][j-1] : 0;
            coinways[i][j] = x + y;
        }
    }
    return coinways[200][COIN_TYPE-1];
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    cout << coinsum(n) << endl;
    return 0;
}
