#pragma once
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define size_x 30
#define size_y 10
#define c_y size_y-2 //³» À§Ä¡ 
#define c_x 2

void mapbase(int map[size_y][size_x]);
void mapping(int map[size_y][size_x], int* score);