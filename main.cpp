#include <iostream>
#include <string>
using namespace std;

struct nodeStack {
  char c;
  nodeStack* next;
};
typedef nodeStack* Stack;

Stack push( Stack stack, char element ) {
  Stack newNode = new nodeStack;
  newNode->c    = element;
  newNode->next = stack;
  return newNode;
}
void pop( Stack& stack ) {
  if( stack != NULL ) {
    Stack pointer = stack;
    stack         = stack->next;
    delete( pointer );
  }
}
char top( Stack stack ) {
  return stack->c;
}
char firstChar( string& text ) {
  char character = text.at( 0 );
  text           = text.substr( 1, text.length( ) - 1 );
  return character;
}
bool checkParenthesis( Stack& symbols, string text ) {
  while( text.length( ) ) {
    char character = firstChar( text );
    if( character == '(' || character == '[' || character == '{' ) {
      symbols = push( symbols, character );
    } else if( character == ')' || character == ']' || character == '}' ) {
      if( ( character == ')' && top( symbols ) != '(' ) ||
          ( character == ']' && top( symbols ) != '[' ) ||
          ( character == '}' && top( symbols ) != '{' ) ) {
        return false;
      } else
        pop( symbols );
    }
  }
  if( symbols != NULL ) return false;
  else
    return true;
}
int main( ) {
  Stack symbols = NULL;
  string text   = "{()[]}";
  if( checkParenthesis( symbols, text ) ) {
    cout << "El orden es correcto" << endl;
  } else {
    cout << "El orden es incorrecto" << endl;
  }
  cout << text << endl;
}