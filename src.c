#include <stdio.h>
#include <stdlib.h>

void input(int *x,int *y, int *flag);
int chkPlace(int *x,int *y);
void mField(int *flag);
int chkWin();

int data[19][19];

void main()
{
	int ch=1;
	int x,y,flag=0;

	while(1)
	{
		mField(&flag);
		ch =1;
		while(ch)
		{
			printf("좌표 입력 (x,y): ");
			scanf("%d %d",&x,&y);
			if(x >= 0 && x < 19)
			{
				if(y >= 0 && y < 19)	ch=0;
				else printf("[y의 범위가 올바르지 않습니다.]\n");
			}
			else printf("[x의 범위가 올바르지 않습니다.]\n");
		}

		input(&x,&y,&flag);
	}
}

int chkWin()
{
	int i, z, line=0;

	// 가로
	for(i=1;i<19;i++)
	{
		for(z=1;z<19;z++)
		{
			if(data[i-1][z-1] != 0)
			{
				if(data[i-1][z-1] == data[i-1][z]) line++;
			}

			if(line == 4)
			{
				// Win
				return 1;
			}
		}
		line = 0;
	}

	// 세로
	for(i=1;i<19;i++)
	{
		for(z=1;z<19;z++)
		{
			if(data[z-1][i-1] != 0)
			{
				if(data[z-1][i-1] == data[z][i-1]) line++;
			}

			if(line == 4)
			{
				// Win
				return 1;
			}
		}
		line = 0;
	}
	
	// 왼쪽 대각선
	for(i=0;i<19;i++)
	{
		for(z=1;z<19;z++)
		{
			if(data[z-1][(z-1)+i] != 0)
			{
				if(data[z-1][(z-1)+i] == data[z][z+i]) line++;
			}

			if(line == 4)
			{
				// Win
				return 1;
			}
		}
		line = 0;
	}
	// 오른쪽 대각선
	for(i=0;i<19;i++)
	{
		for(z=1;z<19;z++)
		{
			if(data[z-1][18-(z-1)-i] != 0)
			{
				if(data[z-1][18-(z-1)-i] == data[z][18-(z+i)]) line++;
			}

			if(line == 4)
			{
				// Win
				return 1;
			}
		}
		line = 0;
	}

	return 0;
}

void input(int *x,int *y, int *flag)
{
	if(!chkPlace(x,y))
	{
		if(*flag == 0) data[*x][*y] = 1;
		if(*flag == 1) data[*x][*y] = 2;

		*flag = !(*flag);
		system("cls");
	}
	else
	{
		system("cls");
		printf("[%d, %d 자리에 이미 돌이 존재 합니다.]\n",*x,*y);
	}
}

int chkPlace(int *x, int *y)
{
	if(data[*x][*y] != 0)
	{
		// 돌이 존재함
		return 1;
	}
	// 돌이 없음
	return 0;
}

void mField(int *flag)
{
	int i, z;

	for(z=0;z<19;z++)
	{
		if( z == 0) printf("    %d ",z);
		else if(z >0 && z <10) printf("  %d ",z);
		else if(z >9) printf(" %d ",z);
	}
	printf("\n");

	for(i=0;i<19;i++)
	{
		if(i <10) printf("%d ",i);
		else if(i >9) printf("%d",i);

		for(z=0;z<19;z++)
		{
			if(data[i][z] == 0) printf("[  ]");
			if(data[i][z] == 1) printf("[●]");
			if(data[i][z] == 2) printf("[○]");
		}
		printf("\n");
	}

	if(chkWin())
	{
		if(*flag == 0) printf("○ 돌의 승리!!!\n");
		if(*flag == 1) printf("● 돌의 승리!!!\n");
		system("pause");
	}
}