"""
Write a function named first_non_repeating_letter that takes a string input, and
returns the first character that is not repeated anywhere in the string.

For example, if given the input 'stress', the function should return 't', since
the letter t only occurs once in the string, and occurs first in the string.

As an added challenge, upper- and lowercase letters are considered the same character,
but the function should return the correct case for the initial letter. For example,
the input 'sTreSS' should return 'T'.

If a string contains all repeating characters, it should return an empty string ("")
or None -- see sample tests.
"""


def first_non_repeating_letter(string):
    unique = []
    string_list_lower = []
    for x in string:
        if x not in unique:
            unique.append(x)
    for y in string:
        string_list_lower.append(y.lower())

    for i in unique:
        lower_i = i.lower()
        if string_list_lower.count(lower_i) == 1:
            return i

    return ""