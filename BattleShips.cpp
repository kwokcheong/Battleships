/*Simple BattleShip game developed by @Wong Kwok Cheong. 
1. 1d array. Will develop 2d array battle-ship game next! :) will use vector < vector<int> > grid; or int grid[][]
2. Features Player vs Computer, Play again mode, valid_inputs else prompt for reinput.
3. Skill showcase: Knowledge in vectors array, boolean, conditional statements for loop while loop, library use ie: rand(), functions.  
*/


#include <iostream> 
#include <string>
#include <vector>
#include <cstdlib> 
#include <chrono> 
#include <thread>
#include <ctime>

using namespace std::this_thread; 
using namespace std::chrono_literals;
using namespace std; 

void initialize(vector<int> &board){
for (int i=0; i<10;i++)
    board.push_back(0); 
}

int valid_input (){ 
    int input = 0;
    while (input==0 or input >10){ 
        cin >> input;
        if (input == 0 or input > 10)
        cout << "Input error. ";
 }
 return input;
}

void printboard(vector<int> &board){ 
for (int i=0; i<board.size();i++){
    if (board[i] == 0)
    cout << "_" << " ";
    else if (board[i] == 2)
    cout << "X" << " ";
    else if (board[i] == 3)
    cout << "HIT!";
    else
    cout << "@" << " ";
}
    cout << "\n";
}

void deploy(vector<int> &board,int &axis){
 while (axis==0 or axis >10){ 
        cin >> axis;
        if (axis == 0 or axis > 10)
        cout << "Error: Please input a value from 1-10: ";
 }
axis -= 1;     
board[axis] = 1;
}

void com_attack(vector<int> &board){ 
    while (true){
    int pos = rand()%10;
    if (board[pos] == 1) {
        board[pos] = 3;
        break;
    } else if (board[pos] == 0){
        board[pos] = 2;
        break;
    } else if (board[pos] == 2)
        continue;
    }
}

void player_attack (vector<int> &com_board){ 
    cout << "Your turn! Select area to hit 1-10: ";
    while (true){
    int pos = 0;
    pos = valid_input();
    if (com_board[pos] == 1) {
        com_board[pos] = 3;
        cout << "Hit!" << "\n";
        break;
    } else if (com_board[pos] == 0){
        com_board[pos] = 2;
        cout << "Miss!" << "\n";
        break;
    } else if (com_board[pos] == 2)
        cout << "Invalid choice. Reselect: ";
        continue;
    }

}


int main (void){
bool flag = true;

while (flag == true){
srand((int)time(0));
int axis = 0, round = 1 , com_deploy = rand()%10;
unsigned long long x = rand()%10 + 1;
vector<int> board , com_board;
initialize(board);
initialize(com_board);
cout << "**** Welcome to Battle Ships by KC ****" << "\n";
cout << "Deploy your ship: " << "\n" << "Choose position 1-10: ";
deploy(board,axis);
cout << "Your ship"<< "\n";
printboard(board);
cout << "Computer is deploying..."<<"\n";
sleep_for(2s);
com_board[com_deploy] = 1;
cout << "Computer ready!"<< "\n"; 
sleep_for(1s); 

while (board[axis] == true){ 
    cout << "Round " << round <<"\n";
    player_attack(com_board);
    if (com_board[com_deploy] == 3){ 
        cout << "Player Wins!" << "\n";
        printboard(com_board);
        break;
    }
    cout << "Computer thinking..." << "\n";
    sleep_for(1s);
    com_attack(board); 
    if (board[axis] == 3){ 
        printboard(board);
        cout << "Computer Wins!" << "\n" ;
        break;
    }
    cout << "Your board -> ";
    printboard(board);
    round++;
}

cout << "Play again? ( 1 = Y / 0 = N) : ";
cin >> flag;
}
} 