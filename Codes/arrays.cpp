#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter the row and col of the code : ";
    int row,col;
    cin>>row>>col;
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i] = new int[col];  // Correct allocation for each row
        for(int j=0;j<col;j++){
            arr[i][j]=i+j;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"This is the 3d array : "<<endl;
    int depth;
    cout<<"Enter the depth , row and col of the code : ";
    cin>>depth>>row>>col;
    int ***arr_3=new int**[depth];
    for(int i=0;i<depth;i++){
        arr_3[i] = new int*[row];  
        for(int j=0;j<row;j++){
             arr_3[i][j]=new int[col];
            for(int k=0;k<col;k++){
                arr_3[i][j][k]=i+j+k;
                cout<<arr_3[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl<<"This is for vector "<<endl;
    cout<<"Can you please enter the size of row and col in vector : "<<endl;
    cin>>row>>col;
    vector<vector<int>>vec(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            vec[i][j]=i+j;
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"This is for vector for 3d : "<<endl<<"Can you please enter the depth, row and col  of vector"<<endl;
    cin>>depth;
    vector<vector<vector<int>>>vec_3(depth,vector<vector<int>>(row,vector<int>(col)));
    for(int i=0;i<depth;i++){
        for(int j=0;j<row;j++){
            for(int k=0;k<col;k++){
                vec_3[i][j][k]=i+j+k;
                cout<<vec_3[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}