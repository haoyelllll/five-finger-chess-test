#include<stdio.h>
int win(int x, int y, int size[10][10]);
int chess_show(int size[10][10]);
int show(int size[10][10]);
int play(int x, int y, int size[10][10], int hb);
void main()
{
	int size[10][10] = { {0} };
	int x = 0;
	int y = 0;
	int hb = 0;


	int cs = chess_show(size);
	while (1)
	{
		int pl = play(x, y, size, hb);
		system("CLS");
		int sh = show(size);
		int aa = win(x, y, size);
		if (aa == "O ")
		{
			printf("O赢\n");
		}
		if (aa == "X ")
		{
			printf("X赢\n");
		}
	}
}


/*
void win(int x, int y,int hb )
{
	char ww;

		if (size[x + 1][y] == "X ") {
			for(int i=0;i<5;i++){
			if (size[x + 1][y] == "X "){
				x=x+1;
			}
			w="R";
			}
		}



	}

	*/


int win(int x, int y, int size[10][10])
{

	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			if (size[i][j] == size[i][j + 1] &&
				size[i][j + 1] == size[i][j + 2] &&
				size[i][j + 2] == size[i][j + 3] &&
				size[i][j + 3] == size[i][j + 4] &&
				size[i][j] != "* ")
			{
				return size[i][j];
			}
		}
	}
	for (j = 0; j < y; j++)
	{
		for (i = 0; i < x; i++)
		{
			if (size[i][j] == size[i + 1][j]
				&& size[i + 1][j] == size[i + 2][j]
				&& size[i + 2][j] == size[i + 3][j]
				&& size[i + 3][j] == size[i + 4][j]
				&& size[i][j] != "* ")
			{
				//printf(size[i][j],"\n");
				return size[i][j];
			}
		}
	}

	for (i = 0; i < x; i++)
	{
		if (size[i][i] == size[i + 1][i + 1]
			&& size[i + 1][i + 1] == size[i + 2][i + 2]
			&& size[i + 2][i + 2] == size[i + 3][i + 3]
			&& size[i + 3][i + 3] == size[i + 4][i + 4]
			&& size[i][i] != "* ")
		{
			return  size[i][i];
		}
		if (size[i][i + 4] == size[i + 1][i + 3]
			&& size[i + 1][i + 3] == size[i + 2][i + 2]
			&& size[i + 2][i + 2] == size[i + 3][i + 1]
			&& size[i + 3][i + 1] == size[i + 4][i]
			&& size[i][i + 4] != "* ")
		{
			return  size[i][i + 4];
		}
	}
}
int  chess_show(int size[10][10])
{
	//棋盘
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			size[i][j] = "* ";
			printf(size[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int show(int size[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf(size[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int play(int x, int y, int size[10][10], int hb)
{//下棋
	scanf_s("%d%d%d", &x, &y, &hb);
	if (size[y - 1][x - 1] != "* ")
	{
		printf("不能重复\n");
	}
	else if (hb == 1) {
		size[y - 1][x - 1] = "X ";
	}
	else {
		size[y - 1][x - 1] = "O ";
	}
}