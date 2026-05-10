
class A:pass

class B(A):pass

class C(B):pass

class D(B):pass

c = C()



print(c.__class__.__mro__[1].__subclasses__()[1])