#include "blackjack_hand.h"

#include <iostream>
using namespace std;

//Global Variables for Deck and deckValue
vector<char> deck = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
vector<int> deckValue = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};

//Define Setter Functions
void BlackJack_Hand::createHand(char firstCard, char secondCard){

  //Initialize the Hand List
  vector<char> tempList = {firstCard, secondCard};  
  handList = tempList;

  //Calculate the Value of the Hand
  if (firstCard == 'A' && secondCard == 'A'){

    handValue = 12;

  }
  else if (firstCard == 'A' || secondCard == 'A'){

    if (firstCard == 'A'){

      handValue += 11;

      for (unsigned int i = 0; i < deck.size(); i++){

        if (secondCard == deck.at(i)){

          handValue += deckValue.at(i);

        }
      }

    }
    else {

      handValue += 11;

      for (unsigned int i = 0; i < deck.size(); i++){

        if (firstCard == deck.at(i)){

          handValue += deckValue.at(i);

        }
      }

    }

  }
  else {

    for (unsigned int i = 0; i < deck.size(); i++){
      if (firstCard == deck.at(i)){

        handValue += deckValue.at(i);

      }
      if (secondCard == deck.at(i)){

        handValue += deckValue.at(i);

      }
    }

  }

  //Update the Bust and BlackJack Booleans
  if (handValue > 21){

    isBust = true;

  }
  if (handValue == 21){

    isBlackJack = true;

  }




} //DONE!
void BlackJack_Hand::addCard(char dealtCard){

  //Add the Card to the Hand List
  handList.push_back(dealtCard);
  if (dealtCard == 'A' && handValue + 11 <= 21){
    handValue += 11;
  }
  else{
    for (unsigned int i = 0; i < deck.size(); i++){
      if (dealtCard == deck.at(i)){
        handValue += deckValue.at(i);
      }
    }
  }

  //Update the Bust and BlackJack Booleans
  if (handValue > 21){
    isBust = true;
  }
  if (handValue == 21){
    isBlackJack = true;
  }
} //DONE!

void BlackJack_Hand::resetHand(){

  /*--------------
  This code was written with the aid of ChatGPT;
  'How can I clear a vector list in C++?'
  the generated text suggested using clear function from the
  <vector> library that can make the list into an empty list directly.
  Accessed: May 15 2024
  ---------------  */
  handList.clear();
  handValue = 0;
  isBust = false;
  isBlackJack = false;

} //DONE!

//Define Getter Functions
vector<char> BlackJack_Hand::getHandList(){
  return handList;
} //DONE!
int BlackJack_Hand::getTotalValue(){

  return handValue;

} //DONE!
bool BlackJack_Hand::getIsBust(){

  return isBust;

} //DONE!
bool BlackJack_Hand::getIsBlackJack(){

  return isBlackJack;

} //DONE!
