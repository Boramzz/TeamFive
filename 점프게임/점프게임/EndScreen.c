#include "EndScreen.h"

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime)
{
	int answer;

	if (*score >= 3000)
	{
		rankinput(score, otime);
	}

	system("cls");
	printf("\n\t\tGame over~~\n\n\t       You score : %d\n\n", *score / 2);
	printf("\n\t\t re game?\n\n");
	printf("\n\t\t 1.go\n\n");
	printf("\n\t\t 2.ranking\n\n");
	printf("\n\t\t 3.exit\n");
	scanf("%d", &answer);
	if (answer == 1)
	{
		system("cls");
		mapbase(map);
		mapping(map, score);
		return 1;
	}
	else if (answer == 2)
	{
		system("cls");
		rankscreen(map, score);
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

//랭크 입력
void rankinput(int *score, int *otime)
{
	RANK user;
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
	printf("\n\t\t 기록을 달성했습니다.\n\n\t       You score : %d\n\n", *score / 2);
	printf("\n\t\t 이름을 입력해주세요.\n\n");
	scanf("%s", &user.name);
	user.score = *score;
	user.time = *otime;

	if (rank[ARR_SIZE - 1].score <= user.score)
	{
		if (rank[ARR_SIZE - 1].time > user.time || rank[ARR_SIZE - 1].time == 0)
		{
			rank[ARR_SIZE - 1] = user;
		}
	}
	sort(rank);
}

//랭크 정렬
void sort(RANK arr[]) //정렬 stable 때문에 버블정렬 사용
{
	FILE* outf;
	RANK temp;

	for (int i = 0; i < ARR_SIZE - 1; i++)
	{
		for (int j = 0; j < ARR_SIZE - 1 - i; j++)
		{
			if (arr[j].time > arr[j + 1].time)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < ARR_SIZE - 1; i++)
	{
		for (int j = 0; j < ARR_SIZE - 1 - i; j++)
		{
			if (arr[j].score < arr[j + 1].score)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	if ((fopen_s(&outf, "Rank.txt", "wb")) != 0)
	{
		printf("file open error \n");
		exit(0);
	}

	for (int i = 0; i < ARR_SIZE; i++)
	{
		fprintf(outf, "%s %d %d\n", arr[i].name, arr[i].score, arr[i].time);
	}
	fclose(outf);
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
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 13)
				break;
		}
	}
	system("cls");
	mapbase(map);
	mapping(map, score);
	return 1;
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