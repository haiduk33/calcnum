from base import *


@algoritmo
def iteracaolinear(self, f, x0):
    g = lambda x: f(x) + x
    x1 = g(x0)
    for _ in xrange(self.nmi):
        x2 = g(x1)
        if abs(x2 - x1) < self.tol and abs(x1 - x0) < self.tol:
            return x1
        x0, x1 = x1, x2
    raise ErroNMI

