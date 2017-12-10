import basic_interface

class X(list):
    def __init__(self, *args, **kwargs):
        super(X, self).__init__(*args, **kwargs)
    
    def __setattr__(self, name, value):
        self.__dict__[name] = value

    def __getattr__(self, item):
        return self.__dict__[item]


def func_y(a, b):
    return a + len(b)

if __name__ == "__main__":
    item1 = X("I am handsome")
    item1.items = 1
    item2 = "foo"
    print(basic_interface.f(item1, item2))
    print("".join(basic_interface.getfunc()(item1, func_y)))

