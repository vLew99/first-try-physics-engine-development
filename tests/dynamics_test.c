#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dynamics.h"

void Test1() {
	Object2D* player = CreateObject2D(10.0f, (Vector2){1, 2}, (Vector2){2, 2});
	AddForce(player, (Vector2){ 1.0f, 2.2f });
	AddForce(player, (Vector2){ 0.0f, 0.2f });
	AddForce(player, (Vector2){ 0.0f, 0.2f });
	AddForce(player, (Vector2){ 0.0f, 0.2f });
	AddForce(player, (Vector2){ 0.0f, 0.2f });
	AddForce(player, (Vector2){ 0.0f, 0.2f });
	AddForce(player, (Vector2){ 0.0f, 0.0f });

	LL_PrintForward(&player->force_list);

	DeleteObject2D(player);

}


void Test2()
{
	Object2D* player = CreateObject2D(10.0f, (Vector2){1, 2}, (Vector2){2, 2});
	
	real_t x, y;

	for(int i =0 ; i< 10; i++) {
		x = ((rand()%10000)/(float)1000) - 5;
		y = ((rand()%10000)/(float)1000) - 5;
		printf("(%f, %f)\n", x, y);
		AddForce(player, (Vector2){x, y});
	}

	Vector2 sum = TotalForce(player);
	printf("Total Force: (%f, %f)\n", sum.x, sum.y);
}


int main(int argc, char const *argv[])
{

	srand(time(NULL));
	Test2();
	return 0;
}