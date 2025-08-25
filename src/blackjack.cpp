#include "blackjack.h"
#include "blackjack_hand.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<char> deck2 = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
int seedMixer = 0;
bool win = false;
string winner = "UNKNOWN";

void printBlackJackRules(){
  cout << "GOAL: To have a hand value of 21 or as close to 21 as possible without going over." << endl;
  cout << "CARD VALUES: All cards count for their face value. Face cards (J, Q, K) are 10. Face card (A) can be worth either 1 or 11." << endl;
  cout << "RULES:" << endl;
  cout << "1. You will be dealt 2 cards. The dealer also receives 2 cards, but only one is face up." << endl;
  cout << "2. You can choose to hit (draw another card) or stand (stop drawing cards)." << endl;
  cout << "3. You lose if you go over 21 (bust), or if the dealer has a higher hand value than you." << endl;
  cout << "4. You win if you have a higher hand value than the dealer, without going over 21, or you have a hand value of exactly 21 (blackjack)." << endl;
  cout << "5. If you and the dealer have the same hand value, it is a tie." << endl << endl;


  
}
void resetBlackJack(){
  win = false;
  winner = "UNKNOWN";
} //DONE

char GenerateCard(){

  /*------------
  REASON: Need to generate a random card but if using time
  it will return same card since this function will be called several time
  in short time intervals
  ----------------*/
  srand(time(0));
  seedMixer+= 123;
  int randSeed = rand() + seedMixer;
  srand(randSeed);
  int randomIndex = rand() % deck2.size();

  return deck2.at(randomIndex);


} //DONE

void Spacers(string text){

  /*-----------------
  This code was suggested by ChatGPT;
  when prompted 'How to change color of text in console in C++ for nixOS?'
  the generated text helped me write the following code:
  Accessed: May 15 2023

  ----------------*/

  cout <<"\n\n" << "\033[36m" << "========================[" << text << "]=====================" << "\033[0m" << "\n\n";

} //DONE

void DisplayDealerRevealHand(vector<char> dealerRevealHand){

  cout << "──────────────────[Dealer's Card]──────────────────\n\n";

  /* ---------
  The following format to output the card was inspired from this website
  avalible @ https://codereview.stackexchange.com/questions/244714/blackjack-with-card-representation-visuals
  ---------- */

  for (int row = 0; row < 5; row++){

    for(unsigned int col = 0; col < dealerRevealHand.size(); col++){
      if (row == 0){

        cout << "╔══════╗" << setw (10);

      }
      else if (row == 1){

      /* -----------
      This code was written with the aid of chatGPT when prompt
      'how to move console out to beginning of line for C++ on nixOS?'
      the generated text helped me write this folloing code:
      Accessed May 15 2024
      Reason: There was always a indent/space error on the 2nd line so
      I wanted to move the cursor to the beginning so my image would aline.
      ----------- */
        if (col == 0){

          cout << "\r";

        }

        cout << "║ " << dealerRevealHand.at(col) << "    ║";


      }
      else if (row == 4){

        cout << "╚══════╝" << setw(10);

      }
      else {

        cout << "║      ║";

      }  

    }

    cout << endl;// end of row
    cout << "\r";

  }

  cout << "\n\n";

}

void DisplayPlayerHand(vector<char> playerHand){


cout << "──────────────────────[Your Card]──────────────────\n\n";

  /* ---------
  The following format to output the card was inspired from this website
  avalible @ https://codereview.stackexchange.com/questions/244714/blackjack-with-card-representation-visuals
  ---------- */

  for (int row = 0; row < 5; row++){

    for(unsigned int col = 0; col < playerHand.size(); col++){
      if (row == 0){

        cout << "╔══════╗" << setw (10);

      }
      else if (row == 1){

      /* -----------
      This code was written with the aid of chatGPT when prompt
      'how to move console out to beginning of line for C++ on nixOS?'
      the generated text helped me write this folloing code:
      Accessed May 15 2024
      Reason: There was always a indent/space error on the 2nd line so
      I wanted to move the cursor to the beginning so my image would aline.
      ----------- */
        if (col == 0){

          cout << "\r";

        }

        cout << "║ " << playerHand.at(col) << "    ║";


      }
      else if (row == 4){

        cout << "╚══════╝" << setw(10);

      }
      else {

        cout << "║      ║";

      }  

    }

    cout << endl;// end of row
    cout << "\r";

  }
  cout << endl;

}
void DisplayDealerHiddenHand(vector<char> dealerHiddenHand){

  cout << "──────────────────[Dealer's Card]──────────────────\n\n";

  for (int row = 0; row < 5; row++){

    for(unsigned int col = 0; col < dealerHiddenHand.size(); col++){
      if (row == 0){

        cout << "╔══════╗" << setw (10);

      }
      else if (row == 1){

      /* -----------
      This code was written with the aid of chatGPT when prompt
      'how to move console out to beginning of line for C++ on nixOS?'
      the generated text helped me write this folloing code:
      Accessed May 15 2024
      Reason: There was always a indent/space error on the 2nd line so
      I wanted to move the cursor to the beginning so my image would aline.
      ----------- */
        if (col > 0){

          cout << "║░░░░░░║" << setw(10);

        }
        else {
          cout << "\r";
          cout << "║ " << dealerHiddenHand.at(col) << "    ║" << setw(10);

      }


      }
      else if (row == 4){

        cout << "╚══════╝" << setw(10);

      }
      else {

        if (col > 0){

          cout << "║░░░░░░║" << setw(10);

        }
        else {

          cout << "║      ║" << setw(10);

        }

      }  

    }

    cout << endl; // end of row
    cout << "\r";

  }

  cout << "\n\n";

}

void DisplayBoardHidden(BlackJack_Hand player, BlackJack_Hand dealer, string text){
  Spacers(text);
  DisplayDealerHiddenHand(dealer.getHandList());
  DisplayPlayerHand(player.getHandList());
  cout << "Your Value: " << player.getTotalValue() << endl;
} //COMBINE THESE TWO FUNCTIONS (hidden)

void DisplayBoardReveal(BlackJack_Hand player, BlackJack_Hand dealer, string text){
  Spacers(text);
  DisplayDealerRevealHand(dealer.getHandList());
  DisplayPlayerHand(player.getHandList());
} ////COMBINE THESE TWO FUNCTIONS (revealed)

void Result(BlackJack_Hand player, BlackJack_Hand dealer){

  if (player.getIsBust()){
    winner = "Dealer";
  }
  else{
    if(player.getIsBlackJack()){
      if(dealer.getIsBlackJack()){
        winner = "No one";        
      }
      else{
        winner = "You";
        win = true;
      }

    }
    else if(dealer.getIsBust() || dealer.getTotalValue() < player.getTotalValue()){
      winner = "You";
      win = true;
    }
    else if(dealer.getTotalValue() == player.getTotalValue()){
      winner = "No one";
    }
    else{
      winner = "Dealer";
    }


  }



}

bool PlayBlackJack(){

  resetBlackJack();
  seedMixer = 0;

  //CREATE player hand and dealer hand
  BlackJack_Hand player;
  BlackJack_Hand dealer;

  //DEAL CARDS First time
  player.createHand(GenerateCard(), GenerateCard());
  dealer.createHand(GenerateCard(), GenerateCard());

  //DISPLAY DEALER HAND & PLAYER HAND
  DisplayBoardHidden(player, dealer, "GAME START");

  //PLAYER choose Hit or Stand THEN DEALER takes turn
  if (player.getIsBlackJack() == false){

    char userAnswer = '@';
    while (true){
      cout << u8"\U0001F3B4: Would you like to hit or stand? (h/s): ";
      cin >> userAnswer;
      if (userAnswer == 'h' || userAnswer == 's'){
        break;
      }
      else{
        cout << "Invalid Input. Please try again." << endl;
      }
    }
  //NOW user answer is either 'h' or 's'

    if (userAnswer == 'h'){
      while (userAnswer != 's' || player.getIsBust() == true || player.getIsBlackJack() == true){

        //Deal Card
        player.addCard(GenerateCard());

        //DISPLAY BOARD
        DisplayBoardHidden(player, dealer, "YOU HIT");

        //CHECK IF BUST AND IF BLACKJACK
        if (player.getIsBust() || player.getIsBlackJack()){
          break;
        }
        else {

          while (true){
            cout << u8"\U0001F3B4: Would you like to hit or stand? (h/s): ";
            cin >> userAnswer;
            if (userAnswer == 'h' || userAnswer == 's'){
              break;
            }
            else{
              cout << "Invalid Input. Please try again." << endl;
            }
          }

        }       

      }
    }

    //MOVE ON TO DEALER TURN TO GENERATE CARDS
    if (userAnswer == 's' && player.getIsBust() == false){

      while (dealer.getTotalValue() < 17){

        dealer.addCard(GenerateCard());

      }
    }


  }
  else{ //player is blackJack Now move On to dealer turn

    while (dealer.getTotalValue() < 17 && player.getIsBust() == false){

      dealer.addCard(GenerateCard());

    }

  }

  //DISPLAY BOARD
  DisplayBoardReveal(player, dealer, "GAME RESULT");
  cout << "Dealer Value: " << dealer.getTotalValue() << endl;
  cout << "Your Value: " << player.getTotalValue() << endl;

  //CHECK WINNER
  Result(player, dealer);

  if (win == true){
    cout << u8"\U0001F64C: Congratulations! " << winner << " win!" << endl;
  }
  else if(winner == "No one"){
    cout << u8"\U0001F440: It's a tie! " << winner << " win!" << endl;
  }
  else {
    cout << u8"\U0001F631: Sorry! " << winner << " win!" << endl;
  }  

  return win;

}