#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  vector<char> perm;
  perm.push_back('A');
  perm.push_back('B');
  perm.push_back('C');
  perm.push_back('D');

  cout << "The 4! possible permutations with 4 elements:\n";

  sort (perm.begin(), perm.end());

  do {
        cout << perm[0] << " "
             << perm[1] << " "
             << perm[2] << " "
             << perm[3] << endl;
  } while ( next_permutation (perm.begin(),perm.end()) );

  return 0;
}
