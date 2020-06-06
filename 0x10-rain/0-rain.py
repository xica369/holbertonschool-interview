#!/usr/bin/python3

"""
Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """
    walls is a list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    """

    if not walls:
        return 0

    if sum(walls) == 0 or len(walls) < 3:
        return 0

    previous_wall = 0
    spaces = 0
    retained = 0

    for wall in walls:

        if wall != 0 and previous_wall != 0:
            if wall > previous_wall:
                retained += previous_wall * spaces
            else:
                retained += wall * spaces

            previous_wall = wall
            spaces = 0

        if wall != 0 and previous_wall == 0:
            previous_wall = wall

        if wall == 0 and previous_wall != 0:
            spaces += 1

    return retained
