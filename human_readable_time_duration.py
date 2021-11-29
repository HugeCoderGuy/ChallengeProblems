"""
Your task in order to complete this Kata is to write a function which formats a duration,
given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. If it is zero, it just returns "now".
Otherwise, the duration is expressed as a combination of years, days, hours, minutes and
seconds.

It is much easier to understand with an example:

format_duration(62)    # returns "1 minute and 2 seconds"
format_duration(3662)  # returns "1 hour, 1 minute and 2 seconds"
For the purpose of this Kata, a year is 365 days and a day is 24 hours.

Note that spaces are important.

Detailed rules

The resulting expression is made of components like 4 seconds, 1 year, etc. In general,
a positive integer and one of the valid units of time, separated by a space. The unit
of time is used in plural if the integer is greater than 1.

The components are separated by a comma and a space (", "). Except the last component,
which is separated by " and ", just like it would be written in English.

A more significant units of time will occur before than a least significant one. Therefore,
second and 1 year is not correct, but 1 year and 1 second is.

Different components have different unit of times. So there is not repeated units like in 5
seconds and 1 second.

A component will not appear at all if its value happens to be zero. Hence, 1 minute and 0
seconds is not valid, but it should be just 1 minute.

A unit of time must be used "as much as possible". It means that the function should not
return 61 seconds, but 1 minute and 1 second instead. Formally, the duration specified by
of a component must not be greater than any valid more significant unit of time.
"""


def format_duration(seconds):
    if seconds == 0:
        return "now"
    year, days, hour, minute, second = 0, 0, 0, 0, 0
    minute, second = divmod(seconds, 60)
    hour, minute = divmod(minute, 60)
    day, hour = divmod(hour, 24)
    year, day = divmod(day, 365)
    print(year, day, hour, minute, second)
    deletes = []

    list = [["year", year], ["day", day], ["hour", hour], ["minute", minute], ["second", second]]

    for i, item in enumerate(list):
        if item[1] > 1:
            item[0] += "s"
        elif item[1] == 0:
            deletes.append(i)

    for j in reversed(deletes):
        del list[j]

    if len(list) == 1:
        return str(list[0][1]) + " " + str(list[0][0])
    elif len(list) == 2:
        return str(list[0][1]) + " " + str(list[0][0]) + " and " + str(list[1][1]) + " " + str(list[1][0])
    elif len(list) == 3:
        return str(list[0][1]) + " " + str(list[0][0]) + ", " + str(list[1][1]) + " " + str(list[1][0]) + " and " + \
               str(list[2][1]) + " " + str(list[2][0])
    elif len(list) == 4:
        return str(list[0][1]) + " " + str(list[0][0]) + ", " + str(list[1][1]) + " " + str(list[1][0]) + ", " + \
               str(list[2][1]) + " " + str(list[2][0]) + " and " + str(list[3][1]) + " " + str(list[3][0])
    else:
        return str(list[0][1]) + " " + str(list[0][0]) + ", " + str(list[1][1]) + " " + str(list[1][0]) + ", " + \
               str(list[2][1]) + " " + str(list[2][0]) + ", " + str(list[3][1]) + " " + str(list[3][0]) + " and " + \
               str(list[4][1]) + " " + str(list[4][0])

