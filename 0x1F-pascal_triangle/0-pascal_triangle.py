#!/usr/bin/python3

"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    - n will be always an integer

    Returns a list of lists of integers representing the Pascal’s triangle of n
    or an empty list if n <= 0
    """

    if n <= 0:
        return []

    pascal_triangle = [[1]]

    for row in range(1, n):
        line = [1] * (row + 1)
        pascal_triangle.append(line)

        for col in range(1, row):
            pascal_triangle[row][col] = pascal_triangle[row-1][col-1]
            pascal_triangle[row][col] += pascal_triangle[row-1][col]

    return pascal_triangle
