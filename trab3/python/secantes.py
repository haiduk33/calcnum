from base import *


@algoritmo
def secantes(self, f, xi, xf):
    for _ in xrange(self.nmi):
        p = f(xf) / f(xi)
        x = xf - (xi - xf) * p / (1 - p)
        if abs(x - xf) < self.tol and abs(f(x)) < self.tol:
            return x
        xi, xf = xf, x
    raise ErroNMI

