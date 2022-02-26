"""
This time we want to write calculations using functions and get the results. Let's have a look at some examples:

seven(times(five())) # must return 35
four(plus(nine())) # must return 13
eight(minus(three())) # must return 5
six(divided_by(two())) # must return 3
Requirements:

There must be a function for each number from 0 ("zero") to 9 ("nine")
There must be a function for each of the following mathematical operations: plus, minus, times, divided_by
Each calculation consist of exactly one operation and two numbers
The most outer function represents the left operand, the most inner function represents the right operand
Division should be integer division. For example, this should return 2, not 2.666666...:
eight(divided_by(three()))
"""

import operator

ops = {
    '+' : operator.add,
    '-' : operator.sub,
    '*' : operator.mul,
    '/' : operator.floordiv,  # use operator.div for Python 2
}


def eval_binary_expr(op1, oper, op2):
    op1, op2 = int(op1), int(op2)
    return ops[oper](op1, op2)


def zero(input = False): #your code here
    if input == False:
        print(str(0))
        return str(0)
    else:
        output = "0 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def one(input = False): #your code here
    if input == False:
        print(str(1))
        return str(1)
    else:
        output = "1 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def two(input = False): #your code here
    if input == False:
        print(str(2))
        return str(2)
    else:
        output = "2 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def three(input = False): #your code here
    if input == False:
        print(str(3))
        return str(3)
    else:
        output = "3 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def four(input = False):
    if input == False:
        print(str(4))
        return str(4)
    else:
        output = "4 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def five(input = False):
    if input == False:
        print(str(5))
        return str(5)
    else:
        output = "5 " + str(input)
        print(output)
        return eval_binary_expr(*(output.split()))


def six(input = False):
    if input == False:
        print(str(6))
        return str(6)
    else:
        output = "6 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def seven(input = False): #your code here
    if input == False:
        print(str(7))
        return str(7)
    else:
        output = "7 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def eight(input = False): #your code here
    if input == False:
        print(str(8))
        return str(8)
    else:
        output = "8 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def nine(input = False): #your code here
    if input == False:
        print(str(9))
        return str(9)
    else:
        output = "9 " + input
        print(output)
        return eval_binary_expr(*(output.split()))


def plus(numb):
    return "+ " + numb
def minus(numb): #your code here
    return "- " + numb
def times(numb): #your code here
    return "* " + numb
def divided_by(numb): #your code here
    return "/ " + numb
