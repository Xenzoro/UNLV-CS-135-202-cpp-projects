/*
Name: Jacob Martinez,
NSHE ID#5007553403, 1008,
ASSIGNMENT
FA Assignment 3.
Description: a blackjack game
Input: values that are used for calculating who wins
Output: the game as a whole...

 I Apologize for random breaks in code...
 CodeGrade does not want code longer than 74 characters.
*/
#include <iostream>
using namespace std;

int main() {
    string answer = " ";
    int playerScore1 (0), playerScore2 (0), p1CardsChosen (0),
        p2CardsChosen (0), p1RandomCard (0), p2RandomCard (0);

    cout << "*******************************************\n"
         << "**   Welcome to CS135’s Blackjack game!  **\n"
         << "*******************************************\n\n";
    cout << "Player 1 Score: " << playerScore1 << endl
         << "Player 2 Score: " << playerScore2 << endl << endl;

    cout << "Dealer: Player 1, how many cards would you like to choose?";
    cin >> p1CardsChosen;
    //this switch makes a branch for each potential card possibility.
    switch (p1CardsChosen) {
        case 1 :
            // player can have minimum of 2 cards...
            cout << endl << "please, choose a random card for Player 1:";
            /* used a "score system" where "new" cards are added to a
             * pool where the score increments after each card
             * is taken.
             */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            playerScore1 += p1RandomCard;

        cout << endl
        << "Player 1, you need to choose another card." << endl;
            cout << endl << "Please, choose a random card for Player 1:";
            /* used a "score system" where "new" cards are added to a
             * pool where the score increments after each card
             * is taken.
             */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p1RandomCard){
                case 13:
                    p1RandomCard = 10;
                    break;
                case 14:
                    p1RandomCard = 11;
                    break;
                case 11:
                    p1RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore1 += p1RandomCard;
            //asked because player(s) can have up to three cards.
        cout << endl
        << "Dealer: Player 1, would you like to choose another card?";
            cin >> answer;
            if (answer == "Yes" || answer == "yes") {
                //optional third card choice.
        cout << endl << "Please, choose a random card for Player 1: ";
                /* used a "score system" where "new" cards are added to a
                     * pool where the score increments after each card
                     * is taken.
                     */
                cin >> p1RandomCard;
                /*switches are used to check for different possibilities
             * of answers.
            */
                switch (p1RandomCard){
                    case 13:
                        p1RandomCard = 10;
                        break;
                    case 14:
                        p1RandomCard = 11;
                        break;
                    case 11:
                        p1RandomCard = 10;
                        break;
                    default:
                        break;
                }
                playerScore1 += p1RandomCard;
            }
            break;

        case 2 :
            //Done twice because of two cards chosen.
        cout << endl << "Please, choose a random card for player 1: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p1RandomCard){
                case 13:
                    p1RandomCard = 10;
                    break;
                case 14:
                    p1RandomCard = 11;
                    break;
                case 11:
                    p1RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore1 += p1RandomCard;
        cout << endl
        << "Please, choose a random card for player 1: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
            * of answers.
            */
            switch (p1RandomCard){
                case 13:
                    p1RandomCard = 10;
                    break;
                case 14:
                    p1RandomCard = 11;
                    break;
                case 11:
                    p1RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore1 += p1RandomCard;
            //asked because player(s) can have up to three cards.
        cout << endl
        << "Dealer: Player 1, would you like to choose another card?";
            cin >> answer;
            if (answer == "Yes" || answer == "yes") {
                //optional third card choice.
                cout << "Please, choose a random card for Player 1: ";
                /* used a "score system" where "new" cards are added to a
                     * pool where the score increments after each card
                     * is taken.
                     */
                cin >> p1RandomCard;
                /*switches are used to check for different possibilities
             * of answers.
            */
                switch (p1RandomCard){
                    case 13:
                        p1RandomCard = 10;
                        break;
                    case 14:
                        p1RandomCard = 11;
                        break;
                    case 11:
                        p1RandomCard = 10;
                        break;
                    default:
                        break;
                }
                playerScore1 += p1RandomCard;
            }
            break;
        case 3 :
            // asked three times because three cards chosen.
        cout << endl << "Please, choose a random card for player 1: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p1RandomCard){
                case 13:
                    p1RandomCard = 10;
                    break;
                case 14:
                    p1RandomCard = 11;
                    break;
                case 11:
                    p1RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore1 += p1RandomCard;
        cout << endl
        << "Please, choose a random card for player 1: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p1RandomCard){
                case 13:
                    p1RandomCard = 10;
                    break;
                case 14:
                    p1RandomCard = 11;
                    break;
                case 11:
                    p1RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore1 += p1RandomCard;
        cout << endl
        << "Please, choose a random card for player 1: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p1RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p1RandomCard){
                case 13:
                    p1RandomCard = 10;
                    break;
                case 14:
                    p1RandomCard = 11;
                    break;
                case 11:
                    p1RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore1 += p1RandomCard;
            break;

        default :
            cout << "You Messed up Dawg";
            break;
    }
    cout << endl
    << "Dealer: Player 2, how many cards would you like to choose?";
    /* used a "score system" where "new" cards are added to a
    * pool where the score increments after each card
    * is taken.
    */
    cin >> p2CardsChosen;
        //this switch makes a branch for each potential card possibility.
    switch (p2CardsChosen) {
        case 1 :
            // player can have minimum of 2 cards...
            cout << endl <<"please, choose a random card for Player 2:";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;

        cout << endl
        << "Player 2, you need to choose another card.\n";
            cout << endl << "Please, choose a random card for Player 2:";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;
            //asked because player(s) can have up to three cards.
        cout << endl
        << "Dealer: Player 2, would you like to choose another card?";
            cin >> answer;
            if (answer == "Yes" || answer == "yes") {
                //optional third card choice.
            cout<< endl
            << "Please, choose a random card for Player 2: ";
                /* used a "score system" where "new" cards are added to a
                * pool where the score increments after each card
                * is taken.
                */
                cin >> p2RandomCard;
            /*switches are used to check for
             * different possibilities
             * of answers.
            */
                switch (p2RandomCard){
                    case 13:
                        p2RandomCard = 10;
                        break;
                    case 14:
                        p2RandomCard = 11;
                        break;
                    case 11:
                        p2RandomCard = 10;
                        break;
                    default:
                        break;
                }
                playerScore2 += p2RandomCard;
            }
            break;

        case 2 :
            //Done twice because of two cards chosen.
        cout << endl
        << "Please, choose a random card for player 2: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;

            cout << endl
            << "Please, choose a random card for player 2: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;
            //asked because player(s) can have up to three cards.
        cout << endl
        << "Dealer: Player 2, would you like to choose another card?";
            cin >> answer;
            if (answer == "Yes" || answer == "yes") {
                //optional third card choice.
        cout << endl << "Please, choose a random card for Player 2: ";
                /* used a "score system" where "new" cards are added to a
                * pool where the score increments after each card
                * is taken.
                */
                cin >> p2RandomCard;
                /*switches are used to check for different possibilities
             * of answers.
            */
                switch (p2RandomCard){
                    case 13:
                        p2RandomCard = 10;
                        break;
                    case 14:
                        p2RandomCard = 11;
                        break;
                    case 11:
                        p2RandomCard = 10;
                        break;
                    default:
                        break;
                }
                playerScore2 += p2RandomCard;

            }
            break;
        case 3 :
            // asked three times because three cards chosen.
        cout << endl << "Please, choose a random card for player 2: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;

        cout << endl << "Please, choose a random card for player 2: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;
        cout << endl << "Please, choose a random card for player 2: ";
            /* used a "score system" where "new" cards are added to a
            * pool where the score increments after each card
            * is taken.
            */
            cin >> p2RandomCard;
            /*switches are used to check for different possibilities
             * of answers.
            */
            switch (p2RandomCard){
                case 13:
                    p2RandomCard = 10;
                    break;
                case 14:
                    p2RandomCard = 11;
                    break;
                case 11:
                    p2RandomCard = 10;
                    break;
                default:
                    break;
            }
            playerScore2 += p2RandomCard;
            break;
        default :
            //playful easter-egg
            cout << endl << "You Messed up Dawg";
            break;
    }
    cout << endl << endl << "Player 1 Score: " << playerScore1 << endl
                 << "Player 2 Score: " << playerScore2 << endl;
        // potential score outcomes...
    if ((playerScore2 > 21) and (playerScore1 > 21)){
        cout << endl <<"Sorry, no one wins, both players busted.";

    }else if(playerScore1 == playerScore2){
        cout << endl <<"Both player 1 and player 2 tie.";

    }else if (playerScore2 <= 21 and (playerScore1 > 21)){
        cout << endl <<"Player 2 wins because player 1 busted.";

    }else if ((playerScore1 <= 21) and (playerScore2 > 21)){
        cout << endl <<"Player 1 wins because player 2 busted.";

    }else if ((playerScore1 < playerScore2)
    and (playerScore1 <= 21 ) and (playerScore2 < 21)){
    cout << endl << "player 2 wins with a higher score than player 1.";

    }else if ((playerScore2 < playerScore1) and (playerScore2 <= 21)
    and (playerScore1 < 21)){
    cout << endl << "player 1 wins with a higher score than player 2.";
    }
    cout << endl <<"** Program Terminated **";
return 0;
}