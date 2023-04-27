// Activity selection using greedy algo

#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int sno[], int s[], int f[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            if (f[j] > f[j + 1])
            {
                swap(&sno[j], &sno[j+1]);
                swap(&s[j], &s[j + 1]);
                swap(&f[j], &f[j + 1]);
            }
        }
    }
}
void activity_selection(int sno[], int s[], int f[], int n)
{
    int i = 0, j;

    cout <<endl<< "The selected activities are: " ;
    cout << sno[0] << " ";
    // first activity always gets selected

    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << sno[j] << " ";
            i = j;
        }
    }
    cout << endl;
}
int main()
{
    // already sorted acc to increasing order of their finish time
    // int start[] = { 1, 3, 0, 5, 8, 5 };
    // int finish[] = { 2, 4, 6, 7, 9, 9 };

    int sno[] = {1,2,3,4,5,6};
    int start[] = {0, 8, 5, 5, 3, 1};
    int finish[] = {6, 9, 9, 7, 4, 2};

    int n = sizeof(sno) / sizeof(sno[0]);

    bubble_sort(sno,start, finish, n);
    // sorting done wrt increasing order of their finish time

    activity_selection(sno,start, finish, n);
    return 0;
}