#take a input that is a incredibly large number and add it with another incredibly large number
    #Inputs are strings
    #Output is a string value that is a sum of the two inputs
#Note that int maxes out at some value and that you have to iterate through the string value

number1 = "9091231203901293019301920392103921090219302193019203921391239102930129031923012930129301293021930192301923012930219309210392103912093021930192039210391203192039"

test1 = "88888"
test2 = "21111"

def largeNumberAddition(input1, input2):
    number_of_additions = min(len(input1), len(input2))
    difference_in_chars = abs(len(input1) - len(input2))
    output = ""
    chopped = ""
    if len(input1) > len(input2) and difference_in_chars != 0:
        for i in range(0,difference_in_chars-1):
            chopped += input1[i]
    elif len(input2) > len(input1) and difference_in_chars != 0:
        for i in range(0,difference_in_chars-1):
            chopped += input2[i]
    elif difference_in_chars != 0:
        pass

    carry = False
    for i in reversed(range(0, number_of_additions)):
        x = int(input1[i])
        y = int(input2[i])
        sum = x + y
        if sum == 9 and carry is True:
            output += str(0)
            carry = True
        if sum == 10 and carry is True:
            output
        elif sum >= 10 and carry is True:
            output += str(sum - 10 + 1)
            carry = True
        elif sum >= 10 and carry is False:
            print("I'm here", sum)
            output += str(sum - 10)
            carry = True
        else:
            output += str(sum)
            carry = False
        print(carry)
        print(output)

    return chopped + output[::-1]


print(largeNumberAddition(test1, test2))
