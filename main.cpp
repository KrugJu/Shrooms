#include <stdio.h>

static int W, N, M;
static int bestA = 0, bestL = 0;
static int ps[1002][1002];
static int a[1002][1002];

struct coord{
    int x;
    int y;
};

int SumOfCoords(coord array[]);

int main() {
    int xi, yi, mi;
    scanf("%d %d %d", &W, &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &xi, &yi, &mi);
        a[yi][xi] = mi;
    }
    coord coords[] = {{0,0},{0,N-1},{N-1,0},{N-1,N-1}};

    //calculating the prefix sum
    for(int i=0;i<1002;i++)
    {
        for(int i1=0;i1<1002;i1++)
        {

            if(i == 0 && i1 == 0){
                ps[i][i1] = a[i][i1];
            }
            else{
                if(i1 == 0)
                    ps[i][i1] = ps[i-1][1002-1] + a[i][i1];
                else{
                    ps[i][i1] = ps[i][i1-1] + a[i][i1];
                }
            }

        }

    }

    printf("prefixsum %d",SumOfCoords(coords));

}
//coordinates must create a quader
//order of array: upper left corner, upper right corner,lower left corner,lower right corner
int SumWithinCoords(coord array[],int count)
{
    coord leftRectangle[]  ={ {0,0},{0,array[0].y},{N-1,0},{N-1,array[0].y   } };
    coord upperRectangle[] ={};
    coord surroundingRectangle[] = {};



}
//formula for calculating sum of rectangle with the upper left corner at (c1|r1)
//and the lower right corner at (c2|r2)
//ps[c2+1][r2+1] - ps[c1][r2+1] - ps[c2+1][r1] + ps[c1][r1] = sumOfRectangle
int SumOfCoords(coord array[])
{
    //array[0] upper left corner has to be (0|0)
    //array[1] upper right corner
    //array[2] lower left corner
    //array[3] lower right corner
    return (ps[array[3].x+1][array[3].y+1] - ps[array[0].x][array[3].y]
    - ps[array[3].x+1][array[0].y] + ps[array[0].x][array[0].y]);
}