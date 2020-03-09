#!/usr/bin/python3

"""Operaciones mínimas"""


def minOperations(n):
    """Returns an integer
    If n is impossible to achieve, return 0"""

    if not isinstance(n, int):
        return 0

    if n <= 1 or n is None:
        return 0

    aux = 2
    temp = n
    h = 0

    while temp >= aux:

        if temp % aux == 0:
            h = h + aux
            temp = temp / aux

        else:
            aux = aux + 1
    return h
