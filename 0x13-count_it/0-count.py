#!/usr/bin/python3
"""
function that queries the Reddit API, parses the title of all hot articles, and
prints a sorted count of given keywords (case-insensitive, delimited by spaces
"""

import requests
after = None


def count_words(subreddit, word_list):
    """
    Results should be printed in descending order, by the count, not the title.
    Words with no matches should be skipped and not printed.
    Results are based on the number of times a keyword appears, not titles
    it appears in.
    """

    hot_list = recurse(subreddit)
    word_dict = {}

    if hot_list:
        for word in word_list:
            word_dict[word.lower()] = 0

        for title in hot_list:
            title_split = title.split(" ")

            for word in title_split:
                if word.lower() in word_dict:
                    word_dict[word.lower()] += 1

        sort_dict = sorted(word_dict.items(), reverse=True)
        for key, val in sort_dict:
            if val != 0:
                print("{}: {}".format(key, val))


def recurse(subreddit, hot_list=[]):
    """
    returns a list containing the titles of all hot articles for a given
    subreddit.

    If no results are found for the given subreddit,
    the function should return None.
    """

    global after
    headers = {'User-Agent': 'xica369'}
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    parameters = {'after': after}
    response = requests.get(url, headers=headers, allow_redirects=False,
                            params=parameters)

    if response.status_code == 200:
        next_ = response.json().get('data').get('after')
        if next_ is not None:
            after = next_
            recurse(subreddit, hot_list)
        list_titles = response.json().get('data').get('children')
        for title_ in list_titles:
            hot_list.append(title_.get('data').get('title'))
        return hot_list
    else:
        return (None)
