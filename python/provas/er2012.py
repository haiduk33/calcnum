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
    y[0], y[n] = y0, yn

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
            k[i] = (d - a * k[i - 1]) / den
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

    p = [-1.0] * (n + 1)
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
    b = [None] * (n + 1)
    x = [None] * (n + 1)
    for i in range(1, n + 1):
        b[i] = [None] * (n + 1)
        x[i] = [None] * (n + 1)
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


from math import sqrt
def eq2g(a, b, c):
    delta = b * b - 4.0 * a * c
    pr = -b / (2.0 * a)
    pi = sqrt(abs(delta)) / (2.0 * a)
    if delta >= 0:
        return [pr + pi, pr - pi]
    else:
        return [pr + pi * 1j, pr - pi * 1j]


def newton_bairstow(n, a):
    tol, nmi = input('Entre TOL, NMI: ')
    t = a[n]
    v = [None] * (n + 1)
    for i in range(n, -1, -1):
        a[i] = a[i] / t
        v[i] = a[i]
    m = n
    for i in range(0, m + 1):
        for j in range(0, m):
            if abs(v[j]) > abs(v[j + 1]):
                v[j], v[j + 1] = v[j + 1], v[j]
    p0 = v[m] / v[m - 2]
    q0 = v[m - 1] / v[m - 2]
    j = 0
    b = [None] * (n + 3)
    c = [None] * (n + 3)
    r = [None] * n
    while m > 2:
        b[m + 2] = b[m + 1] = c[m + 2] = c[m + 1] = 0
        p = p0; q = q0
        dp = dq = 1.0
        k = 0
        while abs(dp) + abs(dq) > tol and k <= nmi:
            for i in range(m, 0, -1):
                b[i] = a[i] - p * b[i + 1] - q * b[i + 2]
                c[i] = b[i] - p * c[i + 1] - q * c[i + 2]
            b[0] = a[0] - p * b[1] - q * b[2]
            c1 = c[1] - b[1]
            d = c[2] * c[2] - c1 * c[3]
            if abs(d) > 0:
                dp = (b[1] * c[2] - b[0] * c[3]) / d
                dq = (b[0] * c[2] - b[1] * c1) / d
                p = p + dp; q = q + dq
            else:
                m = 0
            k = k + 1
        if m != 0:
            r[j:j + 2] = eq2g(1, p, q)
            j = j + 2
            m = m - 2
            for i in range(0, m + 1):
                a[m - i] = b[m + 2 - i]
            p0 = v[m] / v[m - 2]
            q0 = v[m - 1] / v[m - 2]
    if m != 0 and k <= nmi:
        if m == 2:
            r[j:j + 2] = eq2g(1, b[3], b[2])
        else:
            r[j] = -b[2]
        return r
    if k > nmi:
        print 'Ultrapassou NMI'
    if m == 0:
        print 'Não convergiu com valores iniciais P0 e Q0'


def faddeev_leverrier():
    """FADDEEV LEVERRIER"""
    n = input('Entre N: ')
    a = [None] * (n + 1)
    for i in range(1, n + 1):
        a[i] = [None] * (n + 1)
        for j in range(1, n + 1):
            a[i][j] = input('Entre A(%d, %d): ' % (i, j))
    p = policar(a, n)

    # newton-bairstow usa os coeficientes ao contrario
    p.reverse()
    if n == 2:
        r = eq2g(p[0], p[1], [2])
    else:
        r = newton_bairstow(n, p)
    try:
        r.sort()
    except TypeError:
        pass
    print 'Autovalores: ', ' '.join([str(t) for t in r])

    # autovet vai de 1 a N, r começa em 0
    r.insert(0, None)
    x = autovet(n, a, r)
    # transpondo x e normalizando as linhas
    v = [None] * n
    for i in range(n):
        v[i] = [None] * n
        for j in range(n):
            v[i][j] = x[j + 1][i + 1]
        vm = v[i][0]
        for j in range(n):
            if abs(v[i][j]) > abs(vm):
                vm = v[i][j]
        for j in range(n):
            v[i][j] = v[i][j] / vm
    print 'Autovetores:'
    for l in v:
        print '[', ' '.join([str(t) for t in l]), ']'


def pivot(a, b, n, i):
    c = a[i][i]
    l = i
    for k in range(i + 1, n + 1):
        if abs(c) < abs(a[k][i]):
            c = a[k][i]
            l = k
    if l != i:
        for j in range(1, n + 1):
            a[i][j], a[l][j] = a[l][j], a[i][j]
        b[i], b[l] = b[l], b[i]
    return a, b


def lu(a, b, n):
    x = [None] * (n + 1)

    # geração das matrizes [L] e [U]
    for i in range(1, n + 1):
        a, b = pivot(a, b, n, i)
        print a
        for j in range(1, n + 1):
            if j < i:
                l = j - 1
            else:
                l = i - 1
            soma = 0.0 + a[i][j]
            for k in range(1, l + 1):
                soma = soma - a[i][k] * a[k][j]
            if j <= i:
                a[i][j] = soma
            else:
                a[i][j] = soma / a[i][j]
        x[i] = 0.0

    # solução de [L]{X*} = {B}
    for i in range(1, n + 1):
        soma = 0.0 + b[i]
        for k in range(1, i):
            soma = soma - a[i][k] * x[k]
        x[i] = soma / a[i][i]

    # solução de [U]{X} = {X*}
    for i in range(n, 0, -1):
        soma = x[i]
        for j in range(i + 1, n + 1):
            soma = soma - a[i][j] * x[j]
        x[i] = soma

    return x


from math import *
def seqnl_newton():
    """SEQNL-NEWTON"""
    n = input('Entre N: ')
    tol, nmi = input('Entre TOL, NMI: ')
    x = [None] * (n + 1)
    for i in range(1, n + 1):
        x[i] = input('Entre X[%d]: ' % i)
    f = [None] * (n + 1)
    for i in range(1, n + 1):
        f[i] = eval('lambda x:' + raw_input('Entre com F%d(x): ' % i))
    k = 0
    zm = 1.0

    while k <= nmi and abs(zm) > tol:
        fs = [None] * (n + 1)
        a = [None] * (n + 1)
        for i in range(1, n + 1):
            fs[i] = -f[i](x)

            a[i] = [None] * (n + 1)
            for j in range(1, n + 1):
                x[j] = x[j] + tol
                a[i][j] = f[i](x)
                x[j] = x[j] - 2 * tol
                a[i][j] = (a[i][j] - f[i](x)) / (2.0 * tol)
                x[j] = x[j] + tol
        print a, fs
        z = lu(a, fs, n)
        print z
        print
        zm = z[1]
        x[1] = x[1] + z[1]
        for i in range(2, n + 1):
            if abs(zm) <= abs(z[i]):
                zm = z[i]
            x[i] = x[i] + z[i]
        k = k + 1
    if k >= nmi:
        print 'Ultrapassou NMI'
    else:
        print 'Solução:', '[', ' '.join(x), ']'


def regressao_linear(m, n, x, y):
    r = [0.0] * (n + 1)
    r[0] = m; sy2 = 0
    for k in range(1, m + 1):
        x[0][k] = 1
        for j in range(1, n + 1):
            r[j] = r[j] + x[j][k]
        sy2 = sy2 + y[k] * y[k]

    c = [0.0] * (n + 1)
    b = [0.0] * (n + 1)
    a = [None] * (n + 1)
    for i in range(0, n + 1):
        c[i] = 0
        a[i] = [0.0] * (n + 2)
        for j in range(0, i + 1):
            for k in range(1, m + 1):
                a[j][i] = a[j][i] + x[i][k] * x[j][k]
        for k in range(1, m + 1):
            b[i] = b[i] + y[k] * x[i][k]
        a[i][n + 1] = b[i]

    for i in range(0, n + 1):
        for j in range(i, n + 2):
            s = a[i][j]
            for k in range (0, i):
                s = s - a[k][i] * a[k][j]
            if i == j:
                t = 1 / sqrt(s)
                a[i][j] = t
            else:
                a[i][j] = t * s
    for i in range(n, -1, -1):
        s = a[i][n + 1]
        for k in range(i + 1, n + 1):
            s = s - a[i][k] * c[k]
        x[i] = s * a[i][i]

    r2 = 0.0
    for i in range(0, n + 1):
        r2 = r2 + c[i] * (b[i] - r[i] * b[0] / m)
    r2 = r2 / (sy2 - b[0] ** 2 / m)
    print 'C:', ', '.join([str(t) for t in c])
    print 'R2:', r2


FUNCS = [
    integral_tripla_qg,
    pvi_pvc,
    faddeev_leverrier,
    seqnl_newton, # broken
    regressao_linear, # broken
    # adicione mais funcoes aqui
]


if __name__ == '__main__':
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

