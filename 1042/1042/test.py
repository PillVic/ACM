def foo(a):
    r = 1
    while a!=1:
        r *=a
        a -=1
    return r

for i in range(0, 10001):
    print(foo(i))
