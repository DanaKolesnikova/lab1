#include <stdio.h>
#define PI 3.1415592654
#define limit 0.0000000001
double conversion(double x)
{
	double radian = x * PI / 180;
	return radian;
}
double function(double degree)
{
	int n = 1;
	double value = 1;
	double value_1 = 1;
	double temporary = 0;
	while (value > limit)
	{
		value *= (degree*degree/(2 * n-1)*2*n);
		if (n % 2 != 1)
		{
			temporary = value;
		}
		else
		{
			temporary = -value;
		}
		n++;
			value_1 += temporary;
	}
	return value_1;
}
int main(void)
{
	double cos_ref[5];
	double cos;
	double result;
	double corner[5] = { 0,30,60,90,180 };
	double cos_corner[5] = { 1, 0.866025404, 0.5, 0, -1};
	double e = 0.01;
	for (int i = 0; i < 5; i++)
	{
		double radian = conversion(corner[i]);
		cos = function(radian);
		if ((cos - cos_corner[i]) > e)
		{
			result = false;
			printf("Error\n");
		}
		else
		{
			result = true;
		cos_ref[i] = cos_corner[i];
	}
}
	for (int i = 0; i < 5; i++);
	printf ("The values obtained are correct\n", cos_ref);
		return result;
	}