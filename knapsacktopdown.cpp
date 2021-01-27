#include<bits/stdc++.h>
using namespace std;

// int static t[n+1][w+1];
// memset(t, -1, sizeof(t));
// fill(t, t+sizeof(t),-1);


int knapsack(int wt[],int val[], int w, int n){
    int t[n+1][w+1];
    for(int i=0; i<n+1; i++){
        for(int j=0;j<w+1;j++)
        if(i==0||j==0){
         t[i][j]=0;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
             t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else {
             t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main(){

    // memset(t, -1, sizeof(t));
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int w = 50;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout<<knapsack(wt,val,w,n);
    return 0;
}