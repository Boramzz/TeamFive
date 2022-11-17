#include "Map.h"

//맵베이스**************************************************
void mapbase(int map[size_y][size_x])
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (i == (size_y - 1))
				map[i][j] = 1;

			else
				map[i][j] = 0;
		}
	}

	map[c_y][c_x] = 2;
}

//맵핑******************************************************
void mapping(int map[size_y][size_x], int* score)
{
	printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	for (int i = 0; i < size_y; i++)
	{
		printf("□");
		for (int j = 0; j < size_x - 5; j++)
		{
			if (map[i][j] == 0)
				printf("  ");

			if (map[i][j] == 1)
				printf("□");

			if (map[i][j] == 2)
				printf("○");

			if (map[i][j] == 3)
				printf("□");
		}
		printf("□");
		if (i == 1)
			printf(" Score : %d", (*score) / 2);

		if (i == 5)
			printf(" 점프 키 : j 키");

		printf("\n");
	}
	if (*score >= 1000)
	{
		printf("□□□□□□□□□□□□□□□□□\n");
		printf("□  □□□              □□□  □\n");
		printf("□ □    □            □    □ □\n");
		printf("□□      □          □      □□\n");
		printf("□         □        □         □\n");
		printf("□      □□□      □□□      □\n");
	}
	if (*score >= 2000)
	{
		printf("□     □    □    □    □     □\n");
		printf("□     □     □□□     □     □\n");
		printf("□      □    □  □    □      □\n");
		printf("□        □□      □□        □\n");
		printf("□                              □\n");
		printf("□  □□□              □□□  □\n");
	}
	if (*score >= 3000)
	{
		printf("□ □    □□□□□□□□    □ □\n");
		printf("□ □                        □ □\n");
		printf("□ □                        □ □\n");
		printf("□ □    □□□□□□□□    □ □\n");
		printf("□  □□□              □□□  □\n");
		printf("□□□□□□□□□□□□□□□□□\n");
	}
	/*실험용 맵
	printf("\n\n\n");
	for(int i=0;i<size_y;i++)
	{
		for(int j=0;j<size_x;j++)
		{
			if(map[i][j]==0)
			printf("%d",map[i][j]);

			if(map[i][j]==1)
			printf("%d",map[i][j]);

			if(map[i][j]==2)
			printf("%d",map[i][j]);

			if(map[i][j]==3)
			printf("%d",map[i][j]);
		}
		printf("\n");
	}*/
}

int rankscreen(int map[size_y][size_x], int* score)
{
	int key;
	RANK rank[ARR_SIZE];
	FILE* inf;
	if ((fopen_s(&inf, "Rank.txt", "rb")) != 0)
	{
		printf("파일 오픈 실패\n");
		exit(0);
	}


	for (int i = 0; i < ARR_SIZE; i++)
	{
		fscanf(inf, "%s %d %d\n", rank[i].name, &rank[i].score, &rank[i].time);
	}

	fclose(inf);

	system("cls");
	printf("\n\t\tRanking\n\n");
	printf("\t등수 이름        점수  시간\n");

	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf("\n\t%2d등 %-10s %5d %5d\n", i + 1, rank[i].name, rank[i].score, rank[i].time);
	}

	printf("\n");
	printf("\n    enter을 누르면 게임 다시 시작\n");
	printf("    spacebar를 누르면 게임이 종료됩니다.\n");
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 13)
				break;
			else if (key == 32)
			{
				system("cls");
				return 0;
			}
				
		}
	}
	system("cls");
	mapbase(map);
	mapping(map, score);
	return 1;
}

int getKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void print(RANK arr[])/*삭제*/
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf("%s, %d, %d\n", arr->name, arr->score, arr->time);
		arr++;
	}
}