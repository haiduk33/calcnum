from math import pi, e, sin, cos, tan, factorial
from collections import OrderedDict
from pprint import *

pie = pi / e


def somatermos(n, termo):
    return sum(termo(float(i)) for i in xrange(n))


def mysin(x, n):
    return somatermos(n, lambda i: (x ** (2 * i + 1)) * (-1) ** i / factorial(2 * i + 1))


def mycos(x, n):
    return somatermos(n, lambda i: (x ** (2 * i)) * (-1) ** i / factorial(2 * i))


def mytan(x, n):
    return mysin(x, n) / mycos(x, n)


def mypi(n):
    return somatermos(n, lambda i: 4 * (-1) ** i / (2 * i + 1))


def mye(n):
    return somatermos(n, lambda i: 1.0 / factorial(i))


def mypie(n):
    return mypi(n) / mye(n)


def tabela(n):
    valores = OrderedDict([
        ('pi', [pi, mypi(n)]),
        ('e', [e, mye(n)]),
        ('pi/e', [pie, mypie(n)]),
        ('sen(pi/e)', [sin(pie), mysin(mypie(n), n)]),
        ('cos(pi/e)', [cos(pie), mycos(mypie(n), n)]),
        ('tg(pi/e)', [tan(pie), mytan(mypie(n), n)]),
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
    map(tabela, [3, 10, 30, 85])

