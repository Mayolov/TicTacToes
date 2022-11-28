#include <iostream>
using namespace std;

char board [3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, column;
bool draw = false;

void display_board(){
    cout<<"         T I C     T A C     T O E     G A M E"<<endl;
    cout<<"\t PLAYER 1[X] \n\t PLAYER 2[O] \n\n";
    cout<<"\t\t      |      |      "<<endl;
    cout<<"\t\t    "<<board[0][0]<<" |   "<<board[0][1]<<"  |   "<<board[0][2]<<"   "<<endl;
    cout<<"\t\t______|______|______"<<endl;
    cout<<"\t\t      |      |      "<<endl;
    cout<<"\t\t   "<<board[1][0]<<"  |   "<<board[1][1]<<"  |   "<<board[1][2]<<"   "<<endl;
    cout<<"\t\t______|______|______"<<endl;    
    cout<<"\t\t      |      |      "<<endl;
    cout<<"\t\t   "<<board[2][0]<<"  |   "<<board[2][1]<<"  |   "<<board[2][2]<<"   "<<endl;
    cout<<"\t\t      |      |      "<<endl;    
    };

void player_turn(){
    int choice;

    if(turn == 'X')
        cout<<"PLAYER 1 [X] TURN : "<<endl;
        else if(turn == 'O')
        cout<<"PLAYER 1 [O] TURN : "<<endl;

    cin>>choice;
    switch(choice){
        case 1: row =0; column =0;break;
        case 2: row =0; column =1;break;
        case 3: row =0; column =2;break;
        case 4: row =1; column =0;break;
        case 5: row =1; column =1;break;
        case 6: row =1; column =2;break;
        case 7: row =2; column =0;break;
        case 8: row =2; column =1;break;
        case 9: row =2; column =2;break;

        default: cout<<"INVALID NUMBER ENTER "<<endl;break;
        }

    if(turn=='X'&& board[row][column]!= 'X' && board[row][column]!= 'O'){
        board[row][column]='X';
        turn = 'O';
    }
    else if(turn=='O' && board[row][column]!= 'X' && board[row][column]!= 'O'){
        board[row][column]='O';
        turn = 'X';
    }
    else{
        cout<<"BOX ALREADY FILLED \n\n";
        player_turn();
    }
    }

bool gameover(){
    for(int i=0;i<3;i++)
    if(board[i][0]==board [i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;
    else if (board[0][0]==board [1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][0] == board[2][0])
    return false;
    

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)

    if(board[i][j]!='X' && board[i][j]!='O')
    return true;

    draw= true;
    return false;

}

int main(){
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }

    if(turn =='X' && draw == false)
    cout<<"PLAYER 2[O] WINS!!";
    else if(turn=='O' && draw== false)
    cout<<"PLAYER 1[X] WINS!!";
    else
    cout<<"GAME DRAW !! ";
}