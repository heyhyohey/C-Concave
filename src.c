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
			printf("��ǥ �Է� (x,y): ");
			scanf("%d %d",&x,&y);
			if(x >= 0 && x < 19)
			{
				if(y >= 0 && y < 19)	ch=0;
				else printf("[y�� ������ �ùٸ��� �ʽ��ϴ�.]\n");
			}
			else printf("[x�� ������ �ùٸ��� �ʽ��ϴ�.]\n");
		}

		input(&x,&y,&flag);
	}
}

int chkWin()
{
	int i, z, line=0;

	// ����
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

	// ����
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
	
	// ���� �밢��
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
	// ������ �밢��
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
		printf("[%d, %d �ڸ��� �̹� ���� ���� �մϴ�.]\n",*x,*y);
	}
}

int chkPlace(int *x, int *y)
{
	if(data[*x][*y] != 0)
	{
		// ���� ������
		return 1;
	}
	// ���� ����
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
			if(data[i][z] == 1) printf("[��]");
			if(data[i][z] == 2) printf("[��]");
		}
		printf("\n");
	}

	if(chkWin())
	{
		if(*flag == 0) printf("�� ���� �¸�!!!\n");
		if(*flag == 1) printf("�� ���� �¸�!!!\n");
		system("pause");
	}
}