from math import pi, e, sin, cos, tan, factorial
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
    valores = [
        ['n={0}'.format(n), 'Ve', 'Va', 'Eabs', 'Erel'],
        ['pi', pi, mypi],
        ['e', e, mye],
        ['pi/e', pie, mypie],
        ['sen(pi/e)', sin(pie), mysin(mypie)],
        ['cos(pi/e)', cos(pie), mycos(mypie)],
        ['tg(pi/e)', tan(pie), mytan(mypie)],
    ]

    # calcular erros
    for v in valores[1:]:
        ve, va = v[1], v[2]
        eabs = ve - va
        erel = eabs / ve
        v.append(eabs)
        v.append(erel)

    # imprimir tabela e uma linha em branco
    print_table(valores)
    print


if __name__ == '__main__':
    # imprimir as tabelas de cada valor da lista
    map(tabela, [3, 10, 30, 85])

