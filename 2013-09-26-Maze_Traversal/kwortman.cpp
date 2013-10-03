// Solution for
// 10377 - Maze Traversal
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1318
// Author: Kevin Wortman (kwortman@fullerton.edu)
// Status: Accepted
// 10/3/2013

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

enum Facing { N, E, S, W };

int main() {
  int num_cases;
  cin >> num_cases;
  for (int c = 0; c < num_cases; ++c) {
    int rows, cols;
    cin >> rows >> cols;

    {
      string junk;
      getline(cin, junk);
    }

    vector<vector<bool> > walls(rows, vector<bool>(cols, false));
    for (int row = 0; row < rows; ++row) {
      string line;
      getline(cin, line);
      for (int col = 0; col < cols; ++col) {
	if (line[col] == '*')
	  walls[row][col] = true;
	else
	  assert(line[col] == ' ');
      }
    }

    int row, col;
    cin >> row >> col;
    --row;
    --col;
    Facing facing = N;

    bool quit = false;
    do {
      char ch;
      cin >> ch;

      switch (ch) {
      case 'R':
	switch (facing) {
	case N: facing = E; break;
	case E: facing = S; break;
	case S: facing = W; break;
	case W: facing = N; break;
	}
	break;

      case 'L':
	switch (facing) {
	case N: facing = W; break;
	case E: facing = N; break;
	case S: facing = E; break;
	case W: facing = S; break;
	}
	break;

      case 'F':
	{
	  int new_row = row, new_col = col;

	  switch (facing) {
	  case N: --new_row; break;
	  case E: ++new_col; break;
	  case S: ++new_row; break;
	  case W: --new_col; break;
	  }

	  if (!walls[new_row][new_col]) {
	    row = new_row;
	    col = new_col;
	  }
	}
	break;

      case 'Q':
	quit = true;
	break;

      default:
	break;
      }
    } while (!quit);

    cout << row + 1 << ' ' << col + 1 << ' ';
    switch (facing) {
    case N: cout << 'N'; break;
    case E: cout << 'E'; break;
    case S: cout << 'S'; break;
    case W: cout << 'W'; break;
    }
    cout << endl;

    if (c != (num_cases - 1))
      cout << endl;
  }    
	  
  return 0;
}
