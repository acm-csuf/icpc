
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;

// We will put the regions in a circular doubly linked list.
struct Region {
  int id;
  Region *prev, *next;
};

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N == 0)
      break;

    // Allocate Region nodes. Note they are stack-allocated so do not
    // need to be deleted. The id members are initialized here and
    // never change; the prev and next pointers are reinitialized for
    // every iteration of the next loop.
    Region regions[MAX_N];
    for (int i = 0; i < MAX_N; ++i)
      regions[i].id = i+1;

    int m;
    // Exhaustive search for the value of m that makes region 13
    // (Wellington) the last region turned on.
    for (m = 1; m <= N; ++m) {
      // Set up pointers for a doubly linked circular list of N nodes.
      for (int i = 0; i < N; ++i) {
	regions[i].next = &regions[(i+1)%N];
	regions[i].prev = &regions[(i-1+N)%N];
      }

      // Repeatedly delete the m'th element until only one node
      // remains.
      Region* head = &regions[0];
      while (head->next != head) {
	// delete this region
	Region* next = head->next;
	head->prev->next = head->next;
	head->next->prev = head->prev;

	// advance m steps
	head = next; // one step
	for (int i = 0; i < (m-1); ++i) // m-1 steps
	  head = head->next;
      }

      // Region 13 is the only one left, this is the best choice of m.
      if (head->id == 13)
	break;
    }

    cout << m << endl;
  }
  
  return 0;
}
