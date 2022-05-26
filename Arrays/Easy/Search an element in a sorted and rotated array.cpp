#include <iostream>
#define pii pair<int, int>
#define lli long long int
#define li long int
#define vi vector<int>
#define vlli vector<lli>
#define vli vector<li>
#define rep(i, k, n) for (i = k; i < n; ++i)
#define Repr(i, k, n) for (i = k; i >= n; --i)
#define c(n) cout << n << endl
#define z(n) cout << n <<" "
#define nl cout << endl;
#define INF INT_MAX
using namespace std;

int bs(int arr[],int l,int h,int key){
    while(l<=h){
        int mid= l + (h-l)/2;
        if(arr[mid]== key){
            return mid;
        }
        if(arr[mid]> key){
            h = mid-1;
        }
        else{
            l= mid+1;
        }
    }
    return -1;
}
// int search(int arr[], int l, int h, int key){
//     int idx=-1;
//     int n= sizeof(arr)/sizeof(arr[0]);
//     for(int i=1;i<n-1;i++){
//         if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
//             idx= i;
//             break;
//         }
//     }
//     if(idx<0){
//         return bs(arr,l,h,key);
//     }
//     int r = bs(arr,idx+1,h,key);
//     int l= bs(arr,0,idx,key);
//     return r>0?r:l;
    
// }

// int search(int arr[], int l, int h, int key){
//     int mid= 0;
//     while(l<=h){
//         mid= l + (h-l)/2;
//         if(arr[mid]== key){
//             return mid;
//         }
//         if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
//             if(arr[mid]>arr[l]){
//                 h= mid-1;
//             }
//             else{
//                 l= mid+1;
//             }
//         }
//         else{
//             if(arr[mid]>key){
//                 h= mid-1;
//             }
//             else{
//                 l= mid+1;
//             }
//         }
//     }
//     return mid;
    
// }


int main()
{

    return 0;
}