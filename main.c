#include <stdio.h>
#pragma warning(disable: 4996)
#include <ctype.h>


void DisplayAuthor() {
	printf("Author: Mohammad Abdul Salam and Muneeb Mirza\n");
	printf("Program: Pentago\n");
}


void DisplayGameInformation() {
	printf("Play the two-player game of Pentago. Be the first to get 5 in a row.\n\n");
	printf("Pentago is played on a 6 by 6 board, divided into four 3 by 3 \n");
	printf("quadrants.  There are two players, X and O, who alternate turns.\n");
	printf("The goal of each player is to get five of their pieces in a row,\n");
	printf("either horizontally, vertically, or diagonally.\n\n");
	printf("Players take turns placing one of their pieces into an empty\n");
	printf("space anywhere on the board, then choosing one of the four\n");
	printf("board quadrants to rotate 90 degrees left or right.\n\n");
	printf("If both players get five in a row at the same time, or the\n");
	printf("last move is played with no five in a row, the game is a tie.\n");
	printf("If a player makes five a row by placing a piece, there is no need\n");
	printf("to rotate a quadrant and the player wins immediately.\n\n");
	printf("At any point enter 'x' to exit the program.\n\n");
}
// Displaying Game Information
void displayBoard(char board[6][6]) {
	int row = 0;
	int coulmn = 0;
	char letters = 'A';
	printf("  1  1 2 3 4 5 6  2\n");
	printf("     -----------\n");
	for (row = 0; row < 6; row++) {
		printf("  %c:", letters);
		for (coulmn = 0; coulmn < 6; coulmn++) {
			printf(" %c", board[row][coulmn]);

		}
		printf(" :%c", letters);
		letters++;
		printf("    \n");
	}


	printf("     -----------\n");
	printf("  3  1 2 3 4 5 6  4\n");
}
// displayBoard function creates a 6 by 6 board and assigns the rows by letters and columns by numbers.

int errorCheck(char row, int column, int quadrant, char direction, char board[6][6], int i, int j) {

	if ((row < 'A') || ((row > 'F'))) {
		printf("*** Invalid move row.  Please retry.\n");
		return 0;
	}
	else if (column < 1 || column > 6) {
		printf("*** Invalid move column.  Please retry.\n");
		return 0;
	}
	else if (quadrant < 1 || quadrant > 4) {
		printf("*** Selected quadrant is invalid.  Please retry.\n");
		return 0;
	}
	else if (((direction != 'L')) && ((direction != 'R'))) {
		printf("*** Quadrant rotation direction is invalid.  Please retry.\n");
		return 0;
	}
	else if (board[i][j] != '.') {
		printf("The position is not empty\n");
		return 0;

	}
	else {
		return 1;
	}
}
// errorCheck function checks all the possible values that are outside the board and gives an error if user value is out of range.



int rotate1(char arr[6][6], int direction, int turn) {
	char arr1[3];
	char arr2[3];
	char arr3[3];
	int i = 0;

	if (direction == 'R') {
		for (; i < 3; i++) {
			arr1[i] = arr[0][i];
			arr2[i] = arr[1][i];
			arr3[i] = arr[2][i];
		}
		for (i = 0; i < 3; i++) {
			arr[i][2] = arr1[i];
			arr[i][1] = arr2[i];
			arr[i][0] = arr3[i];
		}

	}
	else if (direction == 'L') {
		for (i = 0; i < 3; i++) {
			arr1[2 - i] = arr[0][i];
			arr2[2 - i] = arr[1][i];
			arr3[2 - i] = arr[2][i];
		}
		for (i = 0; i < 3; i++) {
			arr[i][0] = arr1[i];
			arr[i][1] = arr2[i];
			arr[i][2] = arr3[i];
		}
	}
	if (turn == 1) {
		return 2;
	}
	else {
		return 1;
	}
}
// rotate1 function uses arrays to switch the values in an array after rotating. This function is for the first quadrant.



int rotate2(char arr[6][6], int direction, int turn) {
	char arr1[3];
	char arr2[3];
	char arr3[3];
	int i = 0;

	if (direction == 'R') {
		for (; i < 3; i++) {
			arr1[i] = arr[0][i + 3];
			arr2[i] = arr[1][i + 3];
			arr3[i] = arr[2][i + 3];
		}
		for (i = 0; i < 3; i++) {
			arr[i][5] = arr1[i];
			arr[i][4] = arr2[i];
			arr[i][3] = arr3[i];
		}

	}
	else if (direction == 'L') {
		for (i = 0; i < 3; i++) {
			arr1[2 - i] = arr[0][i + 3];
			arr2[2 - i] = arr[1][i + 3];
			arr3[2 - i] = arr[2][i + 3];
		}
		for (i = 0; i < 3; i++) {
			arr[i][3] = arr1[i];
			arr[i][4] = arr2[i];
			arr[i][5] = arr3[i];
		}
	}
	if (turn == 1) {
		return 2;
	}
	else {
		return 1;
	}
}
// rotate2 function uses arrays to switch the values in an array after rotating. This function is for the second quadrant.


int rotate3(char arr[6][6], int direction, int turn) {
	char arr1[3];
	char arr2[3];
	char arr3[3];
	int i = 0;

	if (direction == 'R') {
		for (; i < 3; i++) {
			arr1[i] = arr[3][i];
			arr2[i] = arr[4][i];
			arr3[i] = arr[5][i];
		}
		for (i = 0; i < 3; i++) {
			arr[i + 3][2] = arr1[i];
			arr[i + 3][1] = arr2[i];
			arr[i + 3][0] = arr3[i];
		}

	}
	else if (direction == 'L') {
		for (i = 0; i < 3; i++) {
			arr1[2 - i] = arr[3][i];
			arr2[2 - i] = arr[4][i];
			arr3[2 - i] = arr[5][i];
		}
		for (i = 0; i < 3; i++) {
			arr[i + 3][0] = arr1[i];
			arr[i + 3][1] = arr2[i];
			arr[i + 3][2] = arr3[i];
		}
	}
	if (turn == 1) {
		return 2;
	}
	else {
		return 1;
	}
}
// rotate3 function uses arrays to switch the values in an array after rotating. This function is for the third quadrant.



int rotate4(char arr[6][6], int direction, int turn) {
	char arr1[3];
	char arr2[3];
	char arr3[3];
	int i = 0;

	if (direction == 'R') {
		for (; i < 3; i++) {
			arr1[i] = arr[3][i + 3];
			arr2[i] = arr[4][i + 3];
			arr3[i] = arr[5][i + 3];
		}
		for (i = 0; i < 3; i++) {
			arr[i + 3][5] = arr1[i];
			arr[i + 3][4] = arr2[i];
			arr[i + 3][3] = arr3[i];
		}

	}
	else if (direction == 'L') {
		for (i = 0; i < 3; i++) {
			arr1[2 - i] = arr[3][i + 3];
			arr2[2 - i] = arr[4][i + 3];
			arr3[2 - i] = arr[5][i + 3];
		}
		for (i = 0; i < 3; i++) {
			arr[i + 3][3] = arr1[i];
			arr[i + 3][4] = arr2[i];
			arr[i + 3][5] = arr3[i];
		}
	}
	if (turn == 1) {
		return 2;
	}
	else {
		return 1;
	}
}
// rotate4 function uses arrays to switch the values in an array after rotating. This function is for the fourth quadrant.


int horizontal(char board[6][6]) {
	int p1win = 0;
	int p2win = 0;
	int i;
	int j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 5; j++) {
			if (board[i][j] == 'X') {
				p1win++;
			}
			else if (board[i][j] == 'O') {
				p2win++;
			}
		}
		if (p1win == 5) {
			return 1;
		}
		else if (p2win == 5) {
			return 2;
		}
		p1win = 0;
		p2win = 0;
	}
	for (i = 0; i < 6; i++) {
		for (j = 1; j < 6; j++) {
			if (board[i][j] == 'X') {
				p1win++;
			}
			else if (board[i][j] == 'O') {
				p2win++;
			}
		}
		if (p1win == 5) {
			return 1;
		}
		else if (p2win == 5) {
			return 2;
		}
		p1win = 0;
		p2win = 0;
	}

}
// horizontal first adds one to either 'X' or 'O' depending on whose turn is it and returns 1 for player one or 2 for player two if either one of them get 5 pieces in a row.
// function checks the first 5 in a row then the last 5 elements in a row




//=====================================


int Vertical(char board[6][6]) {
	int i, j;
	int p1win = 0, p2win = 0;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 5; j++) {
			if (board[j][i] == 'X') {
				p1win++;
			}
			else if (board[j][i] == 'O') {
				p2win++;
			}

		}
		if (p1win == 5) {
			return 1;
		}
		else if (p2win == 5) {
			return 2;
		}
		p1win = 0;
		p2win = 0;
	}


	for (i = 0; i < 6; i++) {
		for (j = 1; j < 6; j++) {
			if (board[j][i] == 'X') {
				p1win++;
			}
			else if (board[j][i] == 'O') {
				p2win++;
			}

		}
		if (p1win == 5) {
			return 1;
		}
		else if (p2win == 5) {
			return 2;
		}
		p1win = 0;
		p2win = 0;
	}
}
// Vertical first adds one to either 'X' or 'O' depending on whose turn is it and returns 1 for player one or 2 for player two if either one of them get 5 pieces in a column.
// function checks the first 5 in a column then the last 5 elements in a column


int DiagnolRight(char board[6][6]) {
	int p1win = 0, p2win = 0;		//from position board [0][0] to board [4][4]
	int i = 0, j = 0;

	for (i = 0; i < 5; i++) {
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}
	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}
	p1win = 0;
	p2win = 0;
	j = 1;
	for (i = 1; i < 5; i++) {		//position [1][1] to board [4][5]

		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}
	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}
	p1win = 0;
	p2win = 0;


	j = 0;
	for (i = 1; i < 6; i++) { // position board [1][0] to board [5][4]
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}

	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}

	p1win = 0;
	p2win = 0;


	j = 1;
	for (i = 1; i < 6; i++) {		// position board [1][1] to board [5][5]
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}
	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}

}
// DiagnolRight checks 4 ways from top left to bottom right and adds +1 depending on 'X' or 'O'.
// Also, returns player one wins or player two wins if one of them hits 5 pieces.

int DiagnolLeft(char board[6][6]) { // position board [5][0] to board [1][4] 
	int i = 0, j = 0;
	int p1win = 0, p2win = 0;

	for (i = 5; i >= 1; i--) {
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}
	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}
	p1win = 0;
	p2win = 0;

	j = 0;
	for (i = 4; i >= 0; i--) { // position board[5][0] to board [0][5]
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}
	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}
	p1win = 0;
	p2win = 0;


	j = 1;
	for (i = 5; i >= 1; i--) { // position board [5][0] to board [0][4]
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}

	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}
	p1win = 0;
	p2win = 0;

	j = 1;

	for (i = 4; i >= 0; i--) {  // position board [4][1] to board [0][5]
		if (board[i][j] == 'X') {
			p1win++;
		}
		else if (board[i][j] == 'O') {
			p2win++;
		}
		j++;
	}
	if (p1win == 5) {
		return 1;
	}
	else if (p2win == 5) {
		return 2;
	}

}
// DiagnolRight checks 4 ways from top left to bottom right and adds +1 depending on 'X' or 'O'.
// Also, returns player one wins or player two wins if one of them hits 5 pieces.




int main() {
	DisplayAuthor();
	DisplayGameInformation(); // calling the information functions


	char board[6][6];
	char direction = 'r';
	int quadrant = 1;
	char row = 'A';
	int column = 2;
	int i = 0;
	int j = 0;
	// Declaring variables
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			board[i][j] = '.';
		}
	}


	int turn = 1;
	char player = 'X';
	displayBoard(board);
	int numMoves = 0;
	while (1) {
		if (turn == 1) {
			printf("\n\nEnter row, column, quadrant, and direction for X:");
			player = 'X';

		}
		else {
			printf("\n\nEnter row, column, quadrant, and direction for O:");
			player = 'O';
		}
		// if statement for two playeres

		scanf(" %c", &row);
		if (row == 'X' || row == 'x') {
			printf("Exiting program...\n");
			return 0;

		}
		scanf("%d", &column);
		scanf("%c", &direction);
		row = toupper(row);
		direction = toupper(direction);
		quadrant = column % 10;
		column = column / 10;



		if (errorCheck(row, column, quadrant, direction, board, row - 65, column - 1) != 1) {
			continue;
		}
		// errorCheck continues if user values passes all checks

		board[row - 65][column - 1] = player;
		displayBoard(board);

		int result1, result2, result3, result4;
		result1 = horizontal(board);
		result2 = Vertical(board);
		result3 = DiagnolLeft(board);
		result4 = DiagnolRight(board);
		if (result1 == 1 && result2 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result1 == 1 && result3 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result1 == 1 && result4 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result2 == 1 && result1 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result2 == 1 && result3 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result2 == 1 && result4 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result3 == 1 && result1 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result3 == 1 && result2 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result3 == 1 && result4 == 4) {
			printf("Its a tie");
			return 0;
		}
		else if (result4 == 1 && result1 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result4 == 1 && result2 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result4 == 1 && result3 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result1 == 1 || result2 == 1 || result3 == 1 || result4 == 1) {
			printf("\nPlayer one wins\n");
			system("pause");
			return 0;
		}
		else if (result1 == 2 || result2 == 2 || result3 == 2 || result4 == 2) {
			printf("\nPlayer two wins\n");
			system("pause");
			return 0;
		}
		// if statement to determine the winner or to determine if its a tie



		if (quadrant == 1) {
			turn = rotate1(board, direction, turn);
			numMoves++;
		}
		else if (quadrant == 2) {
			turn = rotate2(board, direction, turn);
			numMoves++;
		}

		else if (quadrant == 3) {
			turn = rotate3(board, direction, turn);
			numMoves++;
		}
		else if (quadrant == 4) {
			turn = rotate4(board, direction, turn);
			numMoves++;
		}
		// checks which rotate function to use depending on the quadrant



		result1 = horizontal(board);
		result2 = Vertical(board);
		result3 = DiagnolLeft(board);
		result4 = DiagnolRight(board);
		if (result1 == 1 && result2 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result1 == 1 && result3 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result1 == 1 && result4 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result2 == 1 && result1 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result2 == 1 && result3 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result2 == 1 && result4 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result3 == 1 && result1 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result3 == 1 && result2 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result3 == 1 && result4 == 4) {
			printf("Its a tie");
			return 0;
		}
		else if (result4 == 1 && result1 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result4 == 1 && result2 == 2) {
			printf("Its a tie");
			return 0;
		}
		else if (result4 == 1 && result3 == 2) {
			printf("Its a tie");
			system("pause");
			return 0;
		}
		else if (result1 == 1 || result2 == 1 || result3 == 1 || result4 == 1) {
			printf("Player one wins");
			system("pause");
			return 0;

		}
		else if (result1 == 2 || result2 == 2 || result3 == 2 || result4 == 2) {
			printf("Player two wins");
			return 0;
		}

		printf("Number of moves: %d\n", numMoves);

	}
	system("pause");
	return;
}
