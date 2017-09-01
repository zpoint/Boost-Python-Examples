import class_virtual_nopure

class DerivedA(class_virtual_nopure.Base):
    pass

class DerivedB(class_virtual_nopure.Base):
    def f(self):
        return "x"

if __name__ == "__main__":
    da = DerivedA()
    db = DerivedB()
    print(db.f())
    print(da.f())
