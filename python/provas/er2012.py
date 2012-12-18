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
    """INTEGRAL TRIPLA QG"""
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


def pvi_pvc():
    """PVI PVC"""
    f = eval('lambda x, y, z: ' + raw_input('Entre F(x, y, z): '))
    x0, y0, z0, xn, n = input('Entre X0, Y0, Y\'0, XN, N: ')
    h = float(xn - x0) / n # float para forçar divisão fracionária
    x, y, z = x0, y0, z0

    for i in range(0, n):
        k1 = h * z
        l1 = h * f(x, y, z)
        k2 = h * (z + l1)
        l2 = h * f(x + h, y + k1, z + l1)
        z = z + (l1 + l2) / 2
        y = y + (k1 + k2) / 2
        x = x + h

    print 'YN =', y
    print 'ZN =', z

    yn, zn = y, z
    n, tol, nmi = input('Entre N, TOL, NMI: ')
    fy = lambda x, y, z: (f(x, y + tol, z) - f(x, y - tol, z)) / (2 * tol)
    fz = lambda x, y, z: (f(x, y, z + tol) - f(x, y, z - tol)) / (2 * tol)

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
        print 'y[%d] =' % i, y[i]


def policar(a, n):
    b = [None] * (n + 1)
    for i in range(1, n + 1):
        b[i] = [None] * (n + 1)
        for j in range(1, n + 1):
            b[i][j] = a[i][j]

    p = [1.0] * (n + 1)
    for i in range(1, n + 1):
        p[i] = 0.0
        for j in range(1, n + 1):
            p[i] = p[i] + b[j][j]
        p[i] = p[i] / i

        for j in range(1, n + 1):
            b[j][j] = b[j][j] - p[i]

        for j in range(1, n + 1):
            c = [None] * (n + 1)
            for k in range(1, n + 1):
                c[k] = b[k][j]
                b[k][j] = 0

            for k in range(1, n + 1):
                for l in range(1, n + 1):
                    b[k][j] = b[k][j] + a[k][l] * c[l] # ???

    return p


def autovet(n, a, autoval):
    b = [[None] * (n + 1)] * (n + 1)
    x = [[None] * (n + 1)] * (n + 1)
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            b[i][j] = a[i][j]
            if j == i:
                x[i][j] = 1.0
            else:
                x[i][j] = 0.0

    for k in range(1, n):
        p = 0.0
        for i in range(1, n + 1):
            p = p + b[i][i]
        p = p / k

        for i in range(1, n + 1):
            b[i][i] = b[i][i] - p
            for j in range(1, n + 1):
                x[i][j] = autoval[j] * x[i][j] + b[i][j]

        for i in range(1, n + 1):
            c = [None] * (n + 1)
            for j in range(1, n + 1):
                c[j] = b[j][i]
                b[j][i] = 0

            for j in range(1, n + 1):
                for l in range(1, n + 1):
                    b[j][i] = b[j][i] + a[j][l] * c[l]

    return x



def faddeev_leverrier():
    """FADDEEV LEVERRIER"""
    n = input('Entre N: ')
    a = [None] * (n + 1)
    for i in range(1, n + 1):
        a[i] = [None] * (n + 1)
        for j in range(1, n + 1):
            a[i][j] = input('Entre A(%d, %d): ' % (i, j))
    print a
    p = policar(a, n)
    print p


FUNCS = [
    integral_tripla_qg,
    pvi_pvc,
    faddeev_leverrier,
    # adicione mais funcoes aqui
]


faddeev_leverrier()
if __name__ == '__main__!':
    loop = True
    while loop:
        try:
            for i, f in enumerate(FUNCS):
                print i + 1, '-', f.func_doc
            k = input('Esolha uma rotina: ')
            FUNCS[k - 1]()
        except KeyboardInterrupt:
            loop = False
    print

