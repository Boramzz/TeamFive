#include "Map.h"

//╕╩║г└╠╜║**************************************************
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

//╕╩╟╬******************************************************
void mapping(int map[size_y][size_x], int* score)
{
	printf("брбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбр\n");
	for (int i = 0; i < size_y; i++)
	{
		printf("бр");
		for (int j = 0; j < size_x - 5; j++)
		{
			if (map[i][j] == 0)
				printf("  ");

			if (map[i][j] == 1)
				printf("бр");

			if (map[i][j] == 2)
				printf("б█");

			if (map[i][j] == 3)
				printf("бр");
		}
		printf("бр");
		if (i == 1)
			printf(" Score : %d", (*score) / 2);

		if (i == 5)
			printf(" ┴б╟┴ ┼░ : j ┼░");

		printf("\n");
	}
	if (*score >= 1000)
	{
		printf("брбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбр\n");
		printf("бр  брбрбр              брбрбр  бр\n");
		printf("бр бр    бр            бр    бр бр\n");
		printf("брбр      бр          бр      брбр\n");
		printf("бр         бр        бр         бр\n");
		printf("бр      брбрбр      брбрбр      бр\n");
	}
	if (*score >= 2000)
	{
		printf("бр     бр    бр    бр    бр     бр\n");
		printf("бр     бр     брбрбр     бр     бр\n");
		printf("бр      бр    бр  бр    бр      бр\n");
		printf("бр        брбр      брбр        бр\n");
		printf("бр                              бр\n");
		printf("бр  брбрбр              брбрбр  бр\n");
	}
	if (*score >= 3000)
	{
		printf("бр бр    брбрбрбрбрбрбрбр    бр бр\n");
		printf("бр бр                        бр бр\n");
		printf("бр бр                        бр бр\n");
		printf("бр бр    брбрбрбрбрбрбрбр    бр бр\n");
		printf("бр  брбрбр              брбрбр  бр\n");
		printf("брбрбрбрбрбрбрбрбрбрбрбрбрбрбрбрбр\n");
	}
	/*╜╟╟ш┐ы ╕╩
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