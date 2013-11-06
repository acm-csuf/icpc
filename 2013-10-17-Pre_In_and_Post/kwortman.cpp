// Solution for
// 10701 - Pre, in and post
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=19&page=show_problem&problem=1642
// Author: Kevin Wortman (kwortman@fullerton.edu)
// Status: Accepted
// 11/5/2013

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Binary tree node.
struct Node {
  Node(char _letter, auto_ptr<Node> _left, auto_ptr<Node> _right)
    : letter(_letter),
      left(_left),
      right(_right) { }

  void postorder() {
    if (left.get())
      left->postorder();
    if (right.get())
      right->postorder();
    cout << letter;
  }

  char letter;
  auto_ptr<Node> left, right;
};

// Recursive algorithm.
auto_ptr<Node> parse(string& preorder,
		     string::const_iterator inorder_begin,
		     string::const_iterator inorder_end) {
  // Base case: empty substring, return NULL node.
  if (inorder_begin == inorder_end)
    return auto_ptr<Node>();
  
  // Recursive case: build the root node of a nonempty subtree. The
  // root character must be the first element of the preorder string.
  char root = preorder[0];
  preorder.erase(preorder.begin());

  // Find the root character in the inorder string. Our left subtree
  // holds everything before the root character, and the right subtree
  // everything after.
  string::const_iterator root_pos = find(inorder_begin, inorder_end, root);

  // Build each subtree recursively.
  return auto_ptr<Node>(new Node(root,
				 parse(preorder, inorder_begin, root_pos),
				 parse(preorder, root_pos + 1, inorder_end)));
}

int main() {
  int C;
  for (cin >> C; C > 0; C--) {
    int N;
    string preorder, inorder;
    cin >> N >> preorder >> inorder;

    auto_ptr<Node> root(parse(preorder, inorder.begin(), inorder.end()));

    root->postorder();
    cout << endl;
  }
  return 0;
}
