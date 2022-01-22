#include <iostream>
#include <string>
using namespace std;
int findMaxCoins(int coin[], int i, int j)
{
    if (i == j)
    {
        return coin[i];
    }
    if (i + 1 == j)
    {
        return max(coin[i], coin[j]);
    }
    int start = coin[i] + min(findMaxCoins(coin, i + 2, j),
                              findMaxCoins(coin, i + 1, j - 1));
    int end = coin[j] + min(findMaxCoins(coin, i + 1, j - 1),
                            findMaxCoins(coin, i, j - 2));
    return max(start, end);
}
int main()
{
    int coin[] = {4, 6, 2, 3};
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << "Maximum coins collected by player is "
         << findMaxCoins(coin, 0, n - 1);
    return 0;
}
