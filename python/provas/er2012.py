# coding: utf-8

T = [None,
    [0],
    [0.57735027, -0.57735027],
    [0.77459667, -0.77459667, 0],
    [0.86113631, -0.86113631, 0.33998104, -0.33998104],
    [0.90617985, -0.90617985, 0.53846931, -0.53846931, 0],
    #TODO: continuar, tabela na pag 313
]
W = [None,
    [2.0],
    [1.0, 1.0],
    [0.55555556, 0.55555556, 0.88888889],
    [0.34785483, 0.34785483, 0.65214516, 0.65214516],
    [0.23692688, 0.23692688, 0.47862868, 0.47862868, 0.56888889],
    #TODO: continuar, tabela na pag 313
]

def integral_tripla_qg():
    f = eval('lambda x, y, z: ' + raw_input('Entre F(x, y, z): '))
    g1 = eval('lambda x: ' + raw_input('Entre g1(x): '))
    h1 = eval('lambda x: ' + raw_input('Entre h1(x): '))
    g2 = eval('lambda x, y: ' + raw_input('Entre g2(x, y): '))
    h2 = eval('lambda x, y: ' + raw_input('Entre h2(x, y): '))
    a, b = input('Entre A, B: ')
    n = input('Entre N: ')
    f0 = 0
    for i in range(0, n):
        ti = T[n][i]
        x = ((b - a) * ti + a + b) / 2.0
        f1 = 0
        for j in range(0, n):
            tj = T[n][j]
            y = ((h1(x) - g1(x)) * tj + g1(x) + h1(x)) / 2.0
            f2 = 0
            for k in range(0, n):
                tk = T[n][k]
                z = ((h2(x, y) - g2(x, y)) * tk + g2(x, y) + h2(x, y)) / 2.0
                f2 = f2 + (h2(x, y) - g2(x, y)) * f(x, y, z) * W[n][k] / 2.0
            f1 = f1 + (h1(x) - g1(x)) * f2 * W[n][j] / 2.0
        f0 = f0 + (b - a) * f1 * W[n][i] / 2.0
    print 'f0 =', f0