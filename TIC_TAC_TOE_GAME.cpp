//TIC TAC TOE GAME

#include<iostream>
using namespace std;
char A[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row ,column;
bool draw=false;
void display_board()

{
	system("cls");
	cout<<"\n\n        Tic Tac Toe Game\n";
	cout<<"\nPlayer1[X] \nPlayer2[O]";
	cout<<"\n\t     |     |     ";
	cout<<"\n\t  "<<A[0][0]<<"  |  "<<A[0][1]<<"  |  "<<A[0][2]<<"  ";
	cout<<"\n\t_____|_____|_____";	
	cout<<"\n\t     |     |     ";
	cout<<"\n\t  "<<A[1][0]<<"  |  "<<A[1][1]<<"  |  "<<A[1][2]<<"  ";
	cout<<"\n\t_____|_____|_____";
	cout<<"\n\t     |     |     ";
	cout<<"\n\t  "<<A[2][0]<<"  |  "<<A[2][1]<<"  |  "<<A[2][2]<<"  ";
	cout<<"\n\t     |     |     ";
	
	
}

void player_turn()
{
	int choice;
	if(turn=='X')
	cout<<"\n\nPlayer1 [X] turn:";
	
	if(turn=='O')
	cout<<"\n\nPlayer2 [O] turn:";
	
	cin>>choice;
	switch(choice)
	{
		case 1: row=0; column=0; break;
		case 2: row=0; column=1; break;
		case 3: row=0; column=2; break;
		case 4: row=1; column=0; break;
		case 5: row=1; column=1; break;
		case 6: row=1; column=2; break;
		case 7: row=2; column=0; break;
		case 8: row=2; column=1; break;
		case 9: row=2; column=2; break;
		
		
			
		default: cout<<"Invalid Choice"<<endl; break;
	}
	if(turn=='X' && A[row][column]!='X' && A[row][column]!='O')
	{
		A[row][column]='X';
		turn='O';
	}
	else if(turn=='O'&&A[row][column]!='X'&&A[row][column]!='O')
	{
		A[row][column]='O';
		turn='X';
	}
	else
	{
		cout<<"Box already filled! \nPlease try again!!\n\n";
		player_turn();
	}
	display_board();
}

bool gameover()
{	//check win
	for(int i=0;i<3;i++)
	if(A[i][0]==A[i][1] && A[i][1]==A[i][2] || A[0][i]==A[1][i] && A[1][i]==A[2][i])
	return false;
	
	if(A[0][0]==A[1][1] && A[0][0]==A[2][2] || A[0][2]==A[1][1] && A[0][2]==A[2][0])
	return false;
	
	//if there is any box not filled
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	if(A[i][j]!='X' && A[i][j]!='O')
	return true;
	
	//draw
	draw=true;
	return false;
}

 
main()
{
	while(gameover())
	{
			
	display_board();
	player_turn();
	gameover();	
	}
	
	
	if(turn=='X' && draw==false)
	cout<<"\nPlayer2 [O] wins!!!  Congratulations\n";
	
	else if(turn=='O' && draw==false)
	cout<<"\nPlayer1 [X] wins!!!  Congratulations\n";
	
	else
	cout<<"\nGAME DRAW!!!";
}
