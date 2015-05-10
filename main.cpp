//
//  main.cpp
//  Discrete Poker
//

#include <iostream>
#include <math.h>

using namespace std;
void shuffle_deck(int deck[]);
char getSuit(int a);
int getCard(int a);
void deal(int a[], int b[], int c[]);
void printDeck(int a[]);
void printHand(int a[]);
int PairCounter(int a[]);
int drawCard();
int Card1Pairs(int a[]);
int Card2Pairs(int a[]);
int Card3Pairs(int a[]);
int Card4Pairs(int a[]);
int Card5Pairs(int a[]);
int HandRank(int a[]);

int main(int argc, const char * argv[]){
    int deck[52];
    int player1[5];
    int player2[5];
    int a[10];
    int count1d;
    int count1h;
    int count1s;
    int count1c;
    int count2d;
    int count2h;
    int count2s;
    int count2c;
    int x=10;
    shuffle_deck(deck);
    cout << endl << "Shuffled Deck:" << endl;
    printDeck(deck);
    cout << endl;
    deal(player1, player2, deck);
    cout << "Player 1: ";
    printHand(player1);
    cout << "Player 2: ";
    printHand(player2);
    cout << endl;
    
    for (int i=0; i<5; i++){ //P1 Suit Counter
        if (getSuit(player1[i])=='D')
            count1d++;
        else if (getSuit(player1[i])=='H')
            count1h++;
        else if (getSuit(player1[i])=='S')
            count1s++;
        else
            count1c++;
    }
    
    for (int j=0; j<5; j++){ //P2 Suit Counter
        if (getSuit(player2[j])=='D')
            count2d++;
        else if (getSuit(player2[j])=='H')
            count2h++;
        else if (getSuit(player2[j])=='S')
            count2s++;
        else
            count2c++;
    }
    
    if (getSuit(player1[0])==getSuit(player1[1])==getSuit(player1[2])==getSuit(player1[3])==getSuit(player1[4]) || (player1[0]+1==player1[1] && player1[0]+2==player1[2] && player1[0]+3==player1[3] && player1[0]+4==player1[4])){
        cout << "Player 1 New Hand: "; //P1 Flush, Striaght
        printHand(player1);
        cout << endl;
    }
    
    else if (PairCounter(player1)==6){
        cout << "Player 1 New Hand: "; //P1 4 of a kind
        printHand(player1);
        cout << endl;
    }
    
    else if (PairCounter(player1)==5){
        cout << "Player 1 New Hand: "; //P1 Full House
        printHand(player1);
        cout << endl;
    }
    
    else if (count1d==4){ //P1 4 Diamonds
        for(int i=0; i<5; i++){
            if(player2[i]>13){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }
    else if (count1h==4){ //P1 4 Hearts
        for(int i=0; i<5; i++){
            if(player2[i] < 14 || player2[i] > 26){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }
    else if (count1s==4){ //P1 4 Spades
        for(int i=0; i<5; i++){
            if(player2[i] < 27 || player2[i] > 39){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }
    else if (count1c==4){ //P1 4 Clubs
        for(int i=0; i<5; i++){
            if(player2[i]<40){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }

    else if (PairCounter(player1)==3){ //P1 3 of a kind
        if (Card1Pairs(player1)==0){
            player1[0]=deck[x];
            x++;
        }
        if (Card2Pairs(player1)==0){
            player1[1]=deck[x];
            x++;
        }
        if (Card3Pairs(player1)==0){
            player1[2]=deck[x];
            x++;
        }
        if (Card4Pairs(player1)==0){
            player1[3]=deck[x];
            x++;
        }
        if (Card5Pairs(player1)==0){
            player1[4]=deck[x];
            x++;
        }
        cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }
    
    else if (PairCounter(player1)==2){ //P1 2 Pairs
        if (Card1Pairs(player1)==0){
            player1[0]=deck[x];
            x++;
        }
        if (Card2Pairs(player1)==0){
            player1[1]=deck[x];
            x++;
        }
        if (Card3Pairs(player1)==0){
            player1[2]=deck[x];
            x++;
        }
        if (Card4Pairs(player1)==0){
            player1[3]=deck[x];
            x++;
        }
        if (Card5Pairs(player1)==0){
            player1[4]=deck[x];
            x++;
        }
        cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }
    
    else if (PairCounter(player1)==1){ //P1 1 Pair
        if (Card1Pairs(player1)==0){
            player1[0]=deck[x];
            x++;
        }
        if (Card2Pairs(player1)==0){
            player1[1]=deck[x];
            x++;
        }
        if (Card3Pairs(player1)==0){
            player1[2]=deck[x];
            x++;
        }
        if (Card4Pairs(player1)==0){
            player1[3]=deck[x];
            x++;
        }
        if (Card5Pairs(player1)==0){
            player1[4]=deck[x];
            x++;
        }
        cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
    }
    
    else if(PairCounter(player1)==0){ //P1 High Card
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        if ((getCard(player1[0])==0 || getCard(player1[0])==1) || (getCard(player1[1])==0 || getCard(player1[1])==1)){
            player1[2]=deck[x];
            x++;
            player1[3]=deck[x];
            x++;
            player1[4]=deck[x];
            x++;
            cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;        }
        else if (getCard(player1[0])==0 || getCard(player1[0])==1){
            player1[1]=deck[x];
            x++;
            player1[2]=deck[x];
            x++;
            player1[3]=deck[x];
            x++;
            cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
        }
        else {
            player1[0]=deck[x];
            x++;
            player1[1]=deck[x];
            x++;
            player1[2]=deck[x];
            x++;
            cout <<  "Player 1 New Hand: " << player1[0] << ", " << player1[1] << ", " << player1[2] << ", " << player1[3] << ", " <<player1[4] << endl;
        }
    }
    
    if (getSuit(player2[0])==getSuit(player2[1])==getSuit(player2[2])==getSuit(player2[3])==getSuit(player2[4]) || (player2[0]+1==player2[1] && player2[0]+2==player2[2] && player2[0]+3==player2[3] && player2[0]+4==player2[4])){
        cout << "Player 2 New Hand: "; //P2 Flush, Striaght
        printHand(player2);
        cout << endl;
    }
    
    else if (PairCounter(player2)==6){
        cout << "Player 2 New Hand: "; //P2 4 of a kind
        printHand(player2);
        cout << endl;
    }
    
    else if (PairCounter(player2)==5){
        cout << "Player 2 New Hand: "; //P2 Full House
        printHand(player2);
        cout << endl;
    }
    
    else if (count2d==4){ //P2 4 Diamonds
        for(int i=0; i<5; i++){
            if(player2[i]>13){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    }
    else if (count2h==4){ //P2 4 Hearts
        for(int i=0; i<5; i++){
            if(player2[i] < 14 || player2[i] > 26){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    }
    else if (count2s==4){ //P2 4 Spades
        for(int i=0; i<5; i++){
            if(player2[i] < 27 || player2[i] > 39){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    }
    else if (count2c==4){ //P2 4 Clubs
        for(int i=0; i<5; i++){
            if(player2[i]<40){
                player2[i]=deck[x];
                x++;
            }
        }
                cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    }
    
    else if (PairCounter(player2)==3){ //P2 3 of a kind
        if (Card1Pairs(player2)==0){
            player2[0]=deck[x];
            x++;
        }
        if (Card2Pairs(player2)==0){
            player2[1]=deck[x];
            x++;
        }
        if (Card3Pairs(player2)==0){
            player2[2]=deck[x];
            x++;
        }
        if (Card4Pairs(player2)==0){
            player2[3]=deck[x];
            x++;
        }
        if (Card5Pairs(player2)==0){
            player2[4]=deck[x];
            x++;
        }
        cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    }
    
    else if (PairCounter(player2)==2){ //P2 2 Pairs
        if (Card1Pairs(player2)==0){
            player2[0]=deck[x];
            x++;
        }
        if (Card2Pairs(player2)==0){
            player2[1]=deck[x];
            x++;
        }
        if (Card3Pairs(player2)==0){
            player2[2]=deck[x];
            x++;
        }
        if (Card4Pairs(player2)==0){
            player2[3]=deck[x];
            x++;
        }
        if (Card5Pairs(player2)==0){
            player2[4]=deck[x];
            x++;
        }
        cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    }

    else if (PairCounter(player2)==1){ //P2 1 Pair
        if (Card1Pairs(player2)==0){
            player2[0]=deck[x];
            x++;
        }
        if (Card2Pairs(player2)==0){
            player2[1]=deck[x];
            x++;
        }
        if (Card3Pairs(player2)==0){
            player2[2]=deck[x];
            x++;
        }
        if (Card4Pairs(player2)==0){
            player2[3]=deck[x];
            x++;
        }
        if (Card5Pairs(player2)==0){
            player2[4]=deck[x];
            x++;
        }
        cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
    
    }
    else if(PairCounter(player2)==0){ //P2 High Card
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if ((getCard(player2[0])==0 || getCard(player2[0])==1) || (getCard(player2[1])==0 || getCard(player2[1])==1)){
            player2[2]=deck[x];
            x++;
            player2[3]=deck[x];
            x++;
            player2[4]=deck[x];
            x++;
            cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;        }
        else if (getCard(player2[0])==0 || getCard(player2[0])==1){
            player2[1]=deck[x];
            x++;
            player2[2]=deck[x];
            x++;
            player2[3]=deck[x];
            x++;
            cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
        }
        else {
            player2[0]=deck[x];
            x++;
            player2[1]=deck[x];
            x++;
            player2[2]=deck[x];
            x++;
            cout <<  "Player 2 New Hand: " << player2[0] << ", " << player2[1] << ", " << player2[2] << ", " << player2[3] << ", " <<player2[4] << endl;
        }
    }
    cout << endl;
    
    //Deciding Winner
    if (HandRank(player1)<HandRank(player2))
        cout << "Player 1 Wins!";
    
    else if (HandRank(player1)>HandRank(player2))
        cout << "Player 2 Wins!";
    
    else if (HandRank(player1)==1 && HandRank(player2)==1){
        if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
            cout << "Player 1 Wins!";
        }
        else if (getCard(player1[4])==getCard(player2[4])){
            if (player1[4]>player2[4])
                cout << "Player 1 Wins!";
            else
                cout << "Player 2 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==2 && HandRank(player2)==2){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[3])==1 || (getCard(player1[3])==0 && getCard(player2[3])!=1) || (getCard(player1[3])>getCard(player2[3]) && getCard(player2[3]!=1) && getCard(player2[3])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==3 && HandRank(player2)==3){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[2])==1 || (getCard(player1[2])==0 && getCard(player2[2])!=1) || (getCard(player1[2])>getCard(player2[2]) && getCard(player2[2]!=1) && getCard(player2[2])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==4 && HandRank(player2)==4){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==5 && HandRank(player2)==5){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==6 && HandRank(player2)==6){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[2])==1 || (getCard(player1[2])==0 && getCard(player2[2])!=1) || (getCard(player1[2])>getCard(player2[2]) && getCard(player2[2]!=1) && getCard(player2[2])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==7 && HandRank(player2)==7){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player1[j])>getCard(player1[j+1])){
                    int temp = player1[j];
                    player1[j]=player1[j+1];
                    player1[j+1]=temp;
                }
            }
        }
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[3])==1 || (getCard(player1[3])==0 && getCard(player2[3])!=1) || (getCard(player1[3])>getCard(player2[3]) && getCard(player2[3]!=1) && getCard(player2[3])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    else if (HandRank(player1)==8 && HandRank(player2)==8){
        if (Card1Pairs(player1)==1 && Card1Pairs(player2)==1){
            if (getCard(player1[0])>getCard(player2[0]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[0])==getCard(player2[0])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card1Pairs(player1)==1 && Card2Pairs(player2)==1){
            if (getCard(player1[0])>getCard(player2[1]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[0])==getCard(player2[1])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card1Pairs(player1)==1 && Card3Pairs(player2)==1){
            if (getCard(player1[0])>getCard(player2[2]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[0])==getCard(player2[2])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card1Pairs(player1)==1 && Card4Pairs(player2)==1){
            if (getCard(player1[0])>getCard(player2[3]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[0])==getCard(player2[3])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card2Pairs(player1)==1 && Card1Pairs(player2)==1){
            if (getCard(player1[1])>getCard(player2[0]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[1])==getCard(player2[0])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card2Pairs(player1)==1 && Card2Pairs(player2)==1){
            if (getCard(player1[1])>getCard(player2[1]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[1])==getCard(player2[1])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card2Pairs(player1)==1 && Card3Pairs(player2)==1){
            if (getCard(player1[1])>getCard(player2[2]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[1])==getCard(player2[2])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card2Pairs(player1)==1 && Card4Pairs(player2)==1){
            if (getCard(player1[1])>getCard(player2[3]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[1])==getCard(player2[3])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card3Pairs(player1)==1 && Card1Pairs(player2)==1){
            if (getCard(player1[2])>getCard(player2[0]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[2])==getCard(player2[0])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card3Pairs(player1)==1 && Card2Pairs(player2)==1){
            if (getCard(player1[2])>getCard(player2[1]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[2])==getCard(player2[1])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card3Pairs(player1)==1 && Card3Pairs(player2)==1){
            if (getCard(player1[2])>getCard(player2[2]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[2])==getCard(player2[2])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card3Pairs(player1)==1 && Card4Pairs(player2)==1){
            if (getCard(player1[2])>getCard(player2[3]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[2])==getCard(player2[3])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card4Pairs(player1)==1 && Card1Pairs(player2)==1){
            if (getCard(player1[3])>getCard(player2[0]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[3])==getCard(player2[0])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card4Pairs(player1)==1 && Card2Pairs(player2)==1){
            if (getCard(player1[3])>getCard(player2[1]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[3])==getCard(player2[1])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card4Pairs(player1)==1 && Card3Pairs(player2)==1){
            if (getCard(player1[3])>getCard(player2[2]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[3])==getCard(player2[2])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
        else if (Card4Pairs(player1)==1 && Card4Pairs(player2)==1){
            if (getCard(player1[3])>getCard(player2[3]))
                cout << "Player 1 Wins!";
            else if (getCard(player1[3])==getCard(player2[3])){
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player1[j])>getCard(player1[j+1])){
                            int temp = player1[j];
                            player1[j]=player1[j+1];
                            player1[j+1]=temp;
                        }
                    }
                }
                for(int k=5;k>0;k--){
                    for(int j=0;j<k-1;j++){
                        if (getCard(player2[j])>getCard(player2[j+1])){
                            int temp = player2[j];
                            player2[j]=player2[j+1];
                            player2[j+1]=temp;
                        }
                    }
                }
                if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
                    cout << "Player 1 Wins!";
                }
                else
                    cout << "Player 2 Wins!";
            }
            else
                cout << "Player 2 Wins!";
        }
    }
    
    else if (HandRank(player1)==9 && HandRank(player2)==9){
        for(int k=5;k>0;k--){
            for(int j=0;j<k-1;j++){
                if (getCard(player2[j])>getCard(player2[j+1])){
                    int temp = player2[j];
                    player2[j]=player2[j+1];
                    player2[j+1]=temp;
                }
            }
        }
        if (getCard(player1[4])==1 || (getCard(player1[4])==0 && getCard(player2[4])!=1) || (getCard(player1[4])>getCard(player2[4]) && getCard(player2[4]!=1) && getCard(player2[4])!=0)){
            cout << "Player 1 Wins!";
        }
        else
            cout << "Player 2 Wins!";
    }
    
    cout << endl;
    cout << endl;
    return 0;
}

// IMPORTS empty array
// EXPORTS shuffled filled array
void shuffle_deck(int deck[]){
    int temp;
    int j;
    srand(time(0));
    for(int i=0; i <52; i++)
    {
        deck[i]=i+1;
    }
    for(int i=51; i >= 0; i--)
    {
        j= rand()%51;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Replies with Suit
//1-13=D 14-26=H 27-39=S 40-52=C
char getSuit(int a){
    a--;
    if (floor(a/13)==0)
        return 'D';
    else if (floor(a/13)==1)
        return 'H';
    else if (floor(a/13)==2)
        return 'S';
    else
        return 'C';
}

// Returns card type
// 2-10=# 11=J 12=Q 0=K 1=A
int getCard(int a){
    return a%13;
}

void deal(int a[], int b[], int deck[]){
    for(int i=0; i<5; i++){
        a[i]=deck[i];
        b[i]=deck[i+5];
    }
}

void printDeck(int a[]){
    for( int i=0; i < 52; i++){
        cout << a[i] << ", ";
    }
    cout<< endl;
}

void printHand(int a[]){
    int minumumA = a[0];
    for(int i=5;i>0;i--){
        for(int j=0;j<i-1;j++){
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for( int i=0; i < 5; i++){
        cout << a[i] << ", " ;
    }
    cout << endl;
}

int PairCounter(int a[]){
    int counter=0;
    if(getCard(a[0])==getCard(a[1]))
       counter++;
    if(getCard(a[0])==getCard(a[2]))
       counter++;
    if(getCard(a[0])==getCard(a[3]))
       counter++;
    if(getCard(a[0])==getCard(a[4]))
       counter++;
    if(getCard(a[1])==getCard(a[2]))
       counter++;
    if(getCard(a[1])==getCard(a[3]))
       counter++;
    if(getCard(a[1])==getCard(a[4]))
       counter++;
    if(getCard(a[2])==getCard(a[3]))
       counter++;
    if(getCard(a[2])==getCard(a[4]))
       counter++;
    if(getCard(a[3])==getCard(a[4]))
       counter++;
    return counter;
}

int Card1Pairs(int a[]){
    int counter=0;
    if(getCard(a[0])==getCard(a[1]))
        counter++;
    if(getCard(a[0])==getCard(a[2]))
        counter++;
    if(getCard(a[0])==getCard(a[3]))
        counter++;
    if(getCard(a[0])==getCard(a[4]))
        counter++;
    return counter;
}

int Card2Pairs(int a[]){
    int counter=0;
    if(getCard(a[1])==getCard(a[0]))
        counter++;
    if(getCard(a[1])==getCard(a[2]))
        counter++;
    if(getCard(a[1])==getCard(a[3]))
        counter++;
    if(getCard(a[1])==getCard(a[4]))
        counter++;
    return counter;
}

int Card3Pairs(int a[]){
    int counter=0;
    if(getCard(a[2])==getCard(a[0]))
        counter++;
    if(getCard(a[2])==getCard(a[1]))
        counter++;
    if(getCard(a[2])==getCard(a[3]))
        counter++;
    if(getCard(a[2])==getCard(a[4]))
        counter++;
    return counter;
}

int Card4Pairs(int a[]){
    int counter=0;
    if(getCard(a[3])==getCard(a[0]))
        counter++;
    if(getCard(a[3])==getCard(a[1]))
        counter++;
    if(getCard(a[3])==getCard(a[2]))
        counter++;
    if(getCard(a[3])==getCard(a[4]))
        counter++;
    return counter;
}

int Card5Pairs(int a[]){
    int counter=0;
    if(getCard(a[4])==getCard(a[0]))
        counter++;
    if(getCard(a[4])==getCard(a[1]))
        counter++;
    if(getCard(a[4])==getCard(a[2]))
        counter++;
    if(getCard(a[4])==getCard(a[3]))
        counter++;
    return counter;
}

int HandRank(int a[]){
    int rank;
    if (getSuit(a[0])==getSuit(a[1])==getSuit(a[2])==getSuit(a[3])==getSuit(a[4]) && (a[0]+1==a[1] && a[0]+2==a[2] && a[0]+3==a[3] && a[0]+4==a[4])){
        rank=1;
        return rank;
    }
    else if (PairCounter(a)==6){
        rank=2;
        return rank;
    }
    else if (PairCounter(a)==5){
        rank=3;
        return rank;
    }
    else if (getSuit(a[0])==getSuit(a[1])==getSuit(a[2])==getSuit(a[3])==getSuit(a[4])){
        rank=4;
        return rank;
    }
    else if (a[0]+1==a[1] && a[0]+2==a[2] && a[0]+3==a[3] && a[0]+4==a[4]){
        rank=5;
        return rank;
    }
    else if (PairCounter(a)==3){
        rank=6;
        return rank;
    }
    else if (PairCounter(a)==2){
        rank=7;
        return rank;
    }
    else if (PairCounter(a)==1){
        rank=8;
        return rank;
    }
    else{
        rank=9;
        return rank;
    }
}








