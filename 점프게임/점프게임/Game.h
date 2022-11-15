#pragma once
#include "Map.h"

#define spd 100 //속도 초기값 
#define oti 501 //장애물 재로딩 초기값 

void jump(int map[size_y][size_x], int* score, int a);
void obstaclemaker(int map[size_y][size_x]);
void obstaclemove(int map[size_y][size_x], int* speed, int* score, int* otime);
int gameover(int map[size_y][size_x], int* score);
void Score(int* speed, int* score, int* otime);