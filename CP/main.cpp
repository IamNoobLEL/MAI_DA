#include <iostream>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <string>
#include <limits>

const int MAX_DOCUMENTS = 10001; // Предполагая, что у нас не более 1000 документов

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::unordered_map<std::string, std::bitset<MAX_DOCUMENTS>> invertedIndex;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            invertedIndex[word].set(i);
        }
    }

    int m;
    std::cin >> m;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < m; ++i) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string word;

        std::bitset<MAX_DOCUMENTS> queryResult;
        queryResult.set();

        bool firstWord = true;
        while (iss >> word) {
            if (firstWord) {
                queryResult = invertedIndex[word];
                firstWord = false;
            } else {
                queryResult &= invertedIndex[word];
            }
        }

        int count = queryResult.count();
        std::cout << count;
        for (int j = 0; j < n; ++j) {
            if (queryResult.test(j)) {
                std::cout << " " << j;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
