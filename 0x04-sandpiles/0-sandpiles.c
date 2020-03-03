#include "sandpiles.h"

void evaluate_grid(int grid[3][3])
{
  int c1, c2, num, flag = 0;

  for (c1 = 0; c1 < 3; c1++)
    {
      for (c2 = 0; c2 < 3; c2++)
	{
	  num = grid[c1][c2];
	  if (num > 3)
	    {
	      flag = 1;
	      break;
	    }
	}
    }
  if (flag == 1)
    {
      prints_grid(grid);
      topple(grid);
    }
}

/**
 * prints_grid - prints the grid
 *
*@grid1: grid to prints
 *
 */
void prints_grid(int grid[3][3])
{
  int i, j;

  printf("=\n");

  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  if (j)
	    printf(" ");
	  printf("%d", grid[i][j]);
	}
      printf("\n");
    }
}


/**
 * topple - topple the sand
 *
 *@grid1: grid to review
 *
 */

void topple(int grid[3][3])
{
  int c1, c2, num;
  int grid_aux[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  for (c1 = 0; c1 < 3; c1++)
    {
      for (c2 = 0; c2 < 3; c2++)
	{
	  num = grid[c1][c2];
	    if (num > 3)
	      {
		grid[c1][c2] = num - 4;
		if (c1 + 1 < 3)
		  grid_aux[c1 + 1][c2]++;
		if (c1 - 1 >= 0)
		  grid_aux[c1 - 1][c2]++;
		if (c2 + 1 < 3)
		  grid_aux[c1][c2 + 1]++;
		if (c2 - 1 >= 0)
		  grid_aux[c1][c2 - 1]++;
	      }
	}
    }
  sandpiles_sum(grid, grid_aux);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 *
 *@grid1: first grid
 *@grid2: second grid
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
  int c1 = 0, c2 = 0;

    for (c1 = 0; c1 < 3; c1++)
      {
	for (c2 = 0; c2 < 3; c2++)
	  {
	    grid1[c1][c2] = grid1[c1][c2] + grid2[c1][c2];
	  }
      }
    evaluate_grid(grid1);
}
