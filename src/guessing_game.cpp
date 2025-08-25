#include "guessing_game.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

void startGuessingGame(){
  cout << "Welcome to the guessing game!" << endl;
  cout << "The rules are simple." << endl;
  cout << "I am thinking of a number between 1 and 20. You have 3 chances to guess the number in order to win the final piece of the map." << endl;
  //This is the number that the user must guess
  int number = rand() % 20 + 1;
  //This is the number of chances the user has left
  int chances = 3;
  //This variable is to see if the user has won or not
  bool win = false;
  //This number is the users guess
  int userGuess;
  while(chances > 0 && win == false)
  {
    cin >> userGuess;
    if(userGuess < 0 || userGuess > 20)
    {
      cout << "Your guess is out of range." << endl;
      startGuessingGame();
    }
    else if(userGuess == number)
    {
      win = true;
      cout << "You have guessed correct and now I will grant you the final piece of the map." << endl;

    }
    else  {
      chances--;
      cout << "Wrong try again. You have " << chances << " chances left." << endl;
        if (userGuess < number){
          cout << "Hint: Your guess is too low." << endl;
        }
        else if(userGuess > number){
          cout << "Hint: Your guess is too high." << endl;
      }
    }
  }
  if(chances == 0)
  {
    cout << "You have lost the game." << endl;
    startGuessingGame();
  }
}