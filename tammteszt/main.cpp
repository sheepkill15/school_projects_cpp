#include <fstream>

using namespace std;

int n, m, i, j,t[100][100];
ifstream f("matrix.be");
ofstream g("matrix.ki");

int main()
{
    f>>n>>m;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            f>>t[i][j];
        for(j=m-2; j>=0; j--)
                g<<t[0][j]<<" ";

        for(i=0; i<n-1; i++)
                g<<t[i][0]<<" ";

    for(i=0; i<n; i++)
                g<<t[i][m-2]<<" ";

        for(i=0; i<n; i++)
                g<<t[i][m-1]<<" ";

    return 0;
}