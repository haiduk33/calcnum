from base import *


@algoritmo
def newtonraphson(self, f, x0):
    df = lambda x: (f(x + self.tol) - f(x - self.tol)) / (2 * self.tol)
    for _ in xrange(self.nmi):
        x = x0 - f(x0) / df(x0)
        if abs(x - x0) < self.tol and abs(f(x)) < self.tol:
            return x
        x0 = x
    raise ErroNMI

