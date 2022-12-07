#pragma once
#include "Map.h"

int endscreen(int map[size_y][size_x], int* speed, int* score, int* otime, double* timer);
int eventscreen();
void rankinput(int *score, double *timer);
void sort(RANK arr[]);