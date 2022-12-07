#include "Map.h"

//시작 화면*************************************************
void openscreen(int map[size_y][size_x], int* score, double* timer)
{
	int key;

	printf("                                                         \n");
	printf("          □□□  □    □ □      □  □□□            \n");
	printf("              □  □    □ □□  □□ □    □           \n");
	printf("              □  □    □ □  □  □ □    □           \n");
	printf("             □   □    □ □  □  □ □□□             \n");
	printf("           □       □□   □  □  □ □                 \n");
	printf("                                      □                 \n");
	printf("                 □□□       □      □      □ □□□□\n");
	printf("               □            □□     □□  □□ □      \n");
	printf("               □  □□□   □  □    □  □  □ □□□□\n");
	printf("               □      □  □□□□   □  □  □ □      \n");
	printf("                 □□□   □      □  □  □  □ □□□□\n");
	printf("                                                         \n");
	printf("             Enterkey를 입력하면 시작합니다.             \n");
	printf("                                                         \n");
	// 게임로딩 시간을 없애니 게임 바로 시작되어서 Enter키를 누르면 게임 시작하는 것으로 바꾸었습니다.
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 13)
				break;
		}
	}
	//Sleep(5000);
	
	mapbase(map);
	system("cls");
	mapping(map, score, timer);
	
}