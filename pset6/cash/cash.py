from cs50 import get_float

n = get_float("Change owed: ")
while (n <= 0):
    n = get_float("Change owed: ")

cents = round(n * 100)
change = 0

# if not $0.00 we still owe change
while (cents > 0):
    # Check Greedy Algo against each coin
    while (cents >= 25):
        cents = cents - 25
        change += 1

    while (cents >= 10):
        cents = cents - 10
        change += 1

    while (cents >= 5):
        cents = cents - 5
        change += 1

    while (cents >= 1):
        cents = cents - 1
        change += 1

# print result
print(change);