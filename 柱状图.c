#include<stdio.h>
int main(void)
{
	int n,a=0,max=0,min=0;
	scanf("%d",&n);
	char x[n][5],ch,y[31][n*2-1];
	for(int j=0;j<31;j++)
	{
		for(int i=0;i<2*n-1;i++)
		{
			y[j][i]=' ';
		}
	}
	for(int i=0;i<n;i++)
	{
		while((ch=getchar())!=' ')
		{
			if(ch=='\n')
			break;
			x[i][a++]=ch;
		}
		x[i][a]='\0';
		if(x[i][0]=='\0')
		i--;
		a=0;
	}
	for(int i=0;i<n;i++)
	{
		int b=0;
		if(x[i][0]=='-')
		{
			if(x[i][2]<='9'&&x[i][2]>='0')			
			{
				b=(x[i][1]-'0')*10+x[i][2]-'0';
				if(x[i][3]=='\0')
				for(int j=0;j<b;j++)
				{
				y[16+j][i*2]='+';
				}
				else
				for(int j=0;j<b;j++)
				{
				y[16+j][i*2]=x[i][3];
				}
			}
			else
			{
				b=x[i][1]-'0';
				if(x[i][2]=='\0')
				for(int j=0;j<b;j++)
				{
				y[16+j][i*2]='+';
				}
				else
				for(int j=0;j<b;j++)
				{
				y[16+j][i*2]=x[i][2];
				}
			}			
		}
		else
		{
			if(x[i][1]<='9'&&x[i][1]>='0')			
			{
				b=(x[i][0]-'0')*10+x[i][1]-'0';
				if(x[i][2]=='\0')
				for(int j=0;j<b;j++)
				{
				y[14-j][i*2]='+';
				}
				else
				for(int j=0;j<b;j++)
				{
				y[14-j][i*2]=x[i][2];
				}
			}
			else
			{
				b=x[i][0]-'0';
				if(x[i][1]=='\0')
				for(int j=0;j<b;j++)
				{
				y[14-j][i*2]='+';
				}
				else
				for(int j=0;j<b;j++)
				{
				y[14-j][i*2]=x[i][1];
				}
			}			
		}
	}
	for(int i=0;i<2*n-1;i++)
	y[15][i]='-';
	for(int i=0;i<31;i++)
	{
		for(int j=0;j<2*n-1;j++)
		{
			if(y[i][j]!=' ')
			{
				for(int k=0;k<2*n-1;k++)
				printf("%c",y[i][k]);
				printf("\n");
				break;
			}
		}
	}
	return 0;
} 
