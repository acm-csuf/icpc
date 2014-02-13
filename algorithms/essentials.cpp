// ============================================================================
// File: essentials.cpp
// ============================================================================
// Author: Brittany Parker
// Date: 02/13/2014
// Description:
//		Explains input and output redirection using a simple program.
//
// Outline:
//		Program - simple string class example
//		Introduction
//		Read_Input_Until_EOF
//			Compile_In_Command_Line
//		Input/Output_Redirecting
//		Diff
//		Parse_Input
//
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// The following program is used for explanation:

int main(void)
{
	string mystring;

	// Read input one word at a time.
	// Stops looping when string contains EOF.
	while(cin >> mystring)
		{
		cout << mystring << endl;
		}

	return 0;
}

// == Introduction ============================================================
//
// Here's something cool. You can give a program a file without using file I/O!
// That's right; no opening and closing files or any extra lines of code in
// your program. Let's look at the program above.
//
// == Read_Input_Until_EOF ====================================================
//
// If you are using the command line to enter input, this program will read to 
// standard input (stdin) and standard output (stdout), which is the command
// line. It waits for input from the stdin. Once you type something and press
// enter, the program will read each "word" in a loop until it reaches the end
// of the line (where you pressed enter), and it will print each "word" out to
// stdout followed by a new line. For example,
//
// ---- Compile_In_Command_Line -----------
//
// $ g++ myfile.cpp -o name
// $ ./name
// >1 2 3
// 1
// 2
// 3
//
// Then the program waits for you to enter something again. If you press
// "cntrl + c" the program will end. If you press "cntrl + d" the program also
// ends. The difference is that "cntrl + d" represents the EOF (end of file)
// character which is read by the program and tells the while loop to stop
// looping, while "cntrl + c" actually terminates the program no matter what it
// is doing.
//
// In short, the program is waiting for the EOF character to end. This will
// work great for files too even without explicit file I/O. This is because the
// EOF character is at the end of every file.
//
// == Input/Output_Redirecting ================================================
//
// How you do this, is with redirection operators (i.e '<' and '>'). Let's see
// an example:
//
// $ g++ myfile.cpp -o name
// $ ./name < in.txt				// reads from in.txt; writes to stdout
// $ ./name > out.txt				// reads from stdin; writes to out.txt
// $ ./name < in.txt > out.txt 		// reads from in.txt; writes to out.txt
// 
// Your program simply needs to read input from stdin until it encounters
// the EOF character.
//
// == Diff ====================================================================
//
// Another useful thing is quickly checking your output against correct output.
// $ diff output.txt correctOutput.txt
//
// This lists all the differences between the files which is a really easy way
// to check your work without having to do so manually/visually.
//
// == Parse_Input =============================================================
// 
// "parserinput.cpp" serves as a simple example of the following. Please see
// "parsing_csv.cpp" and/or "stringparser.cpp" for further usage.
//		strings
//		stringstreams
//		vectors
//
// ============================================================================