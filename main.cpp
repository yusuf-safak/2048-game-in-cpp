#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
static int score = 0;
class Move
{
	public:
		void up(int[4][4]);
		void down(int[4][4]);
		void right(int[4][4]);
		void left(int[4][4]);
};
void Move::up(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						score += a[li][ri];
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}
void Move::down(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						score += a[li][ri];
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}
void Move::left(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						score += a[li][ri];
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}
void Move::right(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						score += a[li][ri];
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}
void addblock(int a[4][4])
{
	int li,ri;
	srand(time(0));
	while(1)
	{
		li=rand()%4;
		ri=rand()%4;
		if(a[li][ri]==0)
		{
			a[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}
}
void disp(int a[4][4])
{
	cout<<"\t\t\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\t\t\t\t\t   Score: "<<score;
	cout<<"\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<setw(7)<<".";
			else
				cout<<setw(7)<<a[i][j];
		}
		cout<<endl<<endl<<endl;
	}
}
int check(int tmp[4][4],int a[4][4])
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}
int checkover(int a[4][4])
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)
    		{
    			fl=1;
				break;	
			}
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    		{
    			gl=1;
    			break;
			}		
	if(fl || gl) return 1;
	else return 0;
}
int main()
{
	cout<<"\n\n\n\n\t\t\tmy2048\n\n\n\t\tPress any key to continue";
	getch();
	system("cls");

	int i1,i2,i3,i4,i,j;
	int a[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=4;
	disp(a);
	Move move;
	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			tmp[i][j]=a[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) move.up(a);
    	if(ch==80) move.down(a);
    	if(ch==75) move.left(a);
    	if(ch==77) move.right(a);
		if(ch==27) break;
		if(!check(tmp,a))
			addblock(a);
		disp(a);	
		if(!checkover(a))
		{
			cout<<"\n\n\t\t\t\tGAME OVER!!\n";
			cout<<"\t\t\t\tYour Score: "<<score;
			getch();
			break;
		}	
	}
	return 0;
}
