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

    Maria = 0
    Ben = 0

    prime_numbers, new_numbers = get_prime(nums)

    for prime in prime_numbers:
        for num in range(len(new_numbers)):
            if new_numbers[num] % prime == 0:
                new_numbers[num] = 0

    len_prime_num = len(prime_numbers)

    if len_prime_num > 0:
        if len_prime_num % 2 == 0:
            return "Ben"
        else:
            return "Maria"

    return None


def get_prime(nums):
    """get all prime numbers"""

    prime_numbers = []
    new_nums = []
    for num in nums:

        if num < 2:
            new_nums.append(num)

        if num >= 2:
            flag = 0

            for iter in range(2, num):
                if num % iter == 0:
                    flag = 1
                    break

            if flag == 0:
                prime_numbers.append(num)
            else:
                new_nums.append(num)

    return prime_numbers, new_nums
