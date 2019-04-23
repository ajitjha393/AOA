#include<bits/stdc++.h>

int count = 0;

int x[10]; // solution set

int totalcalls = 0; //No of calls to nqueen(no of nodes)

int place(int k,int i) //can i place  queen in ith kth row and ith column
{
  for(int j = 1 ;j<=k-1; j++)
  {
    if((x[j] == i)||(abs(x[j]-i) == abs(j-k)))
      return 0;
  }
  return 1;
}

void display2d(int n) //displays chess board
{
  int k;
  
  count+=1;
  
  printf("\n\nSolution %d : \n",count);
  
  for (int i=1;i<=n;i++)
  {
    k = x[i];
    for(int j=1;j<=n;j++)
    {
      if(j==k)
        printf("\tQ");
      else
        printf("\t--");
    }
    printf("\n");
  }
}


void display(int n) //displays solution set
{
  
  printf("\nx[] = \t");
  
  for (int i = 1; i<=n; i++)
    printf("%d\t",x[i]);
  printf("\n-------------------------------------------------------------------");

}


void NQueens(int k, int n)
{
  totalcalls+=1;
  for (int i=1;i <=n; i++)
  {
    if(place(k,i)==1)
    {
      x[k] = i;
      if(k==n)
        {display2d(n);//2dprinting
        display(n);}//for printing solution vector
        else
          NQueens(k+1,n);
      }
  }

}



  int main(void) {
    int n;
    printf("\n Enter number of queens: ");
    scanf("%d",&n);
    NQueens(1,n);
    printf("\nTotal No.of nodes in the tree = %d", totalcalls);
    return 0;
  }

