from base import *


@algoritmo
def falsaposicao(self, f, xi, xf):
    if f(xi) * f(xf) > 0:
        raise ErroIntervalo
    for _ in xrange(self.nmi):
        p = f(xi) / f(xf)
        xm = xi - (xf - xi) / (1 / p - 1)
        if (abs(xf - xm) < self.tol or abs(xi - xm) < self.tol) and abs(f(xm)) < self.tol:
            return xm
        (xi, xf) = (xi, xm) if f(xm) * f(xi) < 0 else (xm, xf)
    raise ErroNMI

