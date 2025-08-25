#ifndef BLACKJACK_HAND_H
#define BLACKJACK_HAND_H


#include <iostream>
#include <vector>
using namespace std;

class BlackJack_Hand {

private:
  vector<char> handList;
  int handValue = 0;
  bool isBust = false;
  bool isBlackJack = false;

public:

  // void GenerateHand(char firstCard, char secondCard);

  // void AddCard_and_UpdateValueList(char card);

  // int GetSumValue(vector<int> playingHand);

  //Declare Setter Functions
  void createHand(char firstCard, char secondCard);
  void addCard(char dealtCard);
  void resetHand();

  //Declare Getter Functions
  vector<char> getHandList();
  int getTotalValue();
  bool getIsBust();
  bool getIsBlackJack();


};



#endif /* BLACKJACK_HAND_H */