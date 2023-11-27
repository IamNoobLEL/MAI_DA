#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> dp(n + 1, 1e18); // массив для минимальной стоимости
    std::vector<int> op(n + 1, 0); // массив для операций: -1, /2 или /3
    std::vector<int> prev(n + 1, -1); // массив для предыдущего числа

    dp[1] = 0; // стоимость преобразования числа 1 в 1 равна 0

    for (int i = 2; i <= n; i++) {
        // Если делится на 2
        if (i % 2 == 0 && dp[i / 2] + i < dp[i]) {
            dp[i] = dp[i / 2] + i;
            op[i] = 2;
            prev[i] = i / 2;
        }
        // Если делится на 3
        if (i % 3 == 0 && dp[i / 3] + i < dp[i]) {
            dp[i] = dp[i / 3] + i;
            op[i] = 3;
            prev[i] = i / 3;
        }
        // Операция вычитания
        if (dp[i - 1] + i < dp[i]) {
            dp[i] = dp[i - 1] + i;
            op[i] = 1;
            prev[i] = i - 1;
        }
    }

    // Вывод результата
    std::cout << dp[n] << std::endl;

    std::vector<int> operations;
    int current = n;
    while (current != 1) {
        operations.push_back(op[current]);
        current = prev[current];
    }

    for (int operation : operations) {
        if (operation == 1) std::cout << "-1 ";
        else std::cout << "/" << operation << " ";
    }

    return 0;
}
