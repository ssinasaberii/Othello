#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
struct map
{
	int empty_cells;
	int turn;
	int map_size;
};
struct player
{
	int num_choice;
	int mode;
	int win_cells;
};

using namespace std;

void menu();
void size();
void invalid();
int char_to_num();
void game_map(int,char[20][20]);
int check_okw(int,int,char[20][20],int);
int check_okb(int, int, char[20][20], int);
int show_states(int,char[20][20],int);
char flip(char [20][20],int,int,int,int);
int game(int,int);
int main()
{
	menu();
	int a,b=8,i,d,e;
	char c[10]={'\0'};
	cin >> a;
	if (a == 2)
	{
		for (i = 0; i <= 100; i++)
		{
			size();
			fflush(stdin);
			b=char_to_num();
			if (b % 2 == 0 && b >= 4 && b <= 20)
			{
				cout<< "GOOD CHOICE!"<<"\n";
				menu();
				cin >> a;
				if (a == 2)
					continue;
				else
				    break;
			}
			else
			{
			    invalid();
				continue;
			}
		}
	}
	if (a == 1)
	{
		system("cls");
		cout << "Choose game mode:" << "\n" << "1-Player vs Player" << "\n" << "2-Player vs Computer"<<"\n";
		cin >> d;
		system("cls");
		if (d == 2)
		{
			cout << "1-Easy" << "\n" << "2-Normal" << "\n";
			cin >> e;
			if (e == 2)
			{
				cout << "COMING SOON...";
				return 0;
			}
		}
		game(b,d);
	}
	if (a == 3)
		return 0;
	system("pause");
	return 0;
}
void menu()
{
	cout << "Welcome to Othello game" << "\n" << "MENU:"<<"\n";
	cout << "1-Start game" << "\n" << "2-Change game size" << "\n" << "3-EXIT"<<"\n";
}
void size()
{
	cout << "Insert an even number between 4 and 20: ";
}
void invalid()
{
	cout << "invalid number try again"<<"\n";
}
int char_to_num()
{
	fflush(stdin);
	int num=0,i,j;
	char a[10] = { '\0' };
	fflush(stdin);
	cin >> a;
	if (a[1] == '\0')
	{
		num = a[0] - 48;
		return num;
	}
	else if (a[2] == '\0')
	{
		for (i = 1, j = 1; i >= 0; i--, j *= 10)
			num += (a[i] - 48) * j;
		return num;
	}
	else
		return -1;
}
void game_map(int a,char b[20][20])
{
	int i, j, k;
	char c[1][20]={0};
	cout << "   ";
	for (k = 0; k <= a - 1; k++)
	{
		if(k<=9)
		    cout << k << "  ";
		if (k >= 10)
			cout << k << " ";
	}
	cout << "\n";
	for (i = 0; i <= a-1; i++)
	{
		if (i <= 9)
			cout << i << "  ";
		if (i >= 10)
			cout << i << " ";
	    for (j = 0; j <= a-1; j++)
					cout << b[i][j] << "  ";
        cout << "\n";
	}
}
int check_okw(int x, int y,char a[20][20],int size)
{
	int i, j;
	for (i = x-1, j = y; i >= 0; i--)
	{
		if (a[i][j] == 'b')
			if (a[i - 1][j] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	for(i=(x-1),j=(y+1);i>=0 && j<size;i--,j++)
	{
		if (a[i][j] == 'b')
			if (a[i - 1][j+1] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
    for(i=x,j=y+1;j<size;j++)
	{
		if (a[i][j] == 'b')
			if (a[i][j+1] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	for(i=(x+1),j=(y + 1); i < size && j < size; i++, j++)
	{
		if (a[i][j] == 'b')
			if (a[i + 1][j+1] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	for(i=(x+1),j=y;i<size;i++)
	{
		if (a[i][j] == 'b')
			if (a[i + 1][j] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	for(i=(x+1),j=y-1;i<size && j>=0;i++,j--)
	{
		if (a[i][j] == 'b')
			if (a[i + 1][j-1] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	for(i=x,j=(y-1);j>=0;j--)
	{
		if (a[i][j] == 'b')
			if (a[i ][j-1] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	for(i=x-1,j=y-1;i>=0 && j>=0 ;i--,j--)
	{
		if (a[i][j] == 'b')
			if (a[i - 1][j-1] == 'w')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'w')
			break;
	}
	return 0;
}
int check_okb(int x, int y, char a[20][20], int size)
{
	int i, j;
	for (i = x - 1, j = y; i >= 0; i--)
	{
		if (a[i][j] == 'w')
			if (a[i - 1][j] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = (x - 1), j = (y + 1); i >= 0 && j < size; i--, j++)
	{
		if (a[i][j] == 'w')
			if (a[i - 1][j + 1] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = x, j = y + 1; j < size; j++)
	{
		if (a[i][j] == 'w')
			if (a[i][j + 1] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = (x + 1), j = (y + 1); i < size && j < size; i++, j++)
	{
		if (a[i][j] == 'w')
			if (a[i + 1][j + 1] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = (x + 1), j = y; i < size; i++)
	{
		if (a[i][j] == 'w')
			if (a[i + 1][j] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = (x + 1), j = y - 1; i < size && j >= 0; i++, j--)
	{
		if (a[i][j] == 'w')
			if (a[i + 1][j - 1] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = x, j = (y - 1); j >= 0; j--)
	{
		if (a[i][j] == 'w')
			if (a[i][j - 1] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (a[i][j] == 'w')
			if (a[i - 1][j - 1] == 'b')
				return 1;
		if (a[i][j] == '-')
			break;
		if (a[i][j] == 'b')
			break;
	}
	return 0;
}
int show_states(int turn,char a[20][20],int size)
{
	int i, j, k[100][2] = { '\0'}, m = 0, n, l, flag = 0;
	if (turn == 1)
	{
		for(i=0;i<=size-1;i++)
			for (j = 0; j <= size - 1; j++)
			{
				if (a[i][j] == 'b')
				{
					if (check_okw(i + 1, j - 1, a, size) == 1 && a[i + 1][j - 1] == '-' && (i + 1) >= 0 && (i + 1) < size && (j - 1) >= 0 && (j - 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i + 1) && k[n][1] == (j - 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i + 1;
							k[m][1] = j - 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i + 1 << "," << j - 1 << ")" << " ";
					if (check_okw(i, j - 1, a, size) == 1 && a[i][j - 1] == '-' && (i) >= 0 && (i) < size && (j - 1) >= 0 && (j - 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == i  && k[n][1] == (j - 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i;
							k[m][1] = j - 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i << "," << j - 1 << ")" << " ";
					if(check_okw(i-1, j-1, a, size)==1 && a[i - 1][j - 1] == '-' && (i - 1) >= 0 && (i - 1) < size && (j - 1) >= 0 && (j - 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i-1) && k[n][1] == (j - 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i - 1;
							k[m][1] = j - 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i - 1 << "," << j - 1 << ")" << " ";
					if(check_okw(i-1, j, a, size)==1 && a[i - 1][j] == '-' && (i - 1) >= 0 && (i - 1) < size && (j) >= 0 && (j) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i-1) && k[n][1] == j )
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i - 1;
							k[m][1] = j;
							m++;
						}
						flag = 0;
					}//cout << "(" << i - 1 << "," << j << ")" << " ";
					if(check_okw(i-1, j+1, a, size)==1 && a[i - 1][j + 1] == '-' && (i - 1) >= 0 && (i - 1) < size && (j + 1) >= 0 && (j + 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i-1) && k[n][1] == (j + 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i - 1;
							k[m][1] = j + 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i - 1 << "," << j + 1 << ")" << " ";
					if(check_okw(i, j+1, a, size)==1 && a[i ][j + 1] == '-' && (i) >= 0 && (i) < size && (j + 1) >= 0 && (j + 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i) && k[n][1] == (j + 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i;
							k[m][1] = j + 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i << "," << j + 1 << ")" << " ";
					if(check_okw(i+1, j+1, a, size)==1 && a[i + 1][j + 1] == '-' && (i + 1) >= 0 && (i + 1) < size && (j + 1) >= 0 && (j + 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i + 1) && k[n][1] == (j + 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i + 1;
							k[m][1] = j + 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i + 1 << "," << j + 1 << ")" << " ";
					if(check_okw(i+1, j, a, size)==1 && a[i + 1][j ] == '-' && (i + 1) >= 0 && (i + 1) < size && (j) >= 0 && (j) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i + 1) && k[n][1] == (j))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i + 1;
							k[m][1] = j;
							m++;
						}
						flag = 0;
					}//cout << "(" << i + 1 << "," << j << ")" << " ";
				}
			}
	}
	if (turn == 2)
	{
		for (i = 0; i <= size - 1; i++)
			for (j = 0; j <= size - 1; j++)
			{
				if (a[i][j] == 'w')
				{
					if (check_okb(i + 1, j - 1, a, size) == 1 && a[i + 1][j - 1] == '-' && (i + 1) >= 0 && (i + 1) < size && (j - 1) >= 0 && (j - 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i + 1) && k[n][1] == (j - 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i + 1;
							k[m][1] = j - 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i + 1 << "," << j - 1 << ")" << " ";
					if (check_okb(i, j - 1, a, size) == 1 && a[i][j - 1] == '-' && (i) >= 0 && (i) < size && (j - 1) >= 0 && (j - 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == i && k[n][1] == (j - 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i;
							k[m][1] = j - 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i << "," << j - 1 << ")" << " ";
					if (check_okb(i - 1, j - 1, a, size) == 1 && a[i - 1][j - 1] == '-' && (i - 1) >= 0 && (i - 1) < size && (j - 1) >= 0 && (j - 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i - 1) && k[n][1] == (j - 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i - 1;
							k[m][1] = j - 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i - 1 << "," << j - 1 << ")" << " ";
					if (check_okb(i - 1, j, a, size) == 1 && a[i - 1][j] == '-' && (i - 1) >= 0 && (i - 1) < size && (j) >= 0 && (j) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i - 1) && k[n][1] == j)
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i - 1;
							k[m][1] = j;
							m++;
						}
						flag = 0;
					}//cout << "(" << i - 1 << "," << j << ")" << " ";
					if (check_okb(i - 1, j + 1, a, size) == 1 && a[i - 1][j + 1] == '-' && (i - 1) >= 0 && (i - 1) < size && (j + 1) >= 0 && (j + 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i - 1) && k[n][1] == (j + 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i - 1;
							k[m][1] = j + 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i - 1 << "," << j + 1 << ")" << " ";
					if (check_okb(i, j + 1, a, size) == 1 && a[i][j + 1] == '-' && (i) >= 0 && (i) < size && (j + 1) >= 0 && (j + 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i) && k[n][1] == (j + 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i;
							k[m][1] = j + 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i << "," << j + 1 << ")" << " ";
					if (check_okb(i + 1, j + 1, a, size) == 1 && a[i + 1][j + 1] == '-' && (i + 1) >= 0 && (i + 1) < size && (j + 1) >= 0 && (j + 1) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i + 1) && k[n][1] == (j + 1))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i + 1;
							k[m][1] = j + 1;
							m++;
						}
						flag = 0;
					}//cout << "(" << i + 1 << "," << j + 1 << ")" << " ";
					if (check_okb(i + 1, j, a, size) == 1 && a[i + 1][j] == '-' && (i + 1) >= 0 && (i + 1) < size && (j) >= 0 && (j) < size)
					{
						for (n = 0; n < m; n++)
						{
							if (k[n][0] == (i + 1) && k[n][1] == (j))
								flag = 1;
						}
						if (flag == 0)
						{
							k[m][0] = i + 1;
							k[m][1] = j;
							m++;
						}
						flag = 0;
					}//cout << "(" << i + 1 << "," << j << ")" << " ";
				}
			}
	}
	cout << m << " ";
	k[m][0] = m;
	k[m][1] = 21;
	for (n = 0; n < m; n++)
	{
		flag = 0;
		for (l = 0; l < n; l++)
		{
			if (k[l][0] == k[n][0] && k[l][1] == k[n][1])
				flag = 1;
		}
		if (k[n][0] < 0 || k[n][0] >= size)
			flag = 1;
		if (k[n][1] < 0 || k[n][1] >= size)
			flag = 1;
		if (flag == 0)
			cout << "(" << k[n][0] << "," << k[n][1] << ") ";
	}
	return m;
}
char flip(char a[20][20], int x, int y, int turn,int size)
{
	int i, j;
	if (turn == 1) //tabdile 'b' be 'w'
	{
		for (i = x - 1, j = y; i >= 0; i--)
		{
			if (a[i][j] == 'b')
				if (a[i - 1][j] == 'w')
				{
					for (i, j; i < x; i++)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = (x - 1), j = (y + 1); i >= 0 && j <= size; i--, j++)
		{
			if (a[i][j] == 'b')
				if (a[i - 1][j + 1] == 'w')
				{
					for (i, j; i < x, j>y; i++, j--)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = x, j = y + 1; j <= size; j++)
		{
			if (a[i][j] == 'b')
				if (a[i][j + 1] == 'w')
				{
					for (i, j; j > y; j--)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = (x + 1), j = (y + 1); i <= size && j <= size; i++, j++)
		{
			if (a[i][j] == 'b')
				if (a[i + 1][j + 1] == 'w')
				{
					for (i, j; i > x, j > y; i--, j--)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = (x + 1), j = y; i <= size; i++)
		{
			if (a[i][j] == 'b')
				if (a[i + 1][j] == 'w')
				{
					for (i, j; i > x; i--)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = (x + 1), j = y - 1; i <= size && j >= 0; i++, j--)
		{
			if (a[i][j] == 'b')
				if (a[i + 1][j - 1] == 'w')
				{
					for (i, j; i > x, j < y; i--, j++)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = x, j = (y - 1); j >= 0; j--)
		{
			if (a[i][j] == 'b')
				if (a[i][j - 1] == 'w')
				{
					for (i, j; j < y; j++)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
		for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (a[i][j] == 'b')
				if (a[i - 1][j - 1] == 'w')
				{
					for (i, j; j < y, i < x; j++, i++)
						a[i][j] = 'w';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'w')
				break;
		}
	}
	if (turn == 2) //tabdile 'w' be 'b'
	{
		for (i = x - 1, j = y; i >= 0; i--)
		{
			if (a[i][j] == 'w')
				if (a[i - 1][j] == 'b')
				{
					for (i, j; i < x; i++)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = (x - 1), j = (y + 1); i >= 0 && j <= size; i--, j++)
		{
			if (a[i][j] == 'w')
				if (a[i - 1][j + 1] == 'b')
				{
					for (i, j; i < x, j>y; i++, j--)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = x, j = y + 1; j <= size; j++)
		{
			if (a[i][j] == 'w')
				if (a[i][j + 1] == 'b')
				{
					for (i, j; j > y; j--)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = (x + 1), j = (y + 1); i <= size && j <= size; i++, j++)
		{
			if (a[i][j] == 'w')
				if (a[i + 1][j + 1] == 'b')
				{
					for (i, j; i > x, j > y; i--, j--)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = (x + 1), j = y; i <= size; i++)
		{
			if (a[i][j] == 'w')
				if (a[i + 1][j] == 'b')
				{
					for (i, j; i > x; i--)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = (x + 1), j = y - 1; i <= size && j >= 0; i++, j--)
		{
			if (a[i][j] == 'w')
				if (a[i + 1][j - 1] == 'b')
				{
					for (i, j; i > x, j < y; i--, j++)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = x, j = (y - 1); j >= 0; j--)
		{
			if (a[i][j] == 'w')
				if (a[i][j - 1] == 'b')
				{
					for (i, j; j < y; j++)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
		for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
		{
			if (a[i][j] == 'w')
				if (a[i - 1][j - 1] == 'b')
				{
					for (i, j; j < y, i < x; j++, i++)
						a[i][j] = 'b';
					break;
				}
			if (a[i][j] == '-')
				break;
			if (a[i][j] == 'b')
				break;
		}
	}
	return a[20][20];
}
int game(int c,int f)
{
	int i,m,n,x,y,turn=1,v,o, whites = 0, blacks = 0;
	char b[20][20];
	for (m = 0; m <= 19; m++)
		for (n = 0; n <= 19; n++)
			b[m][n] = '-';
	b[c / 2 - 1][c / 2 - 1] = 'w';
	b[c / 2][c / 2] = 'w';
	b[c / 2][c / 2 - 1] = 'b';
	b[c / 2 - 1][c / 2] = 'b';
	if (f == 1)
	{
		for (i = 1; i <= (c * c)-4; i++)
		{
			int flag = 0,a1=1,a2=1;
			blacks = 0;
			whites = 0;
			for(v=0;v<c;v++)
				for (o = 0; o < c; o++)
				{
					if (b[v][o] == 'b')
						blacks++;
					if (b[v][o] == 'w')
						whites++;
				}
			cout << "White`s point: " << whites << "\n";
			cout << "black`s point: " << blacks << "\n";
			if(turn==1)
			    a1= show_states(turn, b, c);
			else if(turn==2)
				a2= show_states(turn, b, c);
			if (a1 == 0 && a2!=0)
			{
					cout << "No possible moves for white!"<<"\n";
					turn = 2;
					i--;
					continue;
			}
			if (a1 != 0 && a2==0)
			{
					cout << "No possible moves for black!"<<"\n";
					turn = 1;
					i--;
					continue;
			}
			if (a1 == 0)
				if(a2==0)
			      {
					blacks = 0;
					whites = 0;
					for (v = 0; v < c; v++)
						for (o = 0; o < c; o++)
						{
							if (b[v][o] == 'b')
								blacks++;
							if (b[v][o] == 'w')
								whites++;
						}
				cout << "The winner is: ";
				if (blacks > whites)
				{
					cout << "BLACK!" << "\n";
					cout << "White`s point: " << whites << "\n";
					cout << "black`s point: " << blacks << "\n";
				}
				if (whites > blacks)
				{
					cout << "WHITE!" << "\n";
					cout << "White`s point: " << whites << "\n";
					cout << "black`s point: " << blacks << "\n";
				}
				if (whites == blacks)
				{
					cout << "NO ONE!" << "\n";
					cout << "White`s point: " << whites << "\n";
					cout << "black`s point: " << blacks << "\n";
				}
				  return 0;
			       }
			cout << endl;
			game_map(c, b);
			if (turn == 1)
				cout << "White`s move: ";
			if (turn == 2)
				cout << "Black`s move: ";
			x = char_to_num();
			y = char_to_num();
			if (turn == 1)
			{
				if (check_okw(x, y, b, c) == 1)
					 flip(b, x, y, turn, c);
				else
				{
					system("cls");
					cout << "Invalid input! Try again " << "\n";
					i--;
					continue;
				}
			}
			if (turn == 2)
			{
					if (check_okb(x, y, b, c) == 1)
						flip(b, x, y, turn, c);
					else
					{
						system("cls");
						cout << "Invalid input! Try again "<<"\n";
						i--;
						continue;
					}
			}
			if (turn == 1)
			{
				b[x][y] = 'w';
				turn = 2;
				system("cls");
				continue;
			}
			if (turn == 2)
			{
				b[x][y] = 'b';
				turn = 1;
				system("cls");
				continue;
			}
		}
		cout << "The winner is: ";
		if (blacks > whites)
		{
			cout << "BLACK!"<<"\n";
			cout << "White`s point: " << whites << "\n";
			cout << "black`s point: " << blacks << "\n";
		}
		if (whites > blacks)
		{
			cout << "WHITE!" << "\n";
			cout << "White`s point: " << whites << "\n";
			cout << "black`s point: " << blacks << "\n";
		}
		if (whites == blacks)
		{
			cout << "NO ONE!"<<"\n";
			cout << "White`s point: " << whites << "\n";
			cout << "black`s point: " << blacks << "\n";
		}
		return 0;
	}
	return 0;
}