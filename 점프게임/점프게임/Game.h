#pragma once
#include "Map.h"

void jump(int map[size_y][size_x], int* score, int a, double* timer);
void itemmaker(int map[size_y][size_x]);
void obstaclemaker(int map[size_y][size_x]);
void obstaclemove(int map[size_y][size_x], int* speed, int* score, int* otime, double* timer);
int gameover(int map[size_y][size_x], int* score, double* timer);
void Score(int* speed, int* score, int* otime);
double StopWatch(time_t start);