// Program	: CPE - p10221 Satellites
// Author	: Timothy William
// Compiled	: 03/22/2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	double r = 6440.0, s, a, R, D, arc_dist, chord_dist;
	char type[3];

	scanf("%lf %lf %s", &s, &a, &type[0]);
	
	// Convert "min" to "degree"
	if(strcmp(type, "min") == 0)
		a = a / 60.0;

	R = r + s;

	arc_dist = M_PI * 2.0 * R * (a / 360.0);
	chord_dist = 2.0 * R * sin((a / 2.0) * (M_PI / 180.0));
	printf("%.6lf %.6lf\n", arc_dist, chord_dist);
}
