#!/usr/bin/python3

"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes"""


def canUnlockAll(boxes):
    """method that determines
    if all the boxes can be opened"""

    n_boxes = len(boxes)

    for key in range(1, n_boxes - 1):
        flag = 0
        for box in range(n_boxes):
            if key in boxes[box] and key != box:
                flag = 1
                break
        if flag == 0:
            return False
    return True
