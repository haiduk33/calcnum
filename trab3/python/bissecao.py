from base import *


@algoritmo
def bissecao(self, f, xi, xf):
    if f(xi) * f(xf) > 0:
        raise ErroIntervalo
    for _ in xrange(self.nmi):
        xm = (xi + xf) / 2
        if abs(xf - xi) < self.tol and abs(f(xm)):
            return xm
        (xi, xf) = (xi, xm) if f(xm) * f(xi) < 0 else (xm, xf)
    raise ErroNMI

