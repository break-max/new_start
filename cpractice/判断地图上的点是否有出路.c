#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 10

int chessboard[ROW][COL]={0};

void print_chessboard()
{
	int i,j;
	for(i = 0; i <ROW; i++)
	{
		for(j = 0;j <COL; j++)
			printf("%d ",chessboard[i][j]) ;
		printf("\n");
	}
}

void init_chessboard()
{
	int i,j;
	for(i = 0; i < ROW; i++)
		for(j = 0; j <COL; j++)
			chessboard[i][j] = rand() % 2;
}

int is_valid(int row, int col)
{
	if(row <0 || row > ROW - 1 || col<0 ||col > COL - 1)
		return 0;
	return 1;
}

struct direction
{
	int dx;
	int dy;
	char name[16];
};

typedef struct direction dir_t;

dir_t dirs[4] = 
{
	{-1,0,"up"},
	{1,0,"down"},
	{0,-1,"left"},
	{0,1,"right"}
};
 
int main()
{
	int row, col;
	printf("Is there a way out?\n");
	
	print_chessboard();
	printf("\n");
	init_chessboard();
	print_chessboard();
	
	while(1)
	{
		int ways = 0;//一共有多少条路 
		
		printf("please input a position\n");
		
		scanf("%d %d", &row, &col);
		printf("row = %d  col = %d\n", row, col); 
		
		if(!is_valid(row, col))
		{
			printf("input error!please input again!\n\n");
			continue;
		}
		
		dir_t dir;
		int nx, ny;
		int i = 0;
		for(i = 0; i < 4; i++)
		{
			
			dir = dirs[i];
			nx = row + dir.dx ;
			ny = col + dir.dy ;
			
			if (is_valid(nx, ny))
			{
				if(chessboard[nx][ny] == 0)
				{
					printf("direction %s is ok!\n",dir.name);
					ways++;
				}
			}
		}	
		
		 
		printf("value = %d\n", chessboard[row][col]);
		printf("ways = %d\n\n", ways);
	}
	return 0;
}
