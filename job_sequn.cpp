#include<algorithm>
#include<iostream>
using namespace std;
class job{
    public:
    char id;
    int dead;
    int profit;
};
bool comparision(job a, job b){
    return a.profit>b.profit;
}
void printJobScheduling(job arr[], int n){
    sort(arr,arr+n,comparision);
    int result[n];
    bool slot[n];
    int i,j;
    for( i=0; i<n; i++){
        slot[i]=false;
    }
    for(i=0; i<n; i++){
        for(j = min(n, arr[i].dead)-1; j>=0; j--){
            if(slot[j]==false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for(i=0; i<n;i++){
        if(slot[i]){
            cout<<arr[result[i]].id<<" ";
        }
    }
}
int main(){
    job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
    // Function call
    printJobScheduling(arr, n);
    return 0;
}