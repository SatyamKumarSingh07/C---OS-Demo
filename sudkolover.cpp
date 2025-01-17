#include<iostream>
#define N 9
using namespace std;
int grid[N][N] = {
{3,0,6,5,0,8,4,0,0},
{5,2,0,0,0,0,0,0,0},
{0,8,7,0,0,0,0,3,1},
{0,0,3,0,1,0,0,8,0},
{9,0,0,8,6,3,0,0,5},
{0,5,0,0,9,0,6,0,0},
{1,3,0,0,0,0,2,5,0},
{0,0,0,0,0,0,0,7,4},
{0,0,5,2,0,6,3,0,0},
};

bool isPossible(int col, int num){
    for(int i=0;i<N;i++){
        if(grid[i][col]==num){
            return true;
        }
    }
    return false;
}
bool isPresent(int row, int num)
    {
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
bool isPresentinbox(int boxStarRow,int boxStarCol ,int num){
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(grid[row+boxStarRow][col+boxStarCol]==num){
                return true;
            }
        }
    }
    return false;
}
void sudkoGrid(){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
          if(col==3 || col==6){
              cout<<" | ";
          }
            cout<<grid[row][col]<<" ";
    }
    if(row==2 || row==5){
        cout<<endl;
        for(int i=0;i<N;i++){
            cout<<"---";
        }
    }
    cout<<endl;
}
}
bool findEmptyPlace(int &row , int &col){
    for(row=0;row<N;row++){
        for(col=0;col<N;col++){
            if(grid[row][col]==0){
                return true;
            }
        }
    }
    return false;
}
bool isValidPlace(int row, int col, int num){
    return !isPresent(row,col) && !isPossible(col,num) && !isPresentinbox(row-row%3,col-col%3,num);
}
bool sudkoSolver(){
    int row,col;
    if(!findEmptyPlace(row,col)){
        return true;
    }
    for(int num=1;num<=9;num++){
        if(isValidPlace(row,col,num)){
            grid[row][col]=num;
            if(sudkoSolver()){
                return true;
            }
            grid[row][col]=0;
        }
    }
    return false;
}
int main(){
    if(sudkoSolver()==true){
        sudkoGrid();
    }
    else{
        cout<<"No solution exists";
    }
    return 0;
}
