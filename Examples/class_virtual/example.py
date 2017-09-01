import class_virtual

class DerivedA(class_virtual.Base):
    pass

class DerivedB(class_virtual.Base):
    def f(self):
        return "x"

if __name__ == "__main__":
    da = DerivedA()
    db = DerivedB()
    print(db.f())
    da.f()
