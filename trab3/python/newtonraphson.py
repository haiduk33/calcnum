from base import *


@algoritmo
def newtonraphson(self, f, x0):
    df = lambda x: (f(x + self.tol) - f(x - self.tol)) / (2 * self.tol)
    self.tabela('k', 'x0', 'f(x0)', 'f\'(x0)', 'x')
    for k in xrange(self.nmi):
        fx0, dfx0 = f(x0), df(x0)
        x = x0 - fx0 / dfx0
        self.tabela(k, x0, fx0, dfx0, x)
        if abs(x - x0) < self.tol and abs(f(x)) < self.tol:
            return x
        x0 = x
    raise ErroNMI

