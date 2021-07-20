#include<bits/stdc++.h>
using namespace std;


vector<vector<char>>res;

    void solve(int i, int j, vector<vector<char>> &a, map<pair<int,int>,map<int,int>>&mp, vector<map<int,int>>&row, vector<map<int,int>>&col)
    {
        if(i==9)
        {
            res=a;
            return;
        }
        if(j==9)
        {
            solve(i+1,0,a,mp,row,col);
            return;
        }

        if(a[i][j]!='.')
        {
            solve(i,j+1,a,mp,row,col);
            return;
        }

        for(int k=1;k<=9;k++)
        {
            int rw=i/3;
            int cw=j/3;
            if(!mp[{rw,cw}][k]and !row[i][k]and !col[j][k])
            {
                mp[{rw,cw}][k]=1;
                row[i][k]=1;
                col[j][k]=1;
                a[i][j]= k+'0';

                solve(i,j+1,a,mp,row,col);

                mp[{rw,cw}][k]=0;
                row[i][k]=0;
                col[j][k]=0;
                a[i][j]='.';
            }
        }
    }


    void solveSudoku(vector<vector<char>>& a) {
        map<pair<int,int>,map<int,int>>mp;
        vector<map<int,int>>row(9);
        vector<map<int,int>>col(9);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(a[i][j]!='.')
                {
                    mp[{i/3,j/3}][a[i][j]-'0']=1;
                    row[i][a[i][j]-'0']=1;
                    col[j][a[i][j]-'0']=1;
                }
            }
        }
        solve(0,0,a,mp,row,col);
        a=res;
    }





    bool is_valid(vector<vector<char>>& board) {
        unordered_map<int,set<int>>row,col,sub;

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.'){
                if(row[i].find(board[i][j])!=row[i].end()||col[j].find(board[i][j])!=col[j].end()||sub[i/3*3+j/3].find(board[i][j])!=sub[i/3*3+j/3].end())
                    return false;
                else
                {
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    sub[i/3*3+j/3].insert(board[i][j]);
                }
                }
            }
        }
        return true;
    }




    void display(vector<vector<char>>board,bool solutionexist)
    {

      if(solutionexist==false)
        cout<<"NO Solution :(\n";
      else if(solutionexist==true)
    {
      cout<<endl;
        cout<< "\t"<<" _____     ____                        _________   _________    ____"<<"\n";
        cout<< "\t"<<"/         /    \\     |       |     |       |           |       /    \\    |\\   |"<<"\n";
        cout<< "\t"<<"\\____     |     |    |       |     |       |           |       |     |    | \\  |"<<"\n";
        cout<< "\t"<<"     \\    |     |    |       |     |       |           |       |     |    |  \\ |"<<"\n";
        cout<< "\t"<<"_____/     \\___/     |_____  \\_____/      |       ____|____    \\___/    |   \\|"<<"\n";
        cout<<endl;
        cout<<"\t\t\t\t-------------------------------------\n";
        for(auto it:board)
        {
          cout<<"\t\t\t\t| ";
            for(auto i:it)
                cout<<i <<" | ";
            cout<<endl;
            cout<<"\t\t\t\t-------------------------------------";
            cout<<endl;
        }
    }
    else
    {
        cout<<"\n\n\t\t\t\t\tRESULT : Invalid Sudoku  :(\n";
    }
    }





    int main()
    {
     while(1)
     {
      cout<<"WELCOME TO SUDOKU SOLVER APP"<<endl;
      bool x;
      cout<<"PRESS 1 TO CONTINUE : ";cin>>x;

      if(x)
      {
        system("CLS");
        cout<<"INSTRUCTIONS \n";
        cout<<"ENTER THE NUMBER IN RANGE 1-9\nFOR EMPTY PALCES ENTER . ";
        int y;
        cout<<"PRESS 1 TO CONTINUE : ";cin>>y;
        if(y)
        {
          system("CLS");
          vector<vector<char>>board(9,vector<char>(9));

          for(int i=0;i<9;i++)
          {
            for(int j=0;j<9;j++)
            {
              cin>>board[i][j];
            }
          }

          bool valid=is_valid(board);
          if(valid){
            solveSudoku(board);
            display(board,valid);
          }
          else
            {
              display(board,false);
            }
        }
        int c;
        cin>>c;
        cout<<"To continue enter 1 else 0 : ";
        cin>>c;
        if(c==0)
          break;
      }
    }
      return 0;
    }
