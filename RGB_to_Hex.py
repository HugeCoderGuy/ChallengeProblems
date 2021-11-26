"""
The rgb function is incomplete. Complete it so that passing in RGB decimal values will
result in a hexadecimal representation being returned. Valid decimal values for RGB are
0 - 255. Any values that fall out of that range must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work
here.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
"""


def rgb(r, g, b):
    if r >= 255:
        red = "FF"
    elif r <= 0:
        red = "00"
    else:
        red = hex(r)
        red = red[2:]
        if len(red) == 1 and int(red, 16) >= 10:
            red += str(0)
            print("r ", red)
        elif len(red) == 1 and int(red) <= 9:
            red = "0" + red

    if g >= 255:
        green = "FF"
    elif g <= 0:
        green = "00"
    else:
        green = hex(g)
        green = green[2:]
        if len(green) == 1 and int(green, 16) >= 10:
            green += str(0)
        elif len(green) == 1 and int(green) <= 9:
            green = "0" + green

    if b >= 255:
        blue = "FF"
    elif b <= 0:
        blue = "00"
    else:
        blue = hex(b)
        blue = blue[2:]
        if len(blue) == 1 and int(blue, 16) >= 10:
            blue += str(0)
        elif len(blue) == 1 and int(blue) <= 9:
            blue = "0" + blue

    return red.upper() + green.upper() + blue.upper()