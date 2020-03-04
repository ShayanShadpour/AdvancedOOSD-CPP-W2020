///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Filename: a1.cpp
//Author: Shayan Shadpour
//Student Number: 104399871
//Created on: 2020/01/27
//Description: Program that reads in raw character data from standard input and formats the output.
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip> // for std::noskipws

using namespace std; //using the standard namespace

int main()
{
     bool is_within_double_quotes = false; //indicator which lets the program know if the current character is enclosed within double quotes or not. It begins at a false value in order to process text correctly.
     char byte; //variable which stores the currently processing character.
     while (cin >> noskipws >> byte) //loop which takes user input and processes it one character at a time by storing it into byte. It also allows whitespace.
     {
          switch (byte) { //used switch case statement, since some characters must be treated differently

          case '.': // the actions for this case are the same actions when processing the ( , ? ' -  )characters
               if (is_within_double_quotes == false) { //checking if the symbol is within double quotes
                    cout << ' '; //the character is replaced by whitespace if it is not within double quotes
                    break;
               }
               else {
                    cout << byte; //if the character is within double quotes, it remains unchanged
                    break;
               }

          case ',':
               if (is_within_double_quotes == false) {
                    cout << ' ';
                    break;
               }
               else {
                    cout << byte;
                    break;
               }


          case '?':
               if (is_within_double_quotes == false) {
                    cout << ' ';
                    break;
               }
               else {
                    cout << byte;
                    break;
               }


          case '\'':
               if (is_within_double_quotes == false) {
                    cout << ' ';
                    break;
               }
               else {
                    cout << byte;
                    break;
               }

          case '-':
               if (is_within_double_quotes == false) {
                    cout << ' ';
                    break;
               }
               else {
                    cout << byte;
                    break;
               }


          case '"': //if the character being process is a double quote, the boolean variable "is_within_double_quotes" is toggled.
               is_within_double_quotes = !is_within_double_quotes;
               cout << byte;
               break;

          default:
               cout << byte;
               break;
          }
          
     }

     return 0;
}