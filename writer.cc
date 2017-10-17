/******************************************************************************
 *
 * Name: Jeffrey Clarke
 *
 * Date: 3/3/17
 *
 * Assignment: Project 3	
 *
 * Purpose: Write a program that generates text by randomly sampling a corpus.
 *
 *****************************************************************************/
#include <iostream>
#include <cstring>
#include <cs111.h>
#include "List.h"

using namespace std;

// Retrieves random character from list of characters occuring after prefix

void charOutput(string& prefix, List& list){
  char value; 
  list.head();  // Current pointer of list is reset
  size_t randval = cs111::random(list.length());
  
  // Advances current position of list until random position (x) is reached
  
  for(size_t x = 0; x < randval; x++) {
    list.advance();
  }

  value = list.retrieve();  // Retrieves value at current position in list
  cout << value;
  prefix = prefix.substr(1) + value;
}

// Finds all instances of prefix in corpus
// Builds list of each subsequent character found after each instance of prefix

void findPrefix(string corpus, string prefix, size_t prefixLength, List& list) {
  list.emptyList();
  
  // Searches corpus for each occurence of prefix
  // Loop terminates at (corpus.length() - prefixLength) before end of corpus
  // Allows for list.insertAfter(corpus[x + prefixLength]) to stay in bounds
  // Help from TA: Bounds
  
  for(size_t x = 0; x < corpus.length() - prefixLength; x++) {  
                                                            
    // If prefix is found, the subsequent character is inserted into a list
    
    if(corpus.substr(x, prefixLength) == prefix) {
      list.insertAfter(corpus[x + prefixLength]);
    }
  }
}

int main(int argc, char** argv) {
  /*
  // Purpose: To test whether List works

  List New;
  char words[11] = {'B', 'U', 'E', 'N', 'O', 'S', ' ', 'D', 'I', 'A', 'S'};

  for(int x = 0; x < 11; x++) {
    New.insertAfter(words[x]);
  }
  List Two;
  Two.copy(New);
  //Two.insertBefore('A');
  //Two.display(cout);
  //New.head();
  //cout <<  << New.currentDefined() << endl;
  char x = Two.retrieve();
  cout << x << endl;
  New.display(cout);
  x = New.retrieve();
  cout << x << endl;

  cout << New.length() << endl;

  for(int y = 0; y < 5; y++) {
    New.remove();
    New.display(cout);
    cout << New.length() << endl;
  }
 */
  ///*
  int prefixLength;
  int textLength;
  string corpus;
  loadCorpus(argc, argv, prefixLength, textLength, corpus);

  // put your code here

  string prefix; 
  List corpusList;  // Creates list to store characters from corpus
  prefix = corpus.substr(0, prefixLength);  // Defines first instance of prefix
  cout << prefix;   // First instance of prefix is output to cout
  
  // Loops until text output is (textLength - prefixLength) in size.
  // Stops at (textLength - prefixLength) due to initial output of prefix.
  // Help from TA: Loop length 
  
  for(int y = 0; y < textLength - prefixLength; y++) { 
    findPrefix(corpus, prefix, prefixLength, corpusList); 
    charOutput(prefix, corpusList);
  }
  cout << endl;
  //*/
}

