#include <stdio.h>

#define MI	255

int main()
{
	/*
	0 --20--> 1, 1 --30--> 4, 4--10--> 6
	0 --10--> 2, 2 --50--> 4, 4--5-->5
	0 --30--> 3, 3 --1--> 4, 4--50--> 6
	 
	*/
	int graph[7][7] = {
			{0,  20, 10, 30, MI, MI, MI},
			{MI,  0, MI, 30, MI, MI, MI},
			{MI, MI, 0, 0, 
			{MI, 20, 10, 30, MAX_INT, MAX_INT, MAX_INT},
			{MI, 20, 10, 30, MAX_INT, MAX_INT, MAX_INT},
			{MI, 20, 10, 30, MAX_INT, MAX_INT, MAX_INT},
			{MI, 20, 10, 30, MAX_INT, MAX_INT, MAX_INT}
			}
}
