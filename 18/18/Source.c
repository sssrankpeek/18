#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<math.h>
struct point {
	float x;
	float y;
	char name;
	float x1;
	float y1;
	char name1;
};
typedef struct point Point;
void put_point(Point z);
void main()
{
	setlocale(LC_ALL, "RUS");
	Point b, a, c;
	a = (Point){ 1.f,2.f,'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	c.name = 'C'; c.x = 2; c.y = -1;
	put_point(b);
	put_point(c);
	dist(b, c);
}
void put_point(Point z)
{
	printf("point %c (%.1f, %.1f)",z.name,z.x,z.y);
}

float dist(Point z, Point w)
{
	float y;
	y = sqrt(pow(z.x-w.x,2)+pow(z.y-w.y,2));
	printf("rasstoyanie = %.2f", y);
	return y;
}
float newpoint(Point z, Point w)
{
	float x,y;
	x = (z.x + w.x) / 2;
	y = (z.y + w.y) / 2;
}