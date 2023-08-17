#include<iostream>
#include<string.h> 
using namespace std;

char X[100],Y[100];
int C[100][100],m,n;
char B[100][100];


void LCSlength(string X,string Y)
{
    
    m=X.length();
    n=Y.length();
    for(int i=0;i<=m;i++)
    {
        C[i][0]=0;
    }
    for(int j=0;j<=n;j++)
    {
        C[0][j]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(X[i-1]==Y[j-1])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]='x';
            }
            else if(C[i-1][j]>=C[i][j-1])
            {
                C[i][j]=C[i-1][j];
                B[i][j]='y';
            }
            else
            {
                C[i][j]=C[i][j-1];
                B[i][j]='z';
            }
        }
    }
    
    cout<<"C array is: "<<endl;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<C[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"B array is: "<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<B[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
}    


void printLcs(char B[100][100],string X,int i,int j)
{
    if(i==0 || j==0)
    {
        return ;
    }
    if(B[i][j]=='x')
    {
        printLcs(B,X,i-1,j-1);
        cout<<X[i-1];
    }
    else if(B[i][j]=='y')
    {
        printLcs(B,X,i-1,j);
    }
    else
    {
        printLcs(B,X,i,j-1);
    }
}

int main()
{
    cout<<"enter String X: "<<endl;
    cin>>X;
    cout<<"enter String Y: "<<endl;
    cin>>Y;
    LCSlength(X,Y);
    cout<<"longest common subsequence in X and Y is: "<<endl;
    printLcs(B,X,m,n);
}




























