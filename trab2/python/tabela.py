from math import pi, e, sin, cos, tan, factorial
from collections import OrderedDict
from pprint import print_table

pie = pi / e


def tabela(n):
    somatorio = lambda termo: sum(termo(float(i)) for i in xrange(n))
    mysin = lambda x: somatorio(lambda i: (x ** (2 * i + 1)) * (-1) ** i / factorial(2 * i + 1))
    mycos = lambda x: somatorio(lambda i: (x ** (2 * i)) * (-1) ** i / factorial(2 * i))
    mytan = lambda x: mysin(x) / mycos(x)
    mypi = somatorio(lambda k: 4 * (-1) ** k / (2 * k + 1))
    mye = somatorio(lambda k: 1.0 / factorial(k))
    mypie = mypi / mye

    # calcular valores
    valores = OrderedDict([
        ('pi', [pi, mypi]),
        ('e', [e, mye]),
        ('pi/e', [pie, mypie]),
        ('sen(pi/e)', [sin(pie), mysin(mypie)]),
        ('cos(pi/e)', [cos(pie), mycos(mypie)]),
        ('tg(pi/e)', [tan(pie), mytan(mypie)]),
    ])

    # calcular erros
    for v in valores.itervalues():
        ve, va = v[0], v[1]
        eabs = ve - va
        erel = eabs / ve
        v.append(eabs)
        v.append(erel)
    tab = [[key] + vals for key, vals in valores.iteritems()]
    tab.insert(0, ['n={0}'.format(n), 'Ve', 'Va', 'Eabs', 'Erel',])

    # imprimir tabela e uma linha em branco
    print_table(tab)
    print


if __name__ == '__main__':
    # imprimir as tabelas de cada valor da lista
    map(tabela, [3, 10, 30, 85])

