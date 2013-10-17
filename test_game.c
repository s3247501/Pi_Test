#include <stdio.h>
 
#define ROWS 3
#define COLS 3
#define DIMENSIONS 2
#define ROW 0
#define COL 1
#define INTROW 0
#define INTCOL 0
#define CMDNEXTSPOT 9
#define CMDPLACE 0
#define TRUE 1
#define FALSE 0
#define PLAYER_1 1
#define PLAYER_2 2
 
typedef char Board[ROWS][COLS];
typedef int Position[DIMENSIONS];
 
int hasWinner(Board board)
{
    int line = 0;
    if((board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0] != ' ') ||
        (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2] != ' ')) { return 1; }
    for(line = 0; line <=2; line++) {
        if((board[line][0]==board[line][1] && board[line][0]==board[line][2] && board[line][0] != ' ')||
            (board[0][line]==board[1][line] && board[0][line]==board[2][line] && board[0][line] != ' ')) {
                return 1;
            }
    }
    return 0;
}
 
int hasEnded(Board board)
{
    int i,j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}
 
int switchplayer(int player)
{
    if(player == 1)
        return 2;
    return 1;
}
 
int main (void)
{
	int num_1, num_2, num_3, num_4, num_5, num_6;
	int i,j;
	int flag_1, flag_2, flag_3;
	int player;
 
    	/* test hasWinner*/
	printf("\nGAME HAS WINNER\n");
	printf("----------------------\n");
	
	Board board_1 = {
        	{'X',' ',' '},
        	{' ','X',' '},
        	{' ',' ','X'}
    	};
	
	Board board_2 = {
        	{' ',' ',' '},
        	{'X','X','X'},
        	{' ',' ',' '}
    	};
	
	Board board_3 = {
        	{' ','X',' '},
        	{' ','X',' '},
        	{' ','X',' '}
    	};
	
	Board board_4 = {
        	{'X',' ',' '},
        	{' ','O',' '},
        	{' ',' ','X'}
    	};
	
	Board board_5 = {
        	{' ',' ',' '},
        	{'X','O','X'},
        	{' ',' ',' '}
    	};
	
	Board board_6 = {
        	{' ','X',' '},
        	{' ','O',' '},
        	{' ','X',' '}
    	};
	
	num_1 = hasWinner(board_1);
	if(num_1 == 1)
		printf("Test case 1 : passed\n");
	else
		printf("Test case 1 : failed\n");
	
	num_2 = hasWinner(board_2);
	if(num_2 == 1)
		printf("Test case 2 : passed\n");
	else
		printf("Test case 2 : failed\n");
	
	num_3 = hasWinner(board_3);
	if(num_3 == 1)
		printf("Test case 3 : passed\n");
	else
		printf("Test case 3 : failed\n");
		
	num_4 = hasWinner(board_4);
	if(num_4 == 1)
		printf("Test case 4 : failed\n");
	else
		printf("Test case 4 : passed\n");
		
	num_5 = hasWinner(board_5);
	if(num_5 == 1)
		printf("Test case 5 : failed\n");
	else
		printf("Test case 5 : passed\n");
		
	num_6 = hasWinner(board_6);
	if(num_6 == 1)
		printf("Test case 6 : failed\n");
	else
		printf("Test case 6 : passed\n");
	
	/* test hasEnded */
	printf("\nGAME IS ENDED\n");
	printf("----------------------\n");
	
	Board board_a = {
        	{' ',' ',' '},
        	{' ',' ',' '},
        	{' ',' ',' '}
    	};
	
	Board board_b = {
        	{'X','X','O'},
        	{'O','X',' '},
        	{'X','O','O'}
    	};
	
	Board board_c = {
        	{'X','X','O'},
        	{'O','X','X'},
        	{'X','O','O'}
    	};
	
	flag_1 = hasEnded(board_a);
	if(flag_1 == 0)
		printf("Test case 1 : passed\n");
	else
		printf("Test case 1 : failed\n");
		
	flag_2 = hasEnded(board_b);
	if(flag_2 == 0)
		printf("Test case 2 : passed\n");
	else
		printf("Test case 2 : failed\n");	
	
	flag_3 = hasEnded(board_c);
	if(flag_3 == 0)
		printf("Test case 3 : failed\n");
	else
		printf("Test case 3 : passed\n");

	/* test player */
	printf("\nSWITCH PLAYER\n");
	printf("----------------------\n");

	player = switchplayer(PLAYER_1);
	if(player == PLAYER_2)
		printf("Test player : passed\n\n");
	else
		printf("Test player : failed\n\n");

	return 0;	
}
