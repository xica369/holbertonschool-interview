#!/usr/bin/python3

"""script that reads stdin line by line and computes metrics:"""

import sys

count = 0
size = 0
codes_dict = {"200": 0, "301": 0, "400": 0, "401": 0,
              "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for line in sys.stdin:
        split = line.split()
        split = split[::-1]
        count += 1

        if count <= 10:
            size += int(split[0])

            code = split[1]
            if code in codes_dict.keys():
                codes_dict[code] += 1

        if count == 10:
            print("File size: {}".format(size))
            for key, val in sorted(codes_dict.items()):
                if val != 0:
                    print("{}: {}".format(key, val))

            count = 0
            size = 0
            codes_dict = {"200": 0, "301": 0, "400": 0, "401": 0,
                          "403": 0, "404": 0, "405": 0, "500": 0}

except:
    pass

finally:
    print("File size: {}".format(size))
    for key, val in sorted(codes_dict.items()):
        if val != 0:
            print("{}: {}".format(key, val))
