#include <stdio.h>
#include <math.h>
#include <time.h>

int board[5][5];
char temp[5][5];
int getting;
void setting() {
	int i, j;
	getting = 0;
	for(i = 0; i<5; i++) {
		for (j = 0; j<5; j++){
			board[i][j] = rand() % 5;
			temp[i][j] = 'n';
		}
	}
	for (i = 0; i<5; i++){
		for (j = 0; j<5; j++){
			if (board[i][j] != 4)
				board[i][j] = 0;
			if (board[i][j] == 4)
				board[i][j] = 10;
		}
	}
	for (i = 0; i<5; i++){
		for (j = 0; j<5; j++){
			if (i != 0 && i != 4 && j != 0 && j != 4){
				if (board[i][j - 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i][j + 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j + 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j + 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j] >= 10)
					board[i][j]++;
				if (board[i - 1][j] >= 10)
					board[i][j]++;
			}
			else if (i == 0 && j == 0){
				if (board[i + 1][j] >= 10)
					board[i][j]++;
				if (board[i + 1][j + 1] >= 10)
					board[i][j]++;
				if (board[i][j + 1] >= 10)
					board[i][j]++;
			}
			else if (i == 0 && j == 4){
				if (board[i + 1][j] >= 10)
					board[i][j]++;
				if (board[i + 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i][j - 1] >= 10)
					board[i][j]++;
			}
			else if (i == 4 && j == 0){
				if (board[i][j + 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j + 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j] >= 10)
					board[i][j]++;
			}
			else if (i == 4 && j == 4){
				if (board[i - 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i][j - 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j] >= 10)
					board[i][j]++;
			}
			else if (i == 0){
				if (board[i][j - 1] >= 10)
					board[i][j]++;
				if (board[i][j + 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j] >= 10)
					board[i][j]++;
				if (board[i + 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j + 1] >= 10)
					board[i][j]++;
			}
			else if (i == 4){
				if (board[i][j - 1] >= 10)
					board[i][j]++;
				if (board[i][j + 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j] >= 10)
					board[i][j]++;
				if (board[i - 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j + 1] >= 10)
					board[i][j]++;
			}
			else if (j == 0){
				if (board[i][j + 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j + 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j + 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j] >= 10)
					board[i][j]++;
				if (board[i - 1][j] >= 10)
					board[i][j]++;
			}
			else if (j == 4){
				if (board[i][j - 1] >= 10)
					board[i][j]++;
				if (board[i - 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j - 1] >= 10)
					board[i][j]++;
				if (board[i + 1][j] >= 10)
					board[i][j]++;
				if (board[i - 1][j] >= 10)
					board[i][j]++;
			}
		}
	}
}
void display(){
	int i, j;
	printf("-----------------------------------------\n");
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++){
			printf("%c\t", temp[i][j]);
		}
		printf("\n");
	}
	printf("------------------------------------------\n");
	for (i = 0; i < 5; i++){
		for (j = 0; j < 5; j++)
			printf("%d\t", board[i][j]);
		printf("\n");
	}
}
void play(){
	int x, y;
	char b;
	printf("How Much get : %d\n", getting);
	display();
	printf("plz put x, y, and specific button\n");
	printf("specific button -> b = open, p = flag n = repack\n");
	scanf("%d %d %c", &x, &y, &b);
	if (b == 'p'){
		if (board[x][y] >= 10){
			getting++;
			temp[x][y] = b;
			play();
		}
		else {
			temp[x][y] = b;
			play();
		}
	}
	else if (b == 'b'){
		if (board[x][y] < 10){
			if (board[x][y] == 0)
				temp[x][y] = b;
			else {
				temp[x][y] = board[x][y];
				play();
			}
		}
		else if (board[x][y] >= 10)
			return;
	}
	else if (b == 'n'){
		temp[x][y] = 'n';
		play();
	}
	else{
		printf("Error!\n");
		play();
	}
}
int main(){
	while (1){
		srand(time(NULL));
		int starter;
		int board[5][5];
		printf(" To Start Game : 1\tTo Finish Game : other Button\n");
		printf("-------------------------------------------------\n");
		scanf("%d", &starter);
		if (starter != 1){
			break;
		}
		else {
			setting();
			play();
		}
	}
	return 0;
}
