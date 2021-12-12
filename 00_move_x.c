#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct canva
{
	int x_size;
	int y_size;
	char **arr;
} canva_struct;

canva_struct *generate_new_canva(int new_x_size, int new_y_size)
{
	canva_struct *canva = malloc(sizeof(canva_struct));
	canva->x_size = new_x_size;
	canva->y_size = new_y_size;
	canva->arr = malloc(sizeof(char *) * new_y_size);
	for (int i = 0; i < new_y_size; i++)
	{
		canva->arr[i] = malloc(sizeof(char) * new_x_size);
		for (int n = 0; n < new_x_size; n++)
		{
			canva->arr[i][n] = '-';
		}
	}
	return canva;
}

void print_2d_array(canva_struct *canva)
{
	printf("\e[1;1H\e[2J"); // clear screen
	printf(" ");
	for (int n = 0; n < canva->x_size; n++)
	{
		printf("%2d", n);
	}
	printf("\n");
	for (int i = 0; i < canva->y_size; i++)
	{
		printf("%2d", i);
		for (int n = 0; n < canva->x_size; n++)
		{
			printf("%c ", canva->arr[i][n]);
		}
		printf("\n");
	}
}

char get_pixel(int from_x, int from_y, canva_struct *canva)
{
	return canva->arr[from_y][from_x];
}

void delete_pixel(int from_x, int from_y, canva_struct *canva)
{
	canva->arr[from_y][from_x] = '-';
}

void put_pixel(int to_x, int to_y, canva_struct *canva)
{
	canva->arr[to_y][to_x] = 'X';
}

void move_pixel(int from_x, int from_y, int to_x, int to_y, canva_struct *canva)
{
	char t;
	t = get_pixel(from_x, from_y, canva);
	delete_pixel(from_x, from_y, canva);
	if (t == 'X')
	{
		put_pixel(to_x, to_y, canva);
	}
	else
	{
		delete_pixel(to_x, to_y, canva);
	}
}

int main(int argc, char **argv)
{
	int size_x = 7;
	int size_y = 8;
	canva_struct *canva;

	canva = generate_new_canva(size_x, size_y);
	put_pixel(1, 2, canva);
	put_pixel(3, 4, canva);
	move_pixel(3, 4, 5, 7, canva);
	print_2d_array(canva);
	return 0;
}