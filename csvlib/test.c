#include "csv_io.h"
#include <stdio.h>



int main()
{
    printf("=====Testing CSV Library=====\n");

    int a = csv_getInt("temp");
    int b = csv_getInt("voltage");
    int c = csv_getInt("current");
    int d = csv_getInt("torque");
    int e = csv_getInt("rpm");
    int f = csv_getInt("duty");
    int g = csv_getInt("direction");
    int h = csv_getInt("temperatu");


    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e, f, g, h);
    return 0;
}