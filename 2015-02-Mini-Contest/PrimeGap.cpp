// Team Bad's solution to Prime Gap

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int input);

int lower_prime(int num_input) {
    for(int i = num_input - 1; i > 2; i--) {
        if(is_prime(i)) {
            return i;
        }
    }

    return 2;
}

int upper_prime(int num_input) {
    for(int i = num_input + 1; i <= 1299709; i++) {
        if(is_prime(i)) {
            return i;
        }
    }

    return 1299709;
}

int find_range(int lower, int upper) {
    return upper - lower;
}

bool is_prime(int input) {
    bool rv = true;

    for(int i = 2; i <= sqrt(input); i++) {
        if(input % i == 0) {
            rv = false;
            break;
        }
    }

    return rv;
}

int main() {
    int input;
    int upper;
    int lower;
    int range;

    cin >> input;

    while(input != 0) {
        if(!is_prime(input)) {
            upper = upper_prime(input);
            lower = lower_prime(input);
            range = find_range(lower, upper);
            cout << range << endl;
        } else {
            cout << 0 << endl;
        }
        cin >> input;
    }

    return 0;
}
