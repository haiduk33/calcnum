from base import *


@algoritmo
def bissecao(self, f, xi, xf):
    self.tabela('k', 'xi', 'xf', 'xm', 'f(xm)')
    if f(xi) * f(xf) > 0:
        raise ErroIntervalo
    for k in xrange(self.nmi):
        xm = (xi + xf) / 2
        fxm = f(xm)
        self.tabela(k, xi, xf, xm, fxm)
        if abs(xf - xi) < self.tol and abs(fxm):
            return xm
        (xi, xf) = (xi, xm) if f(xm) * f(xi) < 0 else (xm, xf)
    raise ErroNMI

