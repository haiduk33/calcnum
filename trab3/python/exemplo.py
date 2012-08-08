# coding=utf-8
from base import Calcnum, eq
from bissecao import bissecao
from falsaposicao import falsaposicao
from iteracaolinear import iteracaolinear
from newtonraphson import newtonraphson
from secantes import secantes

calc = Calcnum(100, 1e-10)
calc.tabelar = True

eq1 = 'cos(x) = x'
eq2 = 'exp(x) = 3 * x'

def exemplo(titulo, metodo, equacoes):
    print '[{0}]'.format(titulo)
    for e in equacoes:
        print 'Equação: {0}'.format(e[0])
        for args in e[1]:
            calc.aplicar(metodo, eq(e[0]), *args)
        print

map(lambda e: exemplo(*e), [
    ['Bisseção', bissecao, [
        [eq1, [(0.6, 0.8)]],
    ]],
    ['Falsa Posição', falsaposicao, [
        [eq1, [(0.6, 0.8)]],
    ]],
    ['Iteração Linear', iteracaolinear, [
        [eq1, [(0.6,)]],
        [eq2, [(0.6,)]],
    ]],
    ['Newton-Raphson', newtonraphson, [
        [eq1, [(2.0,)]],
        [eq2, [(1.0,), (2.0,)]],
    ]],
    ['Secantes', secantes, [
        [eq1, [(0.0, 1.0)]],
    ]],
])

