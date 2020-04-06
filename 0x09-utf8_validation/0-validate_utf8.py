#!/usr/bin/python3

"""
method that determines if a given data set represents a valid UTF-8 encoding
"""

import sys


def validUTF8(data):
    """Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need
    to handle the 8 least significant bits of each integer"""

    continuos_10 = 0

    for byte in data:

        byte = format(byte, '#010b')[-8:]

        if continuos_10 == 0:

            for num in byte:
                if num == '0':
                    break

                continuos_10 += 1

            if continuos_10 == 0:
                continue

            if continuos_10 == 1 or continuos_10 > 4:
                return False
        else:

            if not (byte[0] == '1' and byte[1] == '0'):
                return False

        continuos_10 -= 1

    return continuos_10 == 0
