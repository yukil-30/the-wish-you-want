#include <iostream>
#include <vector>
#include <unistd.h>
#include "blackjack.h"
#include "character.h"
#include "hangman.h"
#include "guessing_game.h"

using namespace std;

//Global variables
string userInput;
int gameChoice;
int gamesDone = 0;
int mapPieces = 0;
vector<bool> gamePlayed = {false, false, false};


void startBlackJack() {

  //-------------- Start of Blackjack-------------//


  int BlackJackWins = 0;

  cout <<"\n\n" << "\033[36m" << "========================[" << "Rules" << "]=====================" << "\033[0m" << "\n\n";
  printBlackJackRules();

  cout << u8"\U0001F47B: For you to get the piece of the magical map, you must win the dealer 3 times in Blackjack. Good luck! ";

  cout << "Enter any key to play... ";
  cin >> userInput;

  while (BlackJackWins != 3) {

    bool win = PlayBlackJack();

    if (win == true) {

      BlackJackWins++;
    }
    if (BlackJackWins != 3) {
      cout << endl;
      cout << "You've won " << BlackJackWins << " times." << endl;
      cout << "You still need to win " << 3 - BlackJackWins << " games."
           << endl;
      cout << u8"\U0001F47B: Enter any key to continue next round... ";

      cin >> userInput;
    }
  }

  cout << "Congratulations! You've won the game!" << endl;
  // mapPieces++;
  // cout << "You now have " << mapPieces << " pieces of the map." << endl;
  
}

void chooseGame(int game) {
  if (gameChoice == 1) {
    startBlackJack();
  } 
  else if (gameChoice == 2) {
    startHangman();
  } 
  else if (gameChoice == 3) {
    startGuessingGame();
  } 
  else {
    cout << "Your input must be between 1 and 3. Please try again." << endl;
    cin >> gameChoice;
  }
}

string toLowerword(string inputWord){

  for (unsigned int i = 0; i < inputWord.length(); i++){
    inputWord.at(i) = tolower(inputWord.at(i));
  }

  return inputWord;
}

int main() {
/*---------------------
This code was adapted from:
https://patorjk.com/software/taag/#p=display&f=Slant&t=Welcome
Accessed: May 2024
for the ASCII art
--------------------*/
  cout << " _       __     __" << endl;                      
  cout << "| |     / /__  / /________  ____ ___  ___ " << endl;
  cout << "| | /| / / _ \\/ / ___/ __ \\/ __ `__ \\/ _ \\" << endl;
  cout << "| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/" << endl;
  cout << "|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/ to the Wish You Want!" << endl << endl;
  
  cout << u8"\U0001F47B: Before we begin, may I ask what your name is young fellow?... "; //narrator
  getline(cin, userInput);
  Character mainPlayer;//Created class for main player
  mainPlayer.setName(userInput);
  cout << endl << u8"\U0001F47B: Welcome " << mainPlayer.getName() << "! I am your internal you, the narrator." << endl << endl;
  
  cout << u8"\U0001F47B: You live in Neverest, a small village located in Europe, with two younger siblings, Henry and Elisa. Unfortunely, your mother passed away a few year ago, and haven't hear from your father ever since he went to the Battle of Colchester. You have been responsible in taking care of your two siblings, but things aren't looking well as the money your mother left you guys are almost gone." << endl;
/*-----------------------
  This code was written with the aid of ChatGPT;
  when prompted 'How to bold letter on NixOS using C++?'
  the generated text helped me write the following code for bold text:
  Accessed: May. 2024
-------------------*/
  cout << "\033[1mEnter any key to continue... \033[0m";
  cin >> userInput;
  
  
  cout << endl << "Henry: " << mainPlayer.getName() << ", I'm hungry. We haven't eat in weeks." << endl;
  cout << "Elisa: Me too, I'm starving!!!!" << endl << endl;

  cout << u8"\U0001F47B: Oh no! Your siblings are hungry! What do you choose to do?" << endl;
  cout << "1. Go to the market to search for food." << endl;
  cout << "2. Go to the forest to hunt for food." << endl;
  cout << "Enter your choice: (market/forest)......";

  //Keep asking for input until user enters a valid input
  cin >> userInput;
  userInput = toLowerword(userInput);
  while (userInput != "market" && userInput != "forest") {
    cout << "Invalid input. Please enter 'market' or 'forest': ";
    cin >> userInput;
    userInput = toLowerword(userInput);
  }

  if (userInput == "market"){

    cout << endl << mainPlayer.getName() << ": I'm sorry little ones, but we are out of the money and food that mother left us. I'll try to find some food for you guys. Elisa, make sure to look after your brother while I'm gone.\033[1mEnter any key to continue... \033[0m";
    cin >> userInput;
    cout << endl;  

    cout << u8"\U0001F47B: You are at the market. You see a few people walking around. What do you choose to do?" << endl;
    cout << "1. Talk to the people and ask them for food." << endl;
    cout << "2. Ignore the people and keep walking on the street." << endl;
    cout << "Enter your choice: (talk/ignore)......";
    cin >> userInput;
    userInput = toLowerword(userInput);
    while (userInput != "talk" && userInput != "ignore") {
      cout << "Invalid input. Please enter 'talk' or 'ignore': ";
      cin >> userInput;
      userInput = toLowerword(userInput);
    }
    
  }
  else { //condition for "forest"

    cout << endl << mainPlayer.getName() << ": I'm sorry little ones, but we are out of the money and food that mother left us. I'll try to find some food for you guys. Elisa, make sure to look after your brother while I'm gone.\033[1mEnter any key to continue... \033[0m";
    cin >> userInput;
    cout << endl;  
    
    cout << u8"\U0001F47B: You are at the forest. You see a man sitting by a tree that seems to be hurt. What do you choose to do?" << endl;
    cout << "1. Approach the man and help him" << endl;
    cout << "2. Ignore the man and keep hunting for food." << endl;
    cout << "Enter your choice: (help/hunt)......";

    cin >> userInput;
    userInput = toLowerword(userInput);
    while (userInput != "help" && userInput != "hunt") {
      cout << "Invalid input. Please enter 'help' or 'hunt': ";
      cin >> userInput;
      userInput = toLowerword(userInput);
    }

  }

  if (userInput == "talk"){ //talk to people at the market
    cout << endl << u8"\U0001F47B: You approach a person and ask him for food. He looked at you and said 'I'm sorry, but I don't have any food.' You walk around the whole market but people ignored you or said they didn't have any spare food. \033[1mEnter any key to continue... \033[0m";
    cin >> userInput;
    cout << endl;    

    cout << "Unknown Man: I believe I can guide you young fellow. My name is Jack by the way. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You are not to sure whether he is trustworthy or not. But there are no choice now as your two younger siblings are in hunger. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: A legend says that there is a magical tree that can grant you any one wish. This tree only appear every 25 years and luckily, this year is another 25 years. You must find the three pieces of the enchanting map and it will bring you to the forest where the magical tree is located." << endl;

    cout << "\033[1mEnter any key to continue... \033[0m";
    cin >> userInput;

    cout << endl << "Jack: 25 years ago, when I was a young lad, my ailments were cured from this map. Now it is your turn. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You certainly had to agree to take on this adventure for your two younger siblings and asked Jack the way to find the pieces to the map. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: You must complete 3 games and in any order you like. Let the journey begin!" << endl << endl;    
    
  }
  else if (userInput == "ignore"){ //ignore people at the market
    cout << endl << u8"\U0001F47B: You ignore the people and keep walking on the street. From no where, you hear a voice calling out to you. You turn around and see an old man. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Unknown Man: I believe I can guide you young fellow. My name is Jack by the way. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You are not to sure whether he is trustworthy or not. But there are no choice now as your two younger siblings are in hunger. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: A legend says that there is a magical tree that can grant you any one wish. This tree only appear every 25 years and luckily, this year is another 25 years. You must find the three pieces of the enchanting map and it will bring you to the forest where the magical tree is located. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << endl << "Jack: 25 years ago, when I was a young lad, my ailments were cured from this map. Now it is your turn. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You certainly had to agree to take on this adventure for your two younger siblings and asked Jack the way to find the pieces to the map. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: You must complete 3 games and in any order you like. Let the journey begin!" << endl << endl;  
      
  }
  else if (userInput == "help"){ //help the man by the tree
    cout << endl << u8"\U0001F47B: You approach the man and help him. He looked up at you and said 'Thank you young fellow, I'm glad you could help me.' \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  
    cout << "Unknown Man: My name is Jack. What brings you here to the forest he ask you? \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You tell him about your situation and the reason you are here. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: I believe I can help you young fellow. A legend says that there is a magical tree that can grant you any one wish. This tree only appear every 25 years and luckily, this year is another 25 years. You must find the three pieces of the enchanting map and it will bring you to the forest where the magical tree is located." << endl;

      cout << "\033[1mEnter any key to continue... \033[0m";
      cin >> userInput;

      cout << endl << "Jack: 25 years ago, when I was a young lad, my ailments were cured from this map. Now you can be the one. \033[1mEnter any key to continue... \033[0m";
        cin >> userInput;
        cout << endl;  

      cout << u8"\U0001F47B: You certainly had to agree to take on this adventure for your two younger siblings and asked Jack on the way to find the pieces to the map. \033[1mEnter any key to continue... \033[0m";
        cin >> userInput;
        cout << endl;  

      cout << "Jack: You must complete 3 games and in any order you like. Let the journey begin!" << endl << endl;  


  }
  else if (userInput == "hunt") {  //continue hunting
    cout << endl << u8"\U0001F47B: You ignore the man and keep hunting for food. However, the man called out to you for help so you decided to help him. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Unknown Man: My name is Jack. Thank you young fellow for helping me. There are barely anyone in this forest, what brings you here? \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You tell him about your situation and the reason you are here. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: I believe I can help you young fellow. A legend says that there is a magical tree that can grant you any one wish. This tree only appear every 25 years and luckily, this year is another 25 years. You must find the three pieces of the enchanting map and it will bring you to the forest where the magical tree is located." << endl;

    cout << "\033[1mEnter any key to continue... \033[0m";
    cin >> userInput;

    cout << endl << "Jack: 25 years ago, when I was a young lad, my ailments were cured from this map. Now you can be the one. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << u8"\U0001F47B: You certainly had to agree to take on this adventure for your two younger siblings and asked Jack on the way to find the pieces to the map. \033[1mEnter any key to continue... \033[0m";
      cin >> userInput;
      cout << endl;  

    cout << "Jack: You must complete 3 games and in any order you like. Let the journey begin!" << endl << endl; 
    
  }
  cout << "1. Blackjack \n2. Hangman \n3. Guessing Game" << endl;

  //Keep playing until all games have been played
  while (gamePlayed.at(0) == false || gamePlayed.at(1) == false || gamePlayed.at(2) == false){
    
    cout << u8"\U0001F47B: INPUT THE NUMBER OF WHICH GAME YOU WANT TO PLAY (1/2/3)......";
    //Keep asking for input until user enters a valid input
    cin >> gameChoice;
    while (gameChoice != 1 && gameChoice != 2 && gameChoice != 3) {
      cout << u8"\U0001F47B: Invalid input. Please enter (1/2/3).... ";
      cin >> gameChoice;
    }
    for (int i = 0; i < gamePlayed.size(); i++){
  
      if (gamePlayed.at(gameChoice - 1) == false){
  
        gamePlayed.at(gameChoice - 1) = true;
        chooseGame(gameChoice);
        mapPieces++;
        cout << endl << u8"\U0001F47B: You have " << mapPieces << " pieces of the map." << endl;
        break;
      }
      else if (gamePlayed.at(gameChoice - 1) == true){
        cout << endl << u8"\U0001F47B: You have already played this game. Please choose another game." << endl;
        break;
      }
    }

    
  }

  
  // cin >> gameChoice;
  // for(int i = 1; i <= 3; i++)
  // {
  //   if(gameChoice == i)
  //   {
  //     chooseGame(gameChoice);
  //     mapPieces++;
  //     cout << "You have " << mapPieces << " pieces of the map." << endl;
  //     cin >> gameChoice;
  //   }
  //   else
  //   {
  //     cout << "The number you input must be in the order of the corresponding game. Please try again." << endl;
  //     cin >> gameChoice;
  //   }
  // }

  
  

cout << u8"\U0001F47B: Congratulations!. You've completed all the games and collected the 3 pieces of the magical map. You pieced the map together and in an instance, a portal appears in front of you and you see the tree. \033[1mEnter any key to continue... \033[0m";
  cin >> userInput;
  cout << endl;  

cout << u8"\U0001F47B: You enter the portal and walk towards the tree in disbelief. You can't believe your eyes. Everything that Jack said was true! \033[1mEnter any key to continue... \033[0m";
  cin >> userInput;
  cout << endl;  

cout << u8"\U0001F47B: You are now under the tree and you start wishing. What is your wish?" << endl << endl;
cout << "Enter your wish: ";

/*-------------------
This code was taken from:
https://cplusplus.com/forum/beginner/39549/
because the getline keeps getting skipped and not allowing
the user to input their wish.
The cin.ingore() allows the empty space to be skipped so getline can work
-------------------*/
cin.ignore();
getline(cin, userInput);

cout << endl << "You have wished for: " << userInput << endl;
usleep(1000000);
cout << endl << "May all your wishes come true!" << endl;
cout << "You have completed the game!" << endl << endl;

/*----------------------
  The ASCII art is taken from:
  'https://www.textartcopy.com/congratulations-word-art.html'
--------------------*/
cout << "  ░█████╗░░█████╗░███╗░░██╗░██████╗░██████╗░░█████╗░████████╗░██████╗" << endl;
cout << "  ██╔══██╗██╔══██╗████╗░██║██╔════╝░██╔══██╗██╔══██╗╚══██╔══╝██╔════╝" << endl;
cout << "  ██║░░╚═╝██║░░██║██╔██╗██║██║░░██╗░██████╔╝███████║░░░██║░░░╚█████╗░" << endl;
cout << "  ██║░░██╗██║░░██║██║╚████║██║░░╚██╗██╔══██╗██╔══██║░░░██║░░░░╚═══██╗" << endl;
cout << "  ╚█████╔╝╚█████╔╝██║░╚███║╚██████╔╝██║░░██║██║░░██║░░░██║░░░██████╔╝" << endl;
cout << "  ░╚════╝░░╚════╝░╚═╝░░╚══╝░╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═════╝░" << endl << endl;

cout << "Have a GREAT SUMMMMMER!!" << u8"\U0001F47B" << endl;

  return 0;
}