#include "Map.h"

//시작 화면*************************************************
void openscreen(int map[size_y][size_x], int* score)
{
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
	printf("                   게임 로딩중입니다.                    \n");
	printf("                                                         \n");
	Sleep(5000);
	mapbase(map);
	system("cls");
	mapping(map, score);
}