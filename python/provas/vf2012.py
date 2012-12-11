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


def volume():
    a, b = input('Entre A, B: ')
    c, d = input('Entre C, D: ')
    n = input('Entre N: ')

    f0 = 0
    for i in range(0, n):
        ti = T[n][i]
        x = ((b - a) * ti + a + b) / 2

        f1 = 0
        for j in range(0, n):
            tj = T[n][j]
            y = ((d - c) * tj + c + d) / 2
            z = input('Entre Z(%d,%d): ' % (i, j))
            p1 = (d - c) * z / 2
            f1 = f1 + p1 * W[n][j]

        p = (b - a) * f1 / 2
        f0 = f0 + p * W[n][i]

    print 'f0 =', f0


#TODO: validar/corrigir
def pvi_pvc_ajuste():
    f = lambda x, y, z: (3 * y * y + 10 * z * z * z) / (10 * x * y)
    x0, y0, z0, xn, n = input('Entre X0, Y0, Y\'0, XN, N: ')
    h = (xn - x0) / float(n) # float para forçar divisão fracionária
    x, y, z = x0, y0, z0

    for i in range(0, n):
        k1 = h * z
        l1 = h * f(x, y, z)
        k2 = h * (z + l1)
        l2 = h * f(x + h, y + k1, z + l1)
        z = z + (l1 + l2) / 2
        y = y + (k1 + k2) / 2
        x = x + h

    yn, zn = y, z
    n, tol, nmi = input('Entre N, TOL, NMI: ')
    fy = lambda x, y, z: 0.3 / x - z * z / (y * y)
    fz = lambda x, y, z: 2 * z / y

    # não precisa calcular h denovo
    v = [0] * (n + 2) # lista de tamanho n + 2
    y = [0] * (n + 2) # lista de tamanho n + 2

    for i in range(1, n):
        y[i] = y0 * i * h * (yn - y0) / (xn - x0)
    kc, vc = 1, 1
    k, t = [0] * (n + 1), [0] * (n + 1) # listas de tamanho n + 1

    while kc <= nmi and abs(vc) > tol:
        for i in range(1, n):
            x = x0 + i * h
            z = (y[i + 1] - y[i - 1]) / (2 * h)
            a = -1 - h * fz(x, y[i], z) / 2
            b = 2 + h * h * fy(x, y[i], z)
            c = -1 + h * fz(x, y[i], z) / 2
            d = y[i - 1] - 2 * y[i] + y[i + 1] - h * h * f(x, y[i], z)
            den = b - a * t[i - 1]
            k[i] = (d - a * t[i - 1]) / den
            t[i] = c / den
        v[n - 1] = k[n - 1]; vc = v[n - 1]
        y[n - 1] = y[n - 1] + v[n - 1]

        for i in range(n - 2, 0, -1):
            v[i] = k[i] - t[i] * v[i + 1]
            y[i] = y[i] + v[i]
            if abs(vc) < abs(v[i]):
                vc = v[i]
        kc = kc + 1

    for i in range(0, n + 1):
        print 'y[i] =', y[i]

    f = lambda x: a * x ** (b * x)
    from math import log, exp
    f1 = lambda y: log(y)
    f2 = lambda x: x * log(x)
    f3 = lambda a: exp(a)
    f4 = lambda b: b
    sx = sy = sx2 = sxy = ym = 0; m = n + 1

    for i in range(0, n + 1):
        sy = sy + f1(y[i])
        sx = sx + f2(x)
        sxy = sxy + f1(y[i]) * f2(x)
        sx2 = sx2 + f2(x) ** 2
        ym = ym + y[i] / m

    b = (sxy - sx * sy / m) / (sx2 - sx * sx / m)
    a = (sy - b * sx) / m
    sn = sd = 0
    a = f3(a)
    b = f4(b)

    for i in range(1, m + 1):
        sn = sn + (y[i] - f(x)) ** 2
        sd = sd + (y[i] - ym) ** 2
    r2 = 1 - sn / sd

    print 'a =', a, 'b =', b, 'r =', r
    for i in range(0, n + 1):
        print 'y[i] =', y[i]


def aquifero():
    n = input('Entre N: ')
    t, s, h, ti, tempo = input('Entre T, S, H, TI, TEMPO: ')
    r = input('Entre R(x, y, t): ') # entrada deve ser do tipo 'lambda x, y, z: x+y+z'
    p = s * h ** 2 / (4 * t)

    # criar listas que vão ser usadas
    x = [None] * (n + 1)
    y = [None] * (n + 1)
    c = [None] * (n + 1)
    v = [[None] * 5] * (n + 1)
    u = [None] * (n + 1)
    w = [None] * (n + 1)

    for i in range(1, n + 1):
        x[i], y[i] = input('Entre X(%d), Y(%d): ' % (i, i))
        c[i] = 0
        for j in range(1, 5):
            v[i][j] = input('Entre V(%d, %d): ' % (i, j))
            if v[i][j] == 0:
                ci = input('Entre CI: ')
                c[i] = c[i] + ci
        u[i] = 0

    k = u[0] = 0; te = ti
    d = 1

    while d == 1 and k <= int(tempo / p):
        d = 0
        for i in range(1, n + 1):
            w[i] = c[i] + r(x[i], y[i], te) * h ** 2 / t
            for j in range(1, 5):
                w[i] = w[i] + u[v[i][j]]
            w[i] = w[i] / 4
            if abs(w[i] - u[i]) > tol:
                d = 1
        k = k + 1; te = te + p
        print 'te =', te
        for i in range(1, n + 1):
            u[i] = w[i]
            print 'u[i] =', u[i]
