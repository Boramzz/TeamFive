#include "EndScreen.h"

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime, double* timer)
{
	int answer;

	if (*score >= 3000) //점수가 3000이상이면 랭크 기록 화면으로 이동 
	{
		rankinput(score, timer);
	}

	system("cls");
	printf("\n\t\tGame over~~\n\n\t       You score : %d\n\n\t       You time : %0.lf\n\n", *score / 2, *timer);
	printf("\n\t\t re game?\n\n");
	printf("\n\t\t 1.go\n\n");
	printf("\n\t\t 2.ranking\n\n");
	printf("\n\t\t 3.exit\n");
	scanf("%d", &answer);
	if (answer == 1)
	{
		system("cls");
		mapbase(map);
		mapping(map, score, timer);
		return 1;
	}
	else if (answer == 2)
	{
		system("cls");
		rankscreen(map, score, timer);
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
void rankinput(int *score, double* timer)
{
	double itimer;
	RANK user;
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
	//파일 종료
	fclose(inf);

	system("cls");
	printf("\n\t\t 기록을 달성했습니다.\n\n\t       You score : %d\n\n\t       You time : %0.lf\n\n", *score / 2, *timer);
	printf("\n\t\t 이름을 입력해주세요.\n\n");
	// 이름 입력
	scanf("%s", user.name); 
	user.score = *score;
	itimer = *timer;
	user.time = (int)itimer;
	// 5등과 기록한 점수와 시간을 비교 점수가 같으면 시간이 짧으면 5등 점수를 기록점수로 기록
	if (rank[ARR_SIZE - 1].time > user.time || rank[ARR_SIZE - 1].time == 0)
	{
		if (rank[ARR_SIZE - 1].score <= user.score) 
		{
			rank[ARR_SIZE - 1] = user;
		}
	}
	sort(rank);
}

//랭크 정렬
void sort(RANK arr[]) // 정렬되지 않은 상태에서 같은 키값을 가진 원소의 순서가 정렬 후에도 유지하기위해서 버블정렬 사용
{
	FILE* outf;
	RANK temp;
	// 랭킹은 점수가 중요해서 점수를 나중에 정렬하고 시간 정렬 부터 시작
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
	// 랭킹 점수 정렬
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
	//"test.txt"파일을 쓰기 모드로 파일 열어보고 실패시 "파일 오픈 실패"라는 글 출력
	if ((fopen_s(&outf, "Rank.txt", "wb")) != 0) 
	{
		printf("file open error \n");
		exit(0);
	}
	//rank구조체 배열의 내용을 파일 내용으로 수정하기
	for (int i = 0; i < ARR_SIZE; i++)
	{
		fprintf(outf, "%s %d %d\n", arr[i].name, arr[i].score, arr[i].time);
	}
	//파일 종료
	fclose(outf); 
}

