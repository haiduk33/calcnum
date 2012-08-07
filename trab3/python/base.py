# coding=utf-8
from math import *


class Calcnum(object):
    def __init__(self, nmi, tol):
        self.nmi = nmi
        self.tol = tol

    def aplicar(self, metodo, *args):
        try:
            raiz = metodo(self, *args)
        except ErroNMI:
            print 'Ultrapassou o nmi'
        except ErroIntervalo:
            print 'Não há garantia de existencia de raiz neste intervalo'
        else:
            prec = int(ceil(-log10(self.tol)))
            if prec < 0: prec = 0
            print ('Raiz: {0:.%df}' % prec).format(raiz)


class ErroNMI(Exception):
    pass


class ErroIntervalo(Exception):
    pass


def eq(string):
    try:
        return eval('lambda x: ({0})'.format(')-('.join(string.split('='))))
    except:
        raise TypeError('Equação inválida.')


def algoritmo(func):
    return func


