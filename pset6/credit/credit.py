from cs50 import get_int

def main():
    # Get user input
    n = get_int("Number: ")
    # Print the correct validation
    print(n)
    print(validate(n))

#Get the checksum
def luhns(number):
    sum = 0
    i = 0
    while number > 0:
        sum += number % 10
        number /= 10
        product = (number % 10) * 2
        if product < 10:
            sum += product
        else:
            while product > 0:
                sum += product % 10
                product /= 10
        number /= 10
        i += 2
    # Validate length and see if valid by Luhns algo (0)
    if i >= 13 and sum % 10 == 0:
        return True

# Look at first digits and determine CC company
def validate(number):
    isValid = luhns(number)
    n = firstDigits(number)
    # Quickly determine if valid length
    if isValid == False:
        return "INVALID\n"
    else:
        if n == 34 or n == 37:
            return "AMEX\n"
        elif n == 51 or n == 52 or n == 53 or n == 54 or n == 55:
            return "MASTERCARD\n"
        elif int(n / 10) == 4:
            return "VISA\n"
        else:
            return "INVALID\n"

# Get the first 2 digits
def firstDigits(number):
    while number >= 100:
        number /= 10
    # return first 2 digits
    convert = int(number)
    return convert

main()