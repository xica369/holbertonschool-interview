#!/usr/bin/python3

"""program that solves the N queens problem

Usage: nqueens N

where N must be an integer greater or equal to 4
The program should print everrow possible solution to the problem
"""

import sys


def queens_potions(N, row, queens):
    """program that solves the N queens problem"""

    # iterate over all the columns of the board
    for column in range(Nq):
        flag = 0

        # compare to queens already located on the board
        for queen in queens:

            # validates if there is another queen on the diagonals
            if abs(column - queen[1]) == abs(row - queen[0]):
                flag = 1
                break

            # validates if there is another queen in the column
            if column == queen[1]:
                flag = 1
                break

        # add the new queen if has no threat with another
        if flag == 0:
            queens.append([row, column])

            # function is called if they are not iterated over all the rows
            if row != Nq - 1:
                queens_potions(Nq, row + 1, queens)

            else:
                print(queens)

            queens.pop()


if __name__ == "__main__":
    """receive console arguments and call function"""

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        exit(1)

    Nq = int(sys.argv[1])

    if Nq < 4:
        print("N must be at least 4")
        exit(1)

    row = 0
    queens = []
    queens_potions(Nq, row, queens)
