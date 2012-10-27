from base import *


@algoritmo
def falsaposicao(self, f, xi, xf):
    if f(xi) * f(xf) > 0:
        raise ErroIntervalo
    self.tabela('k', 'xi', 'xf', 'f(xi)/f(xf)', 'xm', 'f(xm)')
    for k in xrange(self.nmi):
        p = f(xi) / f(xf)
        xm = xi - (xf - xi) / (1 / p - 1)
        fxm = f(xm)
        self.tabela(k, xi, xf, p, xm, fxm)
        if (abs(xf - xm) < self.tol or abs(xi - xm) < self.tol) and abs(fxm) < self.tol:
            return xm
        (xi, xf) = (xi, xm) if f(xm) * f(xi) < 0 else (xm, xf)
    raise ErroNMI

