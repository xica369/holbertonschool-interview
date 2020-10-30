#!/usr/bin/python3

"""
Prime Game
"""


def isWinner(x, nums):
    """
    - x is the number of rounds
    - nums is an array of n

    Return: name of the player that won the most rounds
    If the winner cannot be determined, return None
    """

    prime_numbers = get_prime(nums)

    len_prime_num = len(prime_numbers)

    if len_prime_num > 0:
        if len_prime_num % 2 == 0:
            return "Maria"
        else:
            return "Ben"

    return None


def get_prime(nums):
    """get all prime numbers"""

    prime_numbers = []

    for num in nums:

        if num == 1:
            prime_numbers.append(num)

        if num >= 2:
            flag = 0

            for iter in range(2, num):
                if num % iter == 0:
                    flag = 1
                    break

            if flag == 0:
                prime_numbers.append(num)

    set_prime = set(prime_numbers)
    prime_numbers = list(set_prime)

    return prime_numbers
