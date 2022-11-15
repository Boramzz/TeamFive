#include "Game.h"

//점프*******************************************************
void jump(int map[size_y][size_x], int* score, int cot)
{
	int cx, cy;

	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == 2)
			{
				cx = j;
				cy = i;
			}
		}
	}

	if (cot < 4)
	{
		if (map[cy - 1][cx] == 3)
			map[cy][cx] = 0;
		else
		{
			map[cy - 1][cx] = 2; map[cy][cx] = 0;
			mapping(map, score);
		}
	}
	if (cot >= 4)
	{
		if (map[cy + 1][cx] == 3)
			map[cy][cx] = 0;
		else
		{
			map[cy][cx] = 0; map[cy + 1][cx] = 2;
			mapping(map, score);
		}
	}
}

//장애물**********************************************************
void obstaclemaker(int map[size_y][size_x])
{
	int b;
	int obs[5][size_y - 1];

	b = rand() % 4;

	if (b == 0)
	{
		obs[b][size_y - 10] = 0;
		obs[b][size_y - 9] = 0;
		obs[b][size_y - 8] = 0;
		obs[b][size_y - 7] = 0;
		obs[b][size_y - 6] = 0;
		obs[b][size_y - 5] = 0;
		obs[b][size_y - 4] = 0;
		obs[b][size_y - 3] = 0;
		obs[b][size_y - 2] = 3;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
	if (b == 1)
	{
		obs[b][size_y - 10] = 0;
		obs[b][size_y - 9] = 0;
		obs[b][size_y - 8] = 0;
		obs[b][size_y - 7] = 0;
		obs[b][size_y - 6] = 0;
		obs[b][size_y - 5] = 0;
		obs[b][size_y - 4] = 0;
		obs[b][size_y - 3] = 3;
		obs[b][size_y - 2] = 3;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
	if (b == 2)
	{
		obs[b][size_y - 10] = 0;
		obs[b][size_y - 9] = 0;
		obs[b][size_y - 8] = 0;
		obs[b][size_y - 7] = 0;
		obs[b][size_y - 6] = 0;
		obs[b][size_y - 5] = 0;
		obs[b][size_y - 4] = 0;
		obs[b][size_y - 3] = 3;
		obs[b][size_y - 2] = 0;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
	if (b == 3)
	{
		obs[b][size_y - 10] = 3;
		obs[b][size_y - 9] = 3;
		obs[b][size_y - 8] = 3;
		obs[b][size_y - 7] = 3;
		obs[b][size_y - 6] = 3;
		obs[b][size_y - 5] = 3;
		obs[b][size_y - 4] = 3;
		obs[b][size_y - 3] = 0;
		obs[b][size_y - 2] = 0;
		for (int i = 0; i < size_y - 1; i++)
		{
			map[i][size_x - 1] = obs[b][i];
		}
	}
}

//장애물 무빙*****************************************************
void obstaclemove(int map[size_y][size_x], int* speed, int* score, int* otime)
{
	int obstime/*장애물 재로딩 시간*/, run2 = 1, k, cot = 1, time = 0, ctime = 0;
	//점프할 때 좀 더 매끄럽게 하기위해 점프 동작이 끝나면 계속 0으로 초기화시켜줌  
	obstime = rand() % *otime + *otime - 100; //첫 장애물 생성 

	while (run2)
	{
		//점프키를 눌렀을 때
		if (_kbhit())
		{
			k = _getch();
			//p는 점수 오르는 키(점수에 따른 이벤트 발생 여부 확인을 위해 만듬), 이거 해도 속도는 증가 ㄴㄴ 
			if (k == 'p')
				(*score) += 1000;

			if (k == 'j')
			{
				while (cot <= 6)
				{
					//나 
					if (cot == 1)
					{
						system("cls");
						jump(map, score, cot);
						++cot;
						Sleep(30);
					}
					if ((time % 25) == 0 && cot > 1)
					{
						system("cls");
						jump(map, score, cot);
						if (cot == 6)
							time = 0;
						++cot;
					}

					//장애물 
					if ((time % 22) == 0)
					{
						++(*score); //점수
						Score(speed, score, otime);
						for (int i = 0; i < size_y - 1; i++)
						{
							for (int j = 0; j < size_x; j++)
							{
								if (j != 0 && map[i][j] != 2 && (map[i][j - 1] != 2 || map[i][j] == 3))
								{
									map[i][j - 1] = map[i][j];
									map[i][j] = 0;
								}
							}
						}
						system("cls");
						mapping(map, score);
						Sleep(*speed);
					}

					//둘이 겹쳤을 때
					run2 = gameover(map, score);
					if (run2 == 0)
						break;

					//장애물 생성 
					if ((ctime % obstime) == 0)
					{
						obstaclemaker(map);
						system("cls");
						mapping(map, score);
						ctime = 0;
						obstime = rand() % *otime + *otime - 100;
					}
					time++;
					ctime++;
				}
				cot = 1;
			}
		}


		//점프 키를 안눌렀을 때

		//장애물 
		if ((time % 22) == 0)
		{
			++(*score); //점수
			Score(speed, score, otime);
			for (int i = 0; i < size_y - 1; i++)
			{
				for (int j = 0; j < size_x; j++)
				{
					if (j != 0 && map[i][j] != 2 && (map[i][j - 1] != 2 || map[i][j] == 3))
					{
						map[i][j - 1] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
			system("cls");
			mapping(map, score);
			Sleep(*speed);
		}

		//둘이 겹쳤을 때 
		run2 = gameover(map, score);

		//장애물 생성 
		if ((ctime % obstime) == 0)
		{
			obstaclemaker(map);
			system("cls");
			mapping(map, score);
			ctime = 0;
			obstime = rand() % *otime + *otime - 100;
		}
		time++;
		ctime++;
	}
	*speed = spd;
	*otime = oti;
}

//장애물에 맞았을 때**************************************************
int gameover(int map[size_y][size_x], int* score)
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			if (map[i][j] == 2)
				return 1;

			if (i == size_y - 1 && j == size_x - 1 && map[i][j] != 2)
			{
				system("cls");
				mapping(map, score);
				return 0;
			}
		}
	}
}

//몇 점 이상 올라가면 스피드 조절**************************************  
void Score(int* speed, int* score, int* otime)
{
	if ((*score % 100) == 0 && *speed > 20)
	{
		*speed -= 5;
		*otime -= 20;
	}
	if ((*score % 100) == 0 && *speed <= 10)
		(*speed)--;
}