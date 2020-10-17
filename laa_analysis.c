/************************************************************
 * laa_analysis.c -- program to print out "laa_analysis.c". *
 *                                                          *
 * Author:  Johnny                                          *
 *                                                          *
 * Purpose:                                                 *
 *                                                          *
 * Usage:                                                   *
 *                                                          *
 ***********************************************************/

#include <laa_analysis.h>
#include <math.h>

int main(){
	int progress=0;
	int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1] = {0};
	long long node_link [2][2][2][2] = {0};
	long long node_link_tmp [2][2][2][2] = {0};
	int node_link_flag[4]= {0};
	node_location node_lte[2];
	node_location node_wifi[2];
	draw_circle(circle_range);
	show_circle(circle_range);
	for(node_lte[0].x = 0; node_lte[0].x < X_LENGTH; node_lte[0].x ++){
		for(node_lte[0].y = 0; node_lte[0].y < Y_LENGTH; node_lte[0].y ++){
			for(node_wifi[0].x = 0; node_wifi[0].x < X_LENGTH; node_wifi[0].x ++){
				for(node_wifi[0].y = 0; node_wifi[0].y < Y_LENGTH; node_wifi[0].y ++){
					for(node_lte[1].x = 0; node_lte[1].x < X_LENGTH; node_lte[1].x ++){
						for(node_lte[1].y = 0; node_lte[1].y < Y_LENGTH; node_lte[1].y ++){
							for(node_wifi[1].x = 0; node_wifi[1].x < X_LENGTH; node_wifi[1].x ++){
								for(node_wifi[1].y = 0; node_wifi[1].y < Y_LENGTH; node_wifi[1].y ++){
									
									if(!in_range(node_lte[0],node_lte[1],circle_range)||!in_range(node_wifi[0],node_wifi[1],circle_range))
										continue;
									if(in_range(node_lte[0],node_wifi[0],circle_range)){
										node_link_flag[0] = 1;
									}else{
										node_link_flag[0] = 0;
									}
									if(in_range(node_lte[1],node_wifi[0],circle_range)){
										node_link_flag[1] = 1;
									}
									else{
										node_link_flag[1] = 0;
									}
									if(in_range(node_lte[0],node_wifi[1],circle_range)){
										node_link_flag[2] = 1;
									}
									else{
										node_link_flag[2] = 0;
									}
									if(in_range(node_lte[1],node_wifi[1],circle_range)){
										node_link_flag[3] = 1;
									}
									else{
										node_link_flag[3] = 0;
									}
									if(node_link_flag[0] == 0 && node_link_flag[1] == 0 && node_link_flag[2] == 0 && node_link_flag[3] == 0)
										continue;
									node_link_tmp[node_link_flag[0]][node_link_flag[1]][node_link_flag[2]][node_link_flag[3]]++;
									if(node_link_tmp[node_link_flag[0]][node_link_flag[1]][node_link_flag[2]][node_link_flag[3]] == 1){
										node_link_tmp[node_link_flag[0]][node_link_flag[1]][node_link_flag[2]][node_link_flag[3]] = 0;
										node_link[node_link_flag[0]][node_link_flag[1]][node_link_flag[2]][node_link_flag[3]]++;
									}
								}
							}
						}
					}
				}
			}
			printf("%d\n",progress);
			progress++;
		}
	}
	result(node_link);
} 



int in_range(node_location node_a,node_location node_b, int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1]){
	if((node_a.x - node_b.x)>LTE_RANGE||(node_a.x - node_b.x)<-LTE_RANGE||(node_a.y - node_b.y)>LTE_RANGE||(node_a.y - node_b.y)<-LTE_RANGE)
		return 0;
	else
		return circle_range[(int)(LTE_RANGE + node_a.x - node_b.x)][(int)(LTE_RANGE + node_a.y - node_b.y)];
}

void show_circle(int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1]){
	int x, y;
	for(x = 0; x < LTE_RANGE*2+1; x++){
		for(y = 0; y < LTE_RANGE*2+1; y++){
			printf("%d",circle_range[x][y]);
		}
		printf("\n");
	}
}

void draw_circle(int circle_range[LTE_RANGE*2+1][LTE_RANGE*2+1]){
	int x, y;
	for(x = 0; x < LTE_RANGE*2+1; x++){
		for(y = 0; y < LTE_RANGE*2+1; y++){
			double length;
			double x_0 = LTE_RANGE, y_0 = LTE_RANGE;
			length = sqrt((x-x_0)*(x-x_0)+(y-y_0)*(y-y_0));
			if(length <= LTE_RANGE)
				circle_range[x][y] = 1;
			else
				circle_range[x][y] = 0;
		}
	}
}

void result(long long node_link[2][2][2][2]){
	double sum = 0;
	int i,j,k,l;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			for(k = 0; k < 2; k++){
				for(l = 0; l < 2; l++){
					sum += node_link[i][j][k][l];
				}
			}
		}
	}
	printf("1 : %d\t%f\n",node_link[0][0][0][0],(double)(node_link[0][0][0][0]/sum)*100);
	printf("2 : %d\t%f\n",node_link[1][0][0][0],(double)(node_link[1][0][0][0]/sum)*100);
	printf("3 : %d\t%f\n",node_link[0][1][0][0],(double)(node_link[0][1][0][0]/sum)*100);
	printf("4 : %d\t%f\n",node_link[0][0][1][0],(double)(node_link[0][0][1][0]/sum)*100);
	printf("5 : %d\t%f\n",node_link[0][0][0][1],(double)(node_link[0][0][0][1]/sum)*100);
	printf("6 : %d\t%f\n",node_link[1][1][0][0],(double)(node_link[1][1][0][0]/sum)*100);
	printf("7 : %d\t%f\n",node_link[1][0][1][0],(double)(node_link[1][0][1][0]/sum)*100);
	printf("8 : %d\t%f\n",node_link[0][1][0][1],(double)(node_link[0][1][0][1]/sum)*100);
	printf("9 : %d\t%f\n",node_link[0][0][1][1],(double)(node_link[0][0][1][1]/sum)*100);
	printf("10 : %d\t%f\n",node_link[1][0][0][1],(double)(node_link[1][0][0][1]/sum)*100);
	printf("11 : %d\t%f\n",node_link[0][1][1][0],(double)(node_link[0][1][1][0]/sum)*100);
	printf("12 : %d\t%f\n",node_link[1][1][1][0],(double)(node_link[1][1][1][0]/sum)*100);
	printf("13 : %d\t%f\n",node_link[1][1][0][1],(double)(node_link[1][1][0][1]/sum)*100);
	printf("14 : %d\t%f\n",node_link[1][0][1][1],(double)(node_link[1][0][1][1]/sum)*100);
	printf("15 : %d\t%f\n",node_link[0][1][1][1],(double)(node_link[0][1][1][1]/sum)*100);
	printf("16 : %d\t%f\n",node_link[1][1][1][1],(double)(node_link[1][1][1][1]/sum)*100);


}