#include "OpenScreen.h"
#include "Game.h"
#include "EndScreen.h"

//∏ﬁ¿Œ******************************************************
int main()
{
	int run = 1;
	int map[size_y][size_x];
	int speed = spd;
	int score = 0;
	int otime = oti;
	double timer = 0;

	srand((unsigned)time(NULL));

	openscreen(map, &score, &timer);


	while (run)
	{
		obstaclemove(map, &speed, &score, &otime, &timer);
		run = endscreen(map, &speed, &score, &otime, &timer);

		score = 0;
	}

	

	return 0;
}