from cs50 import get_int

n = get_int("Please enter integer\n")
while n < 1 or n > 8:
    n = get_int("Please enter integer\n")

# spaces
k = n - 1
# outer loop
for i in range(0, n):
    # inner loop
    for j in range(0, k):
        print(end=" ")

    k = k - 1
    # the hashtag
    for j in range(0, i+1):
        print("#", end="")
    print()
