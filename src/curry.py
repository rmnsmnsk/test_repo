def sum(x, y, z):
    return x + y + z


def curry(f, arn):

    if arn < 0:
        raise ValueError("Арность не может быть отрицательной")
    if not isinstance(arn, int):
        raise ValueError("Это должно быть целое число неотрицательное число")
    if arn > 3:
        raise ValueError("Арность не больше 3")

    def curry2(*args):

        if len(args) >= arn:
            return f(*args)

        else:
            def next(next_arg):
                args1 = (next_arg,) + args
                return curry2(*args1)
            return next

    return curry2


def uncurry(f, arn):

    if arn < 0:
        raise ValueError("Арность не может быть отрицательной")
    if not isinstance(arn, int):
        raise ValueError("Это должно быть целое число неотрицательное число")
    if arn > 3:
        raise ValueError("Арность не больше 3")

    def q(*args):

        sum = f

        for argument in args:
            sum = sum(argument)

        return sum
    
    return q

sum3_curry = curry(sum, 3)
sum3_uncurry = uncurry(sum3_curry, 3)
print(sum3_curry(1)(2)(3))    # 6
print(sum3_uncurry(1, 2, 3))  # 6
