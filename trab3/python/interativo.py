# coding=utf-8
from base import Calcnum, eq
from bissecao import bissecao
from falsaposicao import falsaposicao
from iteracaolinear import iteracaolinear
from newtonraphson import newtonraphson
from secantes import secantes

def _entrada(msg, tipo, *opts):
    if tipo == 'opt':
        for k, opt in enumerate(opts[0]):
            print '{0}. {1}'.format(k + 1, opt[1])
        inp = raw_input(msg + ': ')
        try:
            return opts[0][int(inp) - 1][0]
        except ValueError:
            for opt in opts[0]:
                if opt[1].lower().startswith(inp.lower()):
                    return opt[0]
            raise ValueError
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

def entrada(msg, tipo, *opts):
    while True:
        try:
            return _entrada(msg, tipo, *opts)
        except ValueError:
            print 'Entrada não reconhecida.'

def resolver(nmi, tol, equacao, metodo, params):
    mets = dict(metodos)
    print
    print 'Resolvendo a equacao "{0}" pelo método {1} com parâmetros {2} ...'.format(equacao.orig, mets[metodo], params)
    calc = Calcnum(nmi, tol)
    calc.aplicar(metodo, equacao, *params)
    print

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

