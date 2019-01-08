#include <stdio.h>

static int W, N, M;
static int psa[1002][1002]= {0};
static int a[1002][1002]=  {0};
static int res[2];
struct coord{
    int x;
    int y;
};

void GetPrefixSum();
int SumOfCoords(coord array[]);
void GenerateQuader();

int main() {
    int xi, yi, mi;
    scanf("%d %d %d", &W, &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &xi, &yi, &mi);
        a[xi+1][yi+1] = mi;
    }
    GetPrefixSum();
    GenerateQuader();

    printf("%d %d",res[0],res[1]);




}

void GetPrefixSum()
{
    for (int x = 1; x <= W; x++)
    {
        for (int y = 1; y <= W; y++)
        {
            psa[x][y] = psa[x - 1][y] + psa[x][y - 1] - psa[x - 1][y - 1] + a[x][y];
        }
    }

}

int SumOfCoords(coord array[])
{
    int c1 = array[0].x;
    int c2 = array[1].x;
    int r1 = array[0].y;
    int r2 = array[1].y;


    return psa[c2][r2]-psa[c2][r1-1]-psa[c1-1][r2]+psa[c1-1][r1-1];
}
void  GenerateQuader()
{

    for(int i = 1;i<=W;i++)
    {
        //row
        for(int i1=1;(i1+(i-1))<W;i1++)
        {
            //column
            for(int i2=1;(i2+(i-1))<W;i2++)
            {
                //implement checks if size of quader is not out of bounds
                //check i1+i and i2+1 to be smaller than size of forrest
                coord coords[] = {{i1,i2},{i1+(i-1),i2+(i-1)}};
                if(coords[0].x < W && coords[0].y < W && coords[1].x < W && coords[1].y < W) {
                    long sum = SumOfCoords(coords);
                    if (sum == M){res[0]=sum; res[1] = i; return;}
                    else if (sum > res[0] && sum < M) {
                        res[0] = sum;
                        res[1] = i;
                    }
                }


            }


        }


    }
    return;
}