#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define size_x 30
#define size_y 10
#define c_y size_y-2 //내 위치 
#define c_x 2
#define ARR_SIZE 5

typedef struct tag_rank {
	char name[10];
	int score;
	int time;
}RANK;

void mapbase(int map[size_y][size_x]);
void mapping(int map[size_y][size_x], int* score);
int rankscreen(int map[size_y][size_x], int* score);
int getKeyDown();
void print(RANK arr[]); // 삭제하기