def main():
    num = -1

    # allow user to input number
    while num < 0:
        try:
            num = int(input("Number: "))
        except ValueError:
            continue

    # initialise variables
    original = num
    sum_odd = 0
    sum_even = 0
    digits = 0

    # apply Luhn's algorithm
    while num > 0:
        current_digit = num % 10
        if digits % 2 == 0:
            sum_odd += current_digit
        else:
            doubled = current_digit * 2
            if doubled >= 10:
                sum_even += (doubled % 10) + (doubled // 10)
            else:
                sum_even += doubled
        num //= 10
        digits += 1

    # check if the total is a multiple of 10
    total = sum_even + sum_odd
    if (total % 10) != 0:
        print("INVALID")
        return 1

    # find the first two digits of the number
    while original >= 100:
        original //= 10

    first_two = original
    first = original // 10

    # check if the numbers and length of the number matches to any of the card types
    if first == 4 and (digits == 13 or digits == 16):
        print("VISA")
    elif (first_two == 34 or first_two == 37) and digits == 15:
        print("AMEX")
    elif (first_two >= 51 and first_two <= 55) and digits == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
        return 1


main()
