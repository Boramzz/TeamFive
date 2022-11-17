#pragma once
#include "Map.h"

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime);
int eventscreen();
void rankinput(int *score, int *otime);
void sort(RANK arr[]);