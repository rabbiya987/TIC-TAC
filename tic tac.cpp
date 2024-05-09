#include <iostream>
#include<stdlib.h>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn='x';
bool draw=false;

void display_board(){

    cout<<"\n\tPLAYER - 1 [X]\t PLAYER - 2 [O]\n";
    cout<<"\n\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void player_turn(){
	if(turn=='x'){
		cout<<"\n\tPlayer - 1[x] turn :";
	}
	else if(turn=='o'){
		cout<<"\n\tPlayer - 2[o] turn :";
	}
	cin>>choice;
	switch(choice){
		case 1 :row=0; column=0; break;
		case 2 :row=0; column=1; break;
		case 3 :row=0; column=2; break;
		case 4 :row=1; column=0; break;
		case 5 :row=1; column=1; break;
		case 6 :row=1; column=2; break;
		case 7 :row=2; column=0; break;
		case 8 :row=2; column=1; break;
		case 9 :row=2; column=2; break;
		default:
			cout<<"invalid move";
	}
	
	if(turn=='x' && board[row][column]!='x' && board[row][column] !='o'){
		board[row][column]='x';
		turn='o';
	}
	else if(turn=='o' && board[row][column]!='x' && board[row][column] !='o'){
		board[row][column]='o';
		turn='x';
	}
	else{
		cout<<"box already filled";
		player_turn();
	}
	system("CLS");
	}
	
bool gameover(){
	for(int i=0;i<3;i++)
	if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i])
	return false;
	if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
	return false;
	
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(board[i][j]!='x' && board[i][j]!='o')
	return true;
	
	draw=true;
	return false;
}	

int main()
{
    cout<<"\n\tT I C K -- T A C -- T O E -- G A M E\t";
    cout<<"\n\t\tFOR 2 PLAYERS\n";
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }
    if(turn == 'x' && draw == false){
        cout<<"\n\tCONGRATULATION! Player2 with 'o' has won the game";
    }
    else if(turn == 'o' && draw == false){
        cout<<"\n\tCONGRATULATION! Player1 with 'x' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
} 

