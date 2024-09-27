#include <bits/stdc++.h>
using namespace std;


// odd or even
string oddOrEven(int n){
    if((n & 1) == 0){
        return "even";
    }
    else{
        return "odd";
    }
}
int main(){

    int num;
    cin>>num;
    cout<<oddOrEven(num);
    return 0;
}




// get Bit (and &)
int getbit(int n, int pos){
    return ((n & (1 << pos))!=0);
}
int main(){
    int num; cin>>num;
    int pos; cin>>pos;
    cout<<getbit(num, pos);
    return 0;
}




// set Bit (OR |)
// int setBit(int n, int pos){
//     return (n | (1 << pos));
// }
// void main(){
//     int num; cin>>num;
//     cout<<setBit(num, 1);
// }




// clear bit (complement ~)
int clearBit(int n, int pos) {
    int masking  = ~(1 << pos); 
    return (n & masking);
}
int main() {
    int num; cin>>num;
    cout<<clearBit(num, 2);
    return 0;
}




// check if power of 2
bool ifPowerOf2(int n) {
    if((n & (n-1)) == 0){
        return true;
    }
    return false;
}
int main() {
    int num; cin>>num;
    cout<<ifPowerOf2(num);
    return 0;
}






// count the number of 1 present in a binary
int countOf1(int n) {
    int count = 0;
    while(n != 0){
        n = (n & (n-1));
        count++;
    }
    return count;
}
int main() {
    int num; cin>>num;
    int ans = countOf1(num);
    cout<<ans;
    return 0;
}


// total subsets notCorrected
// int main() {
    
//     vector<vector<int>> v;
//     int arr[3] = {1, 2, 3};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<(1<<n); j++) {
//             if (i & j == 1) {
//                 v[i].push_back(arr[i]);
//             }
//         }
//     }
//     for (int i=0; i<v.size(); i++) {
//         for (int j=0; j<v[i].size(); j++) {
//             cout<<v[i][j]<<endl;
//         }
//     }

//     return 0;
// }

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int lastSum;
    sort(arr, arr+n);
    int xorsum = 0;
    for(int i=0; i<n; i++) {
        cout<<arr[i];
    }
    cout<<endl;
    for(int i=0; i<n; i++) {
        lastSum = xorsum;
        xorsum ^= arr[i];
        if (xorsum == lastSum) {
            cout<<lastSum<<endl;
            break;
        }
    }

    return 0;
}
