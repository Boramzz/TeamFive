#include "Map.h"

//¸Êº£ÀÌ½º**************************************************
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

//¸ÊÇÎ******************************************************
void mapping(int map[size_y][size_x], int* score)
{
	printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n");
	for (int i = 0; i < size_y; i++)
	{
		printf("¡à");
		for (int j = 0; j < size_x - 5; j++)
		{
			if (map[i][j] == 0)
				printf("  ");

			if (map[i][j] == 1)
				printf("¡à");

			if (map[i][j] == 2)
				printf("¡Û");

			if (map[i][j] == 3)
				printf("¡à");
		}
		printf("¡à");
		if (i == 1)
			printf(" Score : %d", (*score) / 2);

		if (i == 5)
			printf(" Á¡ÇÁ Å° : j Å°");

		printf("\n");
	}
	if (*score >= 1000)
	{
		printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n");
		printf("¡à  ¡à¡à¡à              ¡à¡à¡à  ¡à\n");
		printf("¡à ¡à    ¡à            ¡à    ¡à ¡à\n");
		printf("¡à¡à      ¡à          ¡à      ¡à¡à\n");
		printf("¡à         ¡à        ¡à         ¡à\n");
		printf("¡à      ¡à¡à¡à      ¡à¡à¡à      ¡à\n");
	}
	if (*score >= 2000)
	{
		printf("¡à     ¡à    ¡à    ¡à    ¡à     ¡à\n");
		printf("¡à     ¡à     ¡à¡à¡à     ¡à     ¡à\n");
		printf("¡à      ¡à    ¡à  ¡à    ¡à      ¡à\n");
		printf("¡à        ¡à¡à      ¡à¡à        ¡à\n");
		printf("¡à                              ¡à\n");
		printf("¡à  ¡à¡à¡à              ¡à¡à¡à  ¡à\n");
	}
	if (*score >= 3000)
	{
		printf("¡à ¡à    ¡à¡à¡à¡à¡à¡à¡à¡à    ¡à ¡à\n");
		printf("¡à ¡à                        ¡à ¡à\n");
		printf("¡à ¡à                        ¡à ¡à\n");
		printf("¡à ¡à    ¡à¡à¡à¡à¡à¡à¡à¡à    ¡à ¡à\n");
		printf("¡à  ¡à¡à¡à              ¡à¡à¡à  ¡à\n");
		printf("¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à¡à\n");
	}
	/*½ÇÇè¿ë ¸Ê
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

int rankscreen()
{
	RANK rank[ARR_SIZE];
	FILE* inf;
	if ((fopen_s(&inf, "Rank.txt", "rb")) != 0)
	{
		printf("ÆÄÀÏ ¿ÀÇÂ ½ÇÆÐ\n");
		exit(0);
	}


	for (int i = 0; i < ARR_SIZE; i++)
	{
		fscanf(inf, "%s %d %d\n", rank[i].name, &rank[i].score, &rank[i].time);
	}

	fclose(inf);

	return 0;
}

void print(RANK arr[])
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		printf("%s, %d, %d\n", arr->name, arr->score, arr->time);
		arr++;
	}
}