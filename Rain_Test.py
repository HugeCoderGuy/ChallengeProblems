test = 11111110000000101111111100000000
      #11111110.00000010.11111111.11111111.ect
      #PacketHead.Version.AltLSB.AltMSB.ect


# Convert LSB byte to decimal value
def LSBbyte_to_value(data):
    str_data = str(data)  # convert to string for indexing purposes.
                          # decided to index data this way because I'm not sure which type it comes in on
                          # over the UART so it seemed safe to convert it to an expected data type
    number = int(str_data[0])*2**7 + int(str_data[1])*2**6 + int(str_data[2])*2**5 + int(str_data[3])*2**4 + \
             int(str_data[4])*2**3 + int(str_data[5])*2**2 + int(str_data[6])*2**1 + int(str_data[7])*2**0
    return number


# Convert MSB byte to decimal value
def MSBbyte_to_value(data):
    str_data = str(data)  # convert to string for indexing purposes
    number = int(str_data[0])*2**15 + int(str_data[1])*2**14 + int(str_data[2])*2**13 + int(str_data[3])*2**12 + \
             int(str_data[4])*2**11 + int(str_data[5])*2**10 + int(str_data[6])*2**9 + int(str_data[7])*2**8
    return number


# take entire UART message and return altitude
def find_alt(data):
    str_data = str(data)
    LSB = str_data[16:24]  # get Byte 3 info
    MSB = str_data[24:32]  # get Byte 4 info
    altitude = MSBbyte_to_value(MSB) + LSBbyte_to_value(LSB)  # altitude in centimeters
    altitude_in_meters = altitude / 100  # I find meters easier to work with
    return altitude_in_meters


#Max value of two bytes is 65535
print(find_alt(test))
