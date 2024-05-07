#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool issafe(const vector<int>& board , int row , int col){

   for(int i = 0 ; i<row ; ++i){
      if(board[i] == col || abs(row - i) == abs(col - board[i]))
           return false;
      
   }
   return true;
}


bool SolveNQueens(vector<int>& board , int row , int n){
      if(row == n){
         return true;
      }
      
      for(int col = 0 ; col<n ; col++){
         if(issafe(board , row , col)){
            board[row] = col;
         
         if(SolveNQueens(board , row+1 , n))
             return true;
         
         
         board[row] = -1;
      }
   }
   return false;   
}

void print(vector<int>& board){

    int n = board.size();
    for(int i=0 ; i<n ; i++){
       for(int j=0 ; j<n ; j++){
         if(board[i] == j){
           cout<<"Q";
         }
         else{
            cout<<".";
         }
       }
       cout<< endl;
    }
}

int main(){
   int n;
   cout<<"Enter the number of queens "<<endl;
   cin>>n;
   vector<int> board(n,-1);
   SolveNQueens(board , 0 , n);
   
   cout<<"The solution will be"<<endl;
   
   if(board[0] == -1){
     cout<<"The solution doesnt exists"<<endl;
   }
   else{
      print(board);
   }
   return 0;
}









