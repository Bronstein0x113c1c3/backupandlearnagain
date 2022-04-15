#include <iostream>

using namespace std;

int main()
{
	char heartarray [6][7];
	
	for (int i = 0; i < 6; i++)
	{		
		switch(i)
		{
		case 0:
		for (int j = 0; j < 7; j++)	
		{
			switch(j)
			{
			case 0: heartarray [i][j] = ' ';
			break;
			case 1: heartarray [i][j] = '*';
			break;
			case 2: heartarray [i][j] = '*';
			break;
			case 3: heartarray [i][j] = ' ';
			break;
			case 4: heartarray [i][j] = '*';
			break;
			case 5: heartarray [i][j] = '*';
			break;
			case 6: heartarray [i][j] = '*';
			break;
			}
		 }break;
		case 1:
		for (int j = 0; j < 7; j++)
		{
			switch(j)
			{
			case 0: heartarray [i][j] = '*';
			break;
			case 1: heartarray [i][j] = '*';
			break;
			case 2: heartarray [i][j] = '*';
			break;
			case 3: heartarray [i][j] = '*';
			break;
			case 4: heartarray [i][j] = '*';
			break;
			case 5: heartarray [i][j] = '*';
			break;
			case 6: heartarray [i][j] = '*';
			break;
			}
		} break;
		case 2:
		for (int j = 0; j < 7; j++)
		{
			switch (j)
			{
			case 0: heartarray [i][j] = '*';
			break;
			case 1: heartarray [i][j] = '*';
			break;
			case 2: heartarray [i][j] = '*';
			break;
			case 3: heartarray [i][j] = '*';
			break;
			case 4: heartarray [i][j] = '*';
			break;
			case 5: heartarray [i][j] = '*';
			break;
			case 6: heartarray [i][j] = '*';
			break;
			}
		} break;
		case 3:
		for (int j = 0; j < 7; j++)
		{
			switch (j)
			{
			case 0: heartarray [i][j] = ' ';
			break;
			case 1: heartarray [i][j] = '*';
			break;
			case 2: heartarray [i][j] = '*';
			break;
			case 3: heartarray [i][j] = '*';
			break;
			case 4: heartarray [i][j] = '*';
			break;
			case 5: heartarray [i][j] = '*';
			break;
			case 6: heartarray [i][j] = ' ';
			break;
			}
		} break;
		case 4:
		for (int j = 0; j < 7; j++)
		{
			switch(j)
			{
			case 0: heartarray [i][j] = ' ';
			break;
			case 1: heartarray [i][j] = ' ';
			break;
			case 2: heartarray [i][j] = '*';
			break;
			case 3: heartarray [i][j] = '*';
			break;
			case 4: heartarray [i][j] = '*';
			break;
			case 5: heartarray [i][j] = ' ';
			break;
			case 6: heartarray [i][j] = ' ';
			break;
			}
		} break;
		case 5:
		for (int j = 0; j < 7; j++)
		{
			switch(j)
			{
			case 0: heartarray [i][j] = ' ';
			break;
			case 1: heartarray [i][j] = ' ';
			break;
			case 2: heartarray [i][j] = ' ';
			break;
			case 3: heartarray [i][j] = '*';
			break;
			case 4: heartarray [i][j] = ' ';
			break;
			case 5: heartarray [i][j] = ' ';
			break;
			case 6: heartarray [i][j] = ' ';
			break;
			}
		} break;
	}
	}
	
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
			cout << heartarray[i][j];
		cout << endl;
	}

	return 0;
}