// recursive max sub array
// O(n)
// deals with only if sum is positive

#include <iostream>
using namespace std;
int maxSubArraySum(int a[], int n)
{
    int max = INT_MIN, max_end = 0;
    for (int i = 0; i < n; i++)
    {
        max_end = max_end + a[i];
        if (max < max_end)
            max = max_end;
        if (max_end < 0)
            max_end = 0;
    }
    return max;
}
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Maximum contiguous sum is " << maxSubArraySum(a, n) << endl;
    return 0;
}



// Brute-force max sub array
// O(n^2)

#include<iostream>
using namespace std;
int max_sum(int a[], int n){
    int sum = INT_MIN; 
    // equates sum to its minimum value
    // works as ( - infinity )
    int i,j;
    
    for(i=0; i<n; i++){
        int s=0;
        for(j=i; j<n; j++){
            s = s + a[j];
            if(sum<s){
                sum = s;
            }
        }
    }
    return sum;
}
int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Max sum is: "<<max_sum(a,n)<<endl;
    return 0;
}



// #include<iostream>
// using namespace std;
// int max_crossing_sum(int a[], int l, int mid, int h){
//     int left_sum = INT_MIN;
//     int sum = 0,i,j;
//     for(i=mid; i>=l; i++){
//         sum = sum + a[i];
//         if(sum > left_sum)
//             left_sum = sum;
//     }
//     int right_sum = INT_MIN;
//     sum = 0;
//     for(j=mid+1; j<=h; j++){
//         sum = sum+a[i];
//         if(sum>right_sum)
//             right_sum=sum;
//     }
//     return left_sum+right_sum;
// }
// int max_sum(int a[], int l, int h){
//     int left_l,left_h,left_sum;
//     int right_l,right_h,right_sum;
//     int cross_l,cross_h,cross_sum;

//     if(h==l)
//         return(l,h,a[l]);
//     else{
//         int mid = (l+h)/2;
//         (left_l,left_h,left_sum) = max_sum(a,l,mid);
//         (right_l,right_h,right_sum) = max_sum(a,mid+1,h);
//         (cross_l,cross_h,cross_sum) = max_crossing_sum(a,l,mid,h);
//         if(left_sum>=right_sum && left_sum>=cross_sum)
//             return(left_l,left_h,left_sum);
//         else if(right_sum>=left_sum && right_sum>=cross_sum)
//             return(right_l,right_h,right_sum);
//         else return(cross_l,cross_h,cross_sum);
//     }
// }
// int main(){
//     int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
//     int n = sizeof(a)/sizeof(a[0]);
//     int l,h,s;
//     (l,h,s)=max_sum(a,0,n-1);
//     cout<<"Max sum is: "<<s<<endl;
//     return 0;
// }




// chat gpt


#include <iostream>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];
    int m = (l + h) / 2;
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}

int main()
{
    // int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    cout << "Maximum subarray sum is " << max_sum;
    return 0;
}
