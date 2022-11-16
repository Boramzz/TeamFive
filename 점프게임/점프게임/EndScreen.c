#include "EndScreen.h"

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime)
{
	int answer;

	system("cls");
	printf("\n\t\tGame over~~\n\n\t       You score : %d\n\n", *score / 2);
	printf("\n\t\t re game?\n\n");
	printf("\n\t\t 1.go\n\n");
	printf("\n\t\t 2.exit\n");
	scanf("%d", &answer);
	if (answer == 1)
	{
		system("cls");
		mapbase(map);
		mapping(map, score);
		return 1;
	}
	/*else if (answer == 8282)
	{
		*speed = 10;
		*otime = 181;
		system("cls");
		mapbase(map);
		mapping(map, score);
		return 1;
	}*/
	else
	{
		system("cls");
		return 0;
	}
}
//이벤트 화면*************************************************************
int eventscreen()
{


	return 0;
}

void rankscreen()
{

}

void rankinput(int* score, int* otime)
{
	RANK cus;

	system("cls");
	printf("\n\t\t 기록을 달성했습니다.\n\n\t       You score : %d\n\n", *score / 2);
	printf("\n\t\t 이름을 입력해주세요.\n\n");
	scanf("%s", &cus.name);
	cus.score = *score;
	cus.time = *otime;

}