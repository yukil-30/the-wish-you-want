#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <vector>
using namespace std;

/* The following rules for Black Jack are referenced from the following 
website available @ https://www.casino.org/blackjack/how-to-play */

//Goal of the Game: Main Character must win 3 rounds of Black Jack to pass the level/game.

//Declare Functions & Global Variables
  void printBlackJackRules();
  char GenerateCard();
  void Spacers();
  void DisplayDealerRevealHand(vector <char>dealerRevealHand); //reveals dealer's second card
  void DisplayPlayerHand(vector<char> playerHand); //displays player's hand
  void DisplayDealerHiddenHand(vector<char> dealerHiddenHand);
  bool PlayBlackJack(); //play the game of blackjack


#endif
