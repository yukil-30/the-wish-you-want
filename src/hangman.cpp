#include "hangman.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

void Rules()
{
  cout << "Welcome to Hangman!" << endl;
  cout << "Once you choose a topic, will have to guess the term. You have 6 guesses. If you run out of guesses, you must restart. If you guess the term correctly. You win and can continue your journey." << endl;
  cout << "The topic is Town Name" << endl;
  cout << "HINT: At the beginning of the game, the answer was mentioned" << endl;
}


void startHangman()
{
  bool won = false;
  int guesses = 6;
  string const answer = "NEVEREST";
  char letter; //user guessing letter
  vector<char> everyLetter = {'N', 'E', 'V', 'E', 'R', 'E', 'S', 'T'};
  vector<bool> lettersGuessed = {false, false, false, false, false, false, false, false};
  cout << "The length of the word is " << answer.length() << " letters." << endl;
  cout << "You have " << guesses << " guesses." << endl;


  while((won == false) && (guesses > 0))
  {
    cout << "Guess a letter: ";
    cin >> letter;
    letter = toupper(letter);
    bool correctGuess = false;

    for(int i = 0; i < answer.length(); i++)
    {
      if(letter == everyLetter.at(i))
      {
        lettersGuessed.at(i) = true; 
        correctGuess = true;
      }
    }
    if(correctGuess == false)
    {
      guesses--;
      cout << "You have " << guesses << " guesses left." << endl;
    }

    for(int i = 0; i < lettersGuessed.size(); i++)
    {
      if(lettersGuessed.at(i) == true)
      {
        cout << everyLetter.at(i);
      }
      else
      {
        cout << "_";
      }
    }
    cout << endl;
    won = true;
    for(int i = 0; i < lettersGuessed.size(); i++)
    {
      if(lettersGuessed.at(i) == false)
      {
        won = false;
        break;
      }
    }
    if(won == true)
    {
      cout << "You guessed the word correctly! Go on and continue your journey." << endl;
      cout << "You now have gained another piece of the map." << endl;
    }
    if(guesses == 0)
    {
      cout << "You ran out of guesses and failed the challenge. Don't be discouraged, try again." << endl;
      startHangman();
    }
 }
}