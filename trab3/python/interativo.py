# coding=utf-8
from base import Calcnum, eq
from bissecao import bissecao
from falsaposicao import falsaposicao
from iteracaolinear import iteracaolinear
from newtonraphson import newtonraphson
from secantes import secantes

def entrada(msg, tipo=None, *opts):
    if tipo == 'opt':
        inp = raw_input(msg + ': ')
        try:
            return opts[0][int(inp)]
        except ValueError:
            for opt in opts[0]:
                if opt[1].lower().startswith(inp.lower()):
                    return opt[0]
    else:
        inp = raw_input(msg + ': ')
        if tipo == 'int':
            return int(inp)
        if tipo == 'float':
            return float(inp)
        if tipo == 'floatarray':
            inp = inp.translate(None, '[](),')
            return map(lambda t: float(t), inp.split())
        if tipo == 'eq':
            return eq(inp)

def resolver(nmi, tol, equacao, metodo, params):
    mets = dict(metodos)
    print 'Resolvendo a equacao "{0}" pelo método "{1}" com parâmetros {2} ...'.format(equacao.orig, mets[metodo], params)
    calc = Calcnum(nmi, tol)
    calc.aplicar(metodo, equacao, *params)

metodos = [
    (bissecao, 'Bisseção'),
    (falsaposicao, 'Falsa Posição'),
    (newtonraphson, 'Newton-Raphson'),
    (iteracaolinear, 'Iteração Linear'),
    (secantes, 'Secantes'),
]

try:
    nmi = entrada('Entre com o NMI (Número Máximo de Iterações)', 'int')
    tol = entrada('Entre com a tolerância (exemplo: 0.001 ou 1.0e-3 ou 1e-3)', 'float')
    equ = entrada('Entre com a equação (exemplo: cos(x) = x, ou sen(x) - x = 0)', 'eq')
    met = entrada('Escolha um método (exemplo 1 ou biss ou new)', 'opt', metodos)
    par = entrada('Entre com os parâmetros para o método (exemplo: 1.0 ou 0.6, 0.8)', 'floatarray')
    resolver(nmi, tol, equ, met, par)

except KeyboardInterrupt:
    print

finally:
    print 'Fim do programa.'

