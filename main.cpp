#include <stdio.h>

static int W, N, M;
static int bestA = 0, bestL = 0;
static int psa[1002][1002]= {0};
static int a[1002][1002]=  {0};

struct coord{
    int x;
    int y;
};

void GetPrefixSum();
int SumOfCoords(coord array[]);

int main() {
    int xi, yi, mi;
    scanf("%d %d %d", &W, &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &xi, &yi, &mi);
        a[yi+1][xi+1] = mi;
    }
    GetPrefixSum();
    coord coords[] = {{1,1},{0,1001},{3,3},{1001,1001}};
    printf("sum of rectangle: %d",SumOfCoords(coords));



}

void GetPrefixSum()
{
    //first row
    for (int i = 1; i < W; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    //first column
    for (int i = 1; i < W; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];

    for(int i =1;i<W;i++)
    {
        for(int j=1;j<W;j++)
        {
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
        }
    }
    for (int i = 1; i < W; i++) {
        for (int j = 1; j < W; j++)
            printf("%d ",psa[i][j]);
        printf("\n");
    }
}


//coordinates must create a quader
//order of array: upper left corner, upper right corner,lower left corner,lower right corner

//formula for calculating sum of rectangle with the upper left corner at (c1|r1)
//and the lower right corner at (c2|r2)
//ps[c2+1][r2+1] - ps[c1][r2+1] - ps[c2+1][r1] + ps[c1][r1] = sumOfRectangle
int SumOfCoords(coord array[])
{
    int c1 = array[0].x;
    int c2 = array[3].x;
    int r1 = array[0].y;
    int r2 = array[3].y;
    //array[0] upper left corner has to be (0|0)
    //array[1] upper right corner
    //array[2] lower left corner
    //array[3] lower right corner
    return psa[c2 + 1][r2 + 1] - psa[c1][r2 + 1] - psa[c2 + 1][r1] + psa[c1][r1];
}
void GenerateQuader()
{
    
}