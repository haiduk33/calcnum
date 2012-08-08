# coding=utf-8
from math import *
from pprint import print_table


class Calcnum(object):
    def __init__(self, nmi, tol):
        self.nmi = nmi
        self.tol = tol
        self.tabelar = False

    def tabela(self, *vals):
        self._tabela.append(vals)

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
            prec = int(ceil(-log10(self.tol)))
            if prec < 0: prec = 0
            print ('Raiz: {0:.%df}' % prec).format(raiz)


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


