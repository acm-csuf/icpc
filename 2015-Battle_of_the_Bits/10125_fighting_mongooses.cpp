#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int numElements;
    long int originalMax = -536870913;
    while (cin >> numElements) {
        if (numElements <= 0 || numElements > 1000) break;

        long int *s;
        s = new long int[numElements];

        long int max = originalMax;

        for (int i = 0; i < numElements; i++) {
            cin >> s[i];
        }

        sort(s, s + numElements);

        for (int i = 0; i < numElements; i++) {
            for (int j = i; j < numElements; j++) {
                if (j == i) continue;

                for (int k = j; k < numElements; k++) {
                    if (k == i || k == j) continue;

                    long int sum = s[i] + s[j] + s[k];

                    if (sum <= max) continue;

                    if (sum > s[numElements - 1]) continue;

                    for (int z = numElements - 1; z >= 0; z--) {
                        if (z == i || z == j || z == k) continue;

                        if (sum == s[z]) {
                            max = sum;
                        }
                    }
                }
            }
        }

        if (max == originalMax) {
            cout << "no solution" << endl;
        } else {
            cout << max << endl;
        }
    }

    return 0;
}
