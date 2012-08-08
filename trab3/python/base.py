# coding=utf-8
from math import *
from pprint import print_table


class Calcnum(object):
    def __init__(self, nmi, tol):
        self.nmi = nmi
        self.tol = tol
        self.tabelar = False

    def prec(self, val):
        prec = int(ceil(-log10(self.tol)))
        if prec < 0: prec = 0
        return ('{0:.%df}' % prec).format(val)

    def tabela(self, *vals):
        if self.tabelar:
            new_vals = []
            for val in vals:
                if isinstance(val, float):
                    new_vals.append(self.prec(val))
                else:
                    new_vals.append(val)
            self._tabela.append(new_vals)

    def aplicar(self, metodo, *args):
        try:
            self._tabela = []
            raiz = metodo(self, *args)
        except ErroNMI:
            print 'Ultrapassou o nmi'
        except ErroIntervalo:
            print 'Não há garantia de existencia de raiz neste intervalo'
        else:
            if self.tabelar:
                print_table(self._tabela)
            print 'Raiz: {0}'.format(self.prec(raiz))


class ErroNMI(Exception):
    pass


class ErroIntervalo(Exception):
    pass


def eq(string):
    try:
        fun = eval('lambda x: ({0})'.format(')-('.join(string.split('='))))
        fun.orig = string
        return fun
    except:
        raise ValueError('Equação inválida.')


def algoritmo(func):
    return func


