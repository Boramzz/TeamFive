#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

struct rank {
	char name[20];
	int time;
	int score;
}; 
typedef struct rank RANK;

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime);
int eventscreen();
void rankscreen();
void rankinput(int* score, int* otime);