#include <iostream>
using namespace std;

#include <bits/stdc++.h>

map<int,bool>rowCheck;
map<int,bool>upperDiagonalCheck;
map<int,bool>lowerDiagonalCheck;
void addSol(vector<vector<int>>&ans,vector<vector<int>>&board,int n){
	vector<int>temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int n,vector<vector<int>>ans,int r,int c){
	//row check
if(rowCheck[r]==true) return false;
if(lowerDiagonalCheck[r+c]==true) return false;
if(upperDiagonalCheck[n-1+c-r]==true) return false;
else return true;

	//diagonal 1 check
	//diagonal 2 check

}

void solve(vector<vector<int>>&ans,int n,vector<vector<int>>&board,int c){
if(c==n){
	addSol(ans,board,n);
	return;
}
for(int i=0;i<n;i++){
	if(isSafe(n,board, i, c)){
		board[i][c]=1;
		rowCheck[i]=true;
		upperDiagonalCheck[n-1+c-i]=true;
		lowerDiagonalCheck[c+i]=true;
		solve(ans,n,board,c+1);
		board[i][c]=0;
		rowCheck[i]=false;
		upperDiagonalCheck[n-1+c-i]=false;
		lowerDiagonalCheck[i+c]=false;
	}
}
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>>ans;
	vector<vector<int>>board(n, vector<int>(n, 0));
	
	solve(ans,n,board,0);
    return ans;
}