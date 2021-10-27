#include <iostream>

using namespace std;

char field[128][128];
int n, m;

void dfs(int x, int y)
{
    int dx, dy, a, b;
    field[x][y] = '.';
    for (dx = -1; dx <= 1; dx++)
        for (dy = -1; dy <= 1; dy++)
        {
            a = x + dx;
            b = y + dy;
            if ((a >= 0 && a < n) && (b >= 0 && field[a][b] == 'w'))
                dfs(a, b);
        }
}

int main(void)
{
    int i,j,num=0;
    while (scanf("%d%d",&n,&m)==2)
    {
        /* code */
        num=0;
        for(i=0;i<n;i++)
            scanf("%s",field[i]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(field[i][j]=='w')
                {
                    dfs(i,j);
                    num++;
                }
            }
        printf("%d\n",num);
        for(i=0;i<n;i++)
            printf("%s\n",field[i]);
            
        
    }
    
}