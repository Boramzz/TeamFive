#pragma once
#include "Map.h"
#define ARR_SIZE 5

typedef struct tag_rank {
	char name[10];
	int score;
	int time;
}RANK;

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime);
int eventscreen();
void rankinput(int *score, int *otime);
void sort(RANK arr[]);
int rankscreen(int map[size_y][size_x], int* score);
void print(RANK arr[]); // 삭제하기