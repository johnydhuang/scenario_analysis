/************************************************************
 * laa_analysis.h -- program to print out "laa_analysis.h". *
 *                                                          *
 * Author:  Johnny                                          *
 *                                                          *
 * Purpose:                                                 *
 *                                                          *
 * Usage:                                                   *
 *                                                          *
 ***********************************************************/

#include <stdio.h>
#define X_LENGTH 20
#define Y_LENGTH 20
#define ROOM_SIZE X_LENGTH*Y_LENGTH
#define LTE_RANGE 5
#define WIFI_RANGE 5
typedef struct{
	double x;
	double y;
}node_location;
int in_range(node_location node_a,node_location node_b, int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1]);
void draw_circle(int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1]);
void show_circle(int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1]);
void result(long long node_link[2][2][2][2]);
