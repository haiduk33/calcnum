from base import *


@algoritmo
def iteracaolinear(self, f, x0):
    g = lambda x: f(x) + x
    x1 = g(x0)
    self.tabela('k', 'x0', 'x1', 'g(x1)')
    for k in xrange(self.nmi):
        x2 = g(x1)
        self.tabela(k, x0, x1, x2)
        if abs(x2 - x1) < self.tol and abs(x1 - x0) < self.tol:
            return x1
        x0, x1 = x1, x2
    raise ErroNMI

