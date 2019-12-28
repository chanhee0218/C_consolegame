#pragma warning (disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int map[20][20] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,1},
	{1, 0, 9, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 3, 0,1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,1},
	{1, 0, 2, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,1},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1}
};

int PlayerX, PlayerY;

void printMap() {
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			switch (map[i][j])
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
				Sleep(1000);
			case 0: printf("  "); break;
			case 1: Sleep(40); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); printf("■"); break;
			case 2:  printf("●"); break;
			case 3: SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); printf("○"); break;
			case 9: printf("★");
				PlayerX = j;
				PlayerY = i;
				break;
			}
		}
		printf("\n");
	}
}

void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x * 2;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw(int x, int y, char ch[]) {
	gotoxy(x, y);
	printf("%s", ch);

}

void movePlayer(int dx, int dy) {

	int nextX = PlayerX + dx;

	int nextY = PlayerY + dy;

	if (map[nextY][nextX] == 0 || map[nextY][nextX] == 2) {

		if (map[nextY][nextX] == 2) {

			if (map[nextY + dy][nextX + dx] != 0 && map[nextY + dy][nextX + dx] != 3)

				return;

			if (map[nextY + dy][nextX + dx] == 3) {

				draw(nextX + dx, nextY + dy, "♥");

				map[nextY + dy][nextX + dx] = 4;

			}

			else {

				draw(nextX + dx, nextY + dy, "●");

				map[nextY + dy][nextX + dx] = 2;

			}

		}

		draw(PlayerX, PlayerY, "  ");

		map[PlayerY][PlayerX] = 0;



		draw(nextX, nextY, "★");

		map[nextY][nextX] = 9;

		PlayerX = nextX;

		PlayerY = nextY;

	}

}

int getBallCount() {

	int i, j, cnt = 0;

	for (i = 0; i < 20; i++) {

		for (j = 0; j < 20; j++) {

			if (map[i][j] == 2)

				cnt += 1;



		}

	}

	return cnt;

}

int main() {

	printMap();
	gotoxy(23, 4);

	printf("게임 재밌게 즐기세요");

	char input;

	while (getBallCount() > 0) {



		input = _getch();

		switch (input)

		{

		case 'w':

		case 'W':

			movePlayer(0, -1);

			break;

		case 's':

		case 'S':

			movePlayer(0, 1);

			break;

		case 'd':

		case 'D':

			movePlayer(1, 0);

			break;

		case 'a':

		case 'A':

			movePlayer(-1, 0);

			break;

		}

	}

	draw(2, 4, "GameClear");

	printf("종료하려면 아무키나 누르시오");

	_getch();



}