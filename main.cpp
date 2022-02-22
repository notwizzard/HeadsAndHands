#include <iostream>
#include <vector>
#include <experimental/random>
#include <algorithm>
#include <chrono>

#define c_minVectorLength 10
#define c_minRandomValue 1
#define c_maxRandomValue 1000

using namespace std;

int main() {
    int n;
    cin >> n;

    vector <vector <int>> vectorOfVectors(n);
    vector <int> vectorsSize(n);

    // fill vector of sizes with values from c_minVectorLength to (c_minVectorLength + n)
    for (int i = 0; i < vectorsSize.size(); i++) {
        vectorsSize[i] = c_minVectorLength + i;
    }

    // shuffle sizes
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(vectorsSize.begin(), vectorsSize.end(), default_random_engine(seed));

    // resize vectors to value from shuffled vector of sizes
    // fill vectors with random values from c_minRandomValue to c_maxRandomValue
    for (int i = 0; i < n; i++) {
        vectorOfVectors[i].resize(vectorsSize[i]);
        for (int &element : vectorOfVectors[i]) {
            element = experimental::randint(c_minRandomValue, c_maxRandomValue);
        }
    }

    // sort vectors
    for (int i = 0; i < n; i++) {
        if (i % 2)
            sort(vectorOfVectors[i].begin(), vectorOfVectors[i].end());
        else
            sort(vectorOfVectors[i].rbegin(), vectorOfVectors[i].rend());
    }

    // print vectors
    for (int i = 0; i < n; i++) {
        cout << i + 1;
        if (i % 10 == 1 || i % 10 == 2)
            cout << "d array: ";
        else
            cout << "th array: ";
        for (int value : vectorOfVectors[i]) {
            cout << value << " ";
        }
        cout << endl;
    }
}
