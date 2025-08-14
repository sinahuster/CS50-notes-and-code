# while loop that allows user to input desired height between 1 and 8
height = 0
while height < 1 or height > 8:
    try:
        height = int(input("Height: "))
    except ValueError:
        continue


# iterate through the height printing empty spaces and then #
# which add together to height
for i in range(height):
    print(" " * (height - (i + 1)) + "#" * (i + 1) + "  " + "#" * (i + 1))
