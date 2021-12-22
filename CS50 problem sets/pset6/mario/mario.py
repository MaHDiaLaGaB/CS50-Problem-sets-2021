from cs50 import get_int
n = get_int("Height: ")
while n < 1 or n > 8:
    n = get_int("Height: ")
for x in range(n):
    for i in range(0, n - x - 1, 1):
        print(" ", end="")
    for j in range(x + 1):
        print("#", end="")
    print()
