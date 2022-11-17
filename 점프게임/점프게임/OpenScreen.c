#include "Map.h"

//시작 화면*************************************************
void openscreen(int map[size_y][size_x], int* score)
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
	mapping(map, score);
}