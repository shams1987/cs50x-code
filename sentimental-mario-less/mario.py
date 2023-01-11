# TODO

def main():
    # import get_int
    from cs50 import get_int
    # promt for height
    height = get_int("Height: ")
    # edge cases rejection
    if height < 1 or height > 8:
        print("Please input number between 1 to 8")
        main()
    # loop and print
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)


main()