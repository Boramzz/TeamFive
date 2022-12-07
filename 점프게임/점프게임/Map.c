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
void mapping(int map[size_y][size_x], int* score, double* timer)
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
			
			if (map[i][j] == 4) //아이템 4번, $모양
				printf("$");

		}
		
		printf("□");
		if (i == 1)
			printf(" Score : %d", (*score) / 2);

		if (i == 3)
			printf(" Time : %0.3lf", *timer);


		if (i == 5)
			printf(" 점프 키 : Space bar ");

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

int rankscreen(int map[size_y][size_x], int* score, double* timer)
{
	int key;
	RANK rank[ARR_SIZE];
	FILE* inf;
	// "test.txt"파일을 읽기 모드로 파일 열어보고 실패시 "파일 오픈 실패"라는 글 출력
	if ((fopen_s(&inf, "Rank.txt", "rb")) != 0) 
	{
		printf("파일 오픈 실패\n");
		exit(0);
	}
	//rank구조체 배열에 읽어온 파일 내용을 값 전달
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
	printf("\n    Space bar를 누르면 게임 다시 시작\n");
	printf("    Enter을 누르면 게임이 종료됩니다.\n");
	//커서 없이 키입력을 표현하기위해서 _getch()사용
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			//enter키 입력시 게임 시작
			if (key == 32) 
				break;
			// spacebar키 입력시 게임 종료
			else if (key == 13) 
			{
				system("cls");
				return 0;
			}
				
		}
	}
	system("cls");
	mapbase(map);
	mapping(map, score, timer);
	return 1;
}

void print(RANK arr[])/*삭제*/
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf("%s, %d, %d\n", arr->name, arr->score, arr->time);
		arr++;
	}
}