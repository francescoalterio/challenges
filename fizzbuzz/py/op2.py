def fizzbuzz(index, limit):
    if index > limit:
        return
    if index % 15 == 0:
        print("FizzBuzz")
    elif index % 3 == 0:
        print("Fizz")
    elif index % 5 == 0:
        print("Buzz")
    else:
        print(index)
    return fizzbuzz(index + 1, limit)

fizzbuzz(1, 100)