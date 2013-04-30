// By Cody Kotichas
// 28 Apr 2013

// Happy Telephones
// Determine how many phone calls fit within the constraints

#include <stdio.h>

int main(void) {
  int i, j;          // Loop counters
  int N = 1;         // # of phone calls
  int M = 1;         // # of intervals
  long source;       // Source phone #
  long destination;  // Destination #
  int start;         // Start time of phone call
  int duration;      // Length of phone call
  int stop;          // Stop time of phone call (start + duration)
  int x;             // Start time requested by the police
  int y;             // Duration requested by the police
  int z;             // Stop time of constraint (x + y)
  int matched = 0;   // Counter for # of matched calls

  // Arrays used for holding inputted data
  int sourcedb[10000];
  int destinationdb[10000];
  int startdb[10000];
  int durationdb[10000];

  // Loop the program until user inputs "0 0"
  while (N,M != 0) {
    scanf("%d %d", &N, &M);

    // Store the 4 variables in their respective databases
    for (i=0; i<N; i++) {
      scanf("%d %d %d %d", &source, &destination, &start, &duration);
      sourcedb[i] = source;
      destinationdb[i] = destination;
      startdb[i] = start;
      durationdb[i] = duration;
    }

    // Get constraints from the police
    for (i=0; i<M; i++) {
      matched = 0;
      scanf("%d %d", &x, &y);

      // Loop through each phone # and compare it against the constraints
      for (j=0; j<N; j++) {
        stop = startdb[j] + durationdb[j];
        z = x + y;

        // If it only scratches the edge or is out of bounds, toss it
        if (((z <= startdb[j]) && (z <= stop)) || (x >= startdb[j]) && (x >= stop)) { continue; }
        else { matched++; }
      }

      // Return the number of calls matched and restart
      printf("%d\n", matched);
    }
  }
}
