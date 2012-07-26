from math import pi, e, sin, cos, tan, factorial
from collections import OrderedDict
from pprint import *

pie = pi / e


def mysin(x, n):
    termo = lambda i: (x ** (2 * i + 1)) * (-1) ** i / factorial(2 * i + 1)
    return sum(termo(i) for i in xrange(n))


def mycos(x, n):
    termo = lambda i: (x ** (2 * i)) * (-1) ** i / factorial(2 * i)
    return sum(termo(i) for i in xrange(n))


def mytan(x, n):
    return mysin(x, n) / mycos(x, n)


def tabela(n):
    valores = OrderedDict([
        ('pi', [pi, pi]),# tem que aproximar pi tambem??
        ('e', [e, e]),# aproximar e tambem??
        ('pi/e', [pie, pie]),# aproximar pi/e??
        ('sen(pi/e)', [sin(pie), mysin(pie, n)]),
        ('cos(pi/e)', [cos(pie), mycos(pie, n)]),
        ('tg(pi/e)', [tan(pie), mytan(pie, n)]),
    ])
    for v in valores.itervalues():
        ve, va = v[0], v[1]
        eabs = ve - va
        erel = eabs / ve
        v.append(eabs)
        v.append(erel)
    tab = [[key] + vals for key, vals in valores.iteritems()]
    tab.insert(0, ['n={0}'.format(n), 'Ve', 'Va', 'Eabs', 'Erel',])
    print_table(tab)
    print


if __name__ == '__main__':
    # imprimir as tabelas n=3 e n=10
    map(tabela, [3, 10])

