import java.io.*;
class InterestingGame
    {
        public static void main(String args[])throws IOException
        {
            //Input number of testcases
            int testCases;
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            testCases=Integer.parseInt(br.readLine());
            int i,j,k;//will rotate a loop for testcases
            for(i=0;i<testCases;i++)
            {
               long n,m;
               n=Long.parseLong(br.readLine());
               System.out.print(" ");
               m=Long.parseLong(br.readLine());
               System.out.println(" ");
               if(!((n>=0&&n<=1000000000)&&(m>=0&&m<=100000)))
                return;
                long arr[][]=new long[m][3];
                for(j=0;j<m;j++)
                {
                    for(k=0;k<3;k++)
                    {
                        arr[j][k]=Long.parseLong(br.readLine());
                        System.out.print(" ");
                        
                    }
                    System.out.println();
                }
                long arr1=new long[n+1][n+1];
                
                for(j=0;j<m;j++)
                {
                    for(k=0;k<3;k++)
                    {
                        arr1[j][k]=arr[j][2];
                    }
                }
                for(j=0;j<n;j++)
                {
                   int sum=arr1[0][0];
                   int sumCol=arr1[0][0];
                    for(k=0;k<n;k++)
                    
                    {
                        sum+=arr1[j][k];
                        sumCol=arr1[k][j];
                        
                    }
                    arr1[j][n]=sum;
                    arr1[n][j]=sumCol;
                    
                }
                int maxRow,maxCol,max,row,col;
                maxRow=arr1[0][n];
                maxCol=arr1[n][0];
                for(i=0;i<n;i++)
                    {
                        if(maxRow<arr1[i][n])
                        {
                            maxRow=arr1[i][n];
                            row=i;
                        }
                        if(maxCol<arr1[n][i])
                        {
                            maxCol=arr1[n][i];
                            col=i;
                        }
                    }
                    if(maxRow>=maxCol)
                        System.out.println("Row ",+(row+1));
                        else
                        System.out.println("Column ",+(col+1);
                        
              
            
                
                
            }
            
        }
    }                 
                        
              
            
                
                
            
            
        
    