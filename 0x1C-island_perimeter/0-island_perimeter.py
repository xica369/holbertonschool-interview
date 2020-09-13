#!/usr/bin/python3

"""
Island Perimeter
"""


def island_perimeter(grid):
    """
    Function that returns the perimeter of the island described in grid:

    - grid is a list of list of integers:
      0 represents water
      1 represents land

    Each cell is square, with a side length of 1
    Cells are connected horizontally/vertically (not diagonally).
    grid is rectangular, with its width and height not exceeding 100
    The grid is completely surrounded by water
    There is only one island (or nothing).
    The island doesn’t have “lakes”
    (water inside that isn’t connected to the water surrounding the island).
    """

    grid_len = len(grid[0])
    water = [0] * (grid_len + 2)
    perimeter = 0

    # add water above and below
    grid.insert(0, water)
    grid.append(water)

    for row in range(1, len(grid) - 1):

        # add water on the left and right
        grid[row].insert(0, 0)
        grid[row].append(0)

        for col in range(1, grid_len + 1):
            if grid[row][col] == 1:

                # check for water above
                if grid[row - 1][col] == 0:
                    perimeter += 1

                # check for water below
                if grid[row + 1][col - 1] == 0:
                    perimeter += 1

                # check for water on the left
                if grid[row][col - 1] == 0:
                    perimeter += 1

                # check for water on the right
                if grid[row][col + 1] == 0:
                    perimeter += 1

    return perimeter
