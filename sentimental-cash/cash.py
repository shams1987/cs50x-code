# TODO
from cs50 import get_float


def main():
    change = int(get_float("Change owed: ") * 100)
    coins = 0
    # if proper change
    if change > 0:

        while change > 0:
            # for quarters
            if change > 24:
                change -= 25
                coins += 1
                # print("quarters " + str(coins))
            # for dimes
            elif change > 9 and change < 25:
                change -= 10
                coins += 1
                # print("dimes " + str(coins))
            # for nickels
            elif change > 4 and change < 10:
                change -= 5
                coins += 1
                # print("nickels " + str(coins))
            # for pennies
            elif change > 0 and change < 5:
                change -= 1
                coins += 1
                # print("pennies " + str(coins))
        print(coins)
    # not proper change
    else:
        main()


main()