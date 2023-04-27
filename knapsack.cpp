// Fractional knapsack

#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
void sort(int p[], int w[], float r[], int n)
{
  for (int step = 1; step < n; step++)
  {
    for (int i = 0; i < n - step; i++)
    {
      if (r[i] < r[i + 1])
      {
        float temp = r[i];
        r[i] = r[i + 1];
        r[i + 1] = temp;

        swap(&p[i], &p[i + 1]);
        swap(&w[i], &w[i + 1]);
      }
    }
  }
}
void knapsack(int p[], int w[], int n, int m)
{
  float r[n];
  int i;
  float ratio;
  for (i = 0; i < n; i++)
  {
    ratio = float(p[i]) / float(w[i]);
    r[i] = ratio;
  }

  sort(p, w, r, n);

  float P = 0; // profit

  for (i = 0; i < n; i++)
  {
    if (m >= 0 && w[i] <= m)
    {
      m = m - w[i];
      P = P + p[i];
    }
    else
    {
      P = P + float(p[i]) * m / w[i];
    }
  }
  cout << "Profit= " << P << endl;
}
int main()
{
  int p[] = {5, 10, 15, 7, 8, 9, 4};
  int w[] = {1, 3, 5, 4, 1, 3, 2};
  int m = 16;
  int n = sizeof(p) / sizeof(p[0]);
  knapsack(p, w, n, m);
}





// dynamic programming
// tabular method
// 0-1 knapsack

#include <iostream>
using namespace std;
void knapsack(int p[], int wt[], int n, int m)
{
  int i, w;
  int k[n + 1][m + 1];

  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= m; w++)
    {
      if (i == 0 || w == 0)
        k[i][w] = 0;
      else if (wt[i] <= w)
        k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
      else
        k[i][w] = k[i - 1][w];
    }
  }
  cout <<"Max profit is: " << k[n][m]<<endl;

  i=n-1;
  w=m;
  while(i>0 && w>=0){
    if(k[i][w]==k[i-1][w]){
      cout<<i<<" = 0"<<endl;
      i--;
    }
    else{
      cout<<i<<" = 1"<<endl;
      w=w-wt[i];
      i--;
    }
  }
  
}
int main()
{
  int p[5] = {0, 1, 2, 5, 6};
  int wt[5] = {0, 2, 3, 4, 5};
  int m = 8;
  int n = sizeof(p) / sizeof(p[0]);
  knapsack(p, wt, n, m);
  return 0;
}
