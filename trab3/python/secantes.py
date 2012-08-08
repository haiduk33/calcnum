from base import *


@algoritmo
def secantes(self, f, xi, xf):
    self.tabela('k', 'xi', 'xf', 'x', 'f(xi)', 'f(xf)')
    for k in xrange(self.nmi):
        fxi, fxf = f(xi), f(xf)
        p = fxf / fxi
        x = xf - (xi - xf) * p / (1 - p)
        self.tabela(k, xi, xf, x, fxi, fxf)
        if abs(x - xf) < self.tol and abs(f(x)) < self.tol:
            return x
        xi, xf = xf, x
    raise ErroNMI

