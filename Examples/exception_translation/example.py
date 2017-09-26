from exception_translation import *
try:
    func_from_cpp(False)
    print("reach here")
    func_from_cpp(True)
    print("Not going to reach here")
except MyCPPException as e:
    print("Exception occure")
    print("e.message: ", e.message)
    print("e.extraData", e.extraData)

