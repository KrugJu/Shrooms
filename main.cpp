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
        a[xi][yi] = mi;
    }
    GetPrefixSum();
    GenerateQuader();

    printf("%d %d",res[0],res[1]);




}

void GetPrefixSum()
{
    /*
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= W; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }*/
    //printf("---------------------------------\n");
    //reihenweise
    for (int i = 1; i <= W; i++){
        for(int j =1;j<=W;j++){
            psa[i][j] =psa[i][j-1] + a[i][j];
        }
    }
    /*
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= W; j++)
            printf("%d ",psa[i][j]);
        printf("\n");
    }
    printf("--------------------------\n");*/
    //spaltenweise
    for (int i = 1; i <= W; i++){
        for(int j =1;j<=W;j++){
            psa[j][i] = psa[j-1][i] + psa[j][i];
        }
    }
    /*
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= W; j++)
            printf("%d ",psa[i][j]);
        printf("\n");
    }*/
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

    bool skip=false;
    for(int i = 1;i<=W;i++)
    {
        //row
        for(int i1=0;i1<W;i++)
        {
            //column
            for(int i2=0;i2<W;i++)
            {
                //implement checks if size of quader is not out of bounds
                //check i1+i and i2+1 to be smaller than size of forrest
                coord coords[] = {{i1,i2},{i1+(i-1),i2+(i-1)}};

                if(coords[0].x < W && coords[0].y < W && coords[1].x < W && coords[1].y < W) {
                    int sum = SumOfCoords(coords);
                    if (sum == M){res[0]=sum; res[1] = i; return;}
                    else if (sum > res[0] && sum < M) {
                        res[0] = sum;
                        res[1] = i;
                    }
                    //printf("x1: %d y1: %d x1: %d y1: %d--sum:%d\n",coords[0].x,coords[0].y,coords[1].x,coords[0].y,sum);

                }
                else{skip=true; break;}
            }
            if(skip)
            {
                skip = false;
                break;
            }

        }


    }
    return;
}