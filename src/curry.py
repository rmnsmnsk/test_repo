def curry(f, arity):
    def curried(*args):
        if len(args) >= arity:
            return f(*args)
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


def sum(x, y, z):
    return x + y + z


def sub(x, y):
    return x - y


if __name__ == "__main__":
    sum3_curry = curry(sum, 3)
    sum3_uncurry = uncurry(sum3_curry, 3)

    print(sum3_curry(1)(2)(3))
    print(sum3_uncurry(1, 2, 3))

    sub_curry = curry(sub, 2)
    print(sub_curry(10)(2))