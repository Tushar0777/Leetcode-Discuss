#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rankArr; // rank array

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return;

    if (rankArr[x_parent] > rankArr[y_parent]) {
        parent[y_parent] = x_parent;
    } else if (rankArr[x_parent] < rankArr[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rankArr[y_parent]++;
    }
}
// helper function already given tha to is pr dimag maat khrb kr code chalane 
// ke liye likha hai 
int globalidx=0;
vector<pair<int,int>>seq={ {0,0}, {1,1}, {1,0}, {2,2}, {1,2}, {1,3}};

pair<int,int>getRandomCell(){
    return seq[globalidx++]; }
// helper fucnrtion ends 

int cellid(int r,int c,int cols){
    return r*cols+c;
}

// Main function to solve the problem

int cellsToConnectLeftRight(int rows, int cols) {
    
    if(rows<=0 || cols<=0) return 0;

    int N=rows*cols;
    int left=N;
    int Right=N+1;
    parent.resize(N+2);
    rankArr.assign(N+2,0);

    for(int i=0;i<N+2;i++){
        parent[i]=i;
    }

    vector<vector<bool>>active(rows,vector<bool>(cols,false));
    int activeCount=0;


    vector<int> dr = {-1, 0, 1, 0}; 
    vector<int> dc = { 0, 1, 0,-1};

    // jabtak return nhi ho jata tab tak while chalega 
    while(true){
        pair<int,int>cell=getRandomCell();
        int r=cell.first;
        int c=cell.second;

        if(active[r][c]==false){
            active[r][c]=true;
            activeCount++;

            int currid=cellid(r,c,cols);

            if(c==0) Union(currid,left);
            if(c==cols-1) Union(currid,Right);

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nc>=0 && nr<rows && nc<cols && active[nr][nc]){
                    Union(currid,cellid(nr,nc,cols));
                }

            }

            if(find(left)==find(Right)){
                return activeCount;
            }
        }
    }

}

// ---------- Test harness ----------
int main() {
    int rows = 3, cols = 4;

    int result = cellsToConnectLeftRight(rows, cols);
    cout << "Total cells activated to connect left to right = " << result << "\n";
    return 0;
}
