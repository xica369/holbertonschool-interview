#!/usr/bin/python3

"""
0x16. Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees
    """

    matrix_copy = matrix.copy()

    for iter in range(len(matrix[0])):
        temp_list = []

        for row in reversed(matrix_copy):
            temp_list.append(row[iter])

        matrix[iter] = temp_list
