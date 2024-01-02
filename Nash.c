##include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void sifirla(int i,int j,int n,int (*nash1)[n])
{
	int k;
		
    for(k=0;k<=i;k++)
    {
    	nash1[k][j]=0;
	}
    					
}

void sifirla2(int i,int j,int n,int (*nash2)[n])
{
	int k;
		
    for(k=0;k<=j;k++)
    {
    	nash2[i][k]=0;
	}
	
    					
}
int main()
{
    int m,n,i,j,max;

    printf("satir ve sutun giriniz: ");
    scanf("%d %d",&m,&n);
    int oyuncu1[m][n];
    int oyuncu2[m][n];
    int nash1[m][n];
    int nash2[m][n];
    int c=0;
 
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("1.Oyuncunun %d.stratejisi için kazanclari giriniz: ",i+1);
            scanf("%d",&oyuncu1[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("2.Oyuncunun %d.stratejisi için kazanclari giriniz: ",j+1);
            scanf("%d",&oyuncu2[i][j]);
        }
    }
    
    for(j=0;j<n;j++)
    {
		max=oyuncu1[0][j];
		nash1[0][j]=max;
    	for(i=0;i<m-1;i++)
    	{
    		if(oyuncu1[i+1][j]>max)
    		{
    			sifirla(i,j,n,nash1);
    			max=oyuncu1[i+1][j];
    			nash1[i+1][j]=max;
			}
			if(oyuncu1[i+1][j]==max)
			{
				
				max=oyuncu1[i+1][j];
				nash1[i+1][j]=max;
			
			}
    			
		}	
		
	}	 
    for(i=0;i<m;i++)
    {
    	max=oyuncu2[i][0];
    	nash2[i][0]=max;
        for(j=0;j<n-1;j++)
        {
            if(oyuncu2[i][j+1]>max)
            {
            	sifirla2(i,j,n,nash2);
    			max=oyuncu2[i][j+1];
    			nash2[i][j+1]=max;
			}
			if((oyuncu2[i][j+1]==max))
			{
				
				max=oyuncu2[i][j+1];
				nash2[i][j+1]=max;
				
			}

        }
        
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if((nash1[i][j]!=0)&&(nash2[i][j]!=0))
            printf("%d,%d nash dengesidir ",nash1[i][j],nash2[i][j]);
            else
            c++;

        }
    }
    if(c==m*n)
    printf("Bu oyunun Nash dengesi yoktur!!!");
    
  

}
