def curry(func, n):
    if not isinstance(n, int):
        raise TypeError("n должно быть целым числом")
    if n < 0:
        raise ValueError("n должно быть неотрицательным числом")
    
    arg_count = func.__code__.co_argcount
    if n > arg_count:
        raise ValueError(f"n ({n}) превышает количество параметров функции ({arg_count})")
    
    def curried(*args):
        if len(args) >= n:
            return func(*args)
        else:
            def next_func(next_arg):
                return curried(*args + (next_arg,))
            return next_func
    return curried


def uncurry(curried_func, arity):
    def uncurried_func(*args):
        if len(args) != arity:
            raise ValueError(f"Ожидается {arity} аргументов, получено {len(args)}")

        result = curried_func
        for arg in args:
            result = result(arg)
        return result

    return uncurried_func


def add_three_numbers(x, y, z):
    return x + y + z


def sub(x, y):
    return x - y


if __name__ == "__main__":
    sum3_curry = curry(add_three_numbers, 3)
    sum3_uncurry = uncurry(sum3_curry, 3)

    print(sum3_curry(1)(2)(3))
    print(sum3_uncurry(1, 2, 3))
 
    sub_curry = curry(sub, 2)
    print(sub_curry(10)(2))
