# coding: utf-8

T = None,
    [0],
    [0.57735027, -0.57735027],
    [0.77459667, -0.77459667, 0],
    [0.86113631, -0.86113631, 0.33998104, -0.33998104],
    [0.90617985, -0.90617985, 0.53846931, -0.53846931, 0]
    #TODO: continuar, tabela na pag 313

W = None,
    [2.0],
    [1.0, 1.0],
    [0.55555556, 0.55555556, 0.88888889],
    [0.34785483, 0.34785483, 0.65214516, 0.65214516],
    [0.23692688, 0.23692688, 0.47862868, 0.47862868, 0.56888889]
    #TODO: continuar, tabela na pag 313



def volume
    print "Entre A, B: "
    a, b = eval "[#{gets.chomp}]"
    print 'Entre C, D: '
    c, d = eval "[#{gets.chomp}]"
    print 'Entre N: '
    n = eval gets.chomp

    f0 = 0
    for i in 0..(n - 1)
        ti = T[n][i]
        x = ((b - a) * ti + a + b) / 2

        f1 = 0
        for j in 0..(n - 1)
            tj = T[n][j]
            y = ((d - c) * tj + c + d) / 2
            print "Entre Z(#{i},#{j}): "
            z = eval gets.chomp
            p1 = (d - c) * z / 2
            f1 = f1 + p1 * W[n][j]
        end

        p = (b - a) * f1 / 2
        f0 = f0 + p * W[n][i]

    puts "f0 = #{f0}"
end


#TODO: validar/corrigir
def pvi_pvc_ajuste
    def f(x, y, z) (3 * y * y + 10 * z * z * z) / (10 * x * y) end
    print "Entre X0, Y0, Y'0, XN, N: "
    x0, y0, z0, xn, n = eval "[#{gets.chomp}]"
    h = 1.0 * (xn - x0) / n
    x, y, z = x0, y0, z0

    for i in 0..(n - 1)
        k1 = h * z
        l1 = h * f(x, y, z)
        k2 = h * (z + l1)
        l2 = h * f(x + h, y + k1, z + l1)
        z = z + (l1 + l2) / 2
        y = y + (k1 + k2) / 2
        x = x + h
    end

    yn, zn = y, z
    print "Entre N, TOL, NMI: "
    n, tol, nmi = eval "[#{gets.chomp}]"
    def fy(x, y, z) 0.3 / x - z * z / (y * y) end
    def fz(x, y, z) 2 * z / y end

    # não precisa calcular h denovo
    v = [0]
    y = [0]

    for i in 1..(n - 1)
        y[i] = y0 * i * h * (yn - y0) / (xn - x0)
    end
    kc, vc = 1, 1
    k, t = [0], [0]

    while kc <= nmi and vc.abs > tol
        for i in 1..(n - 1)
            x = x0 + i * h
            z = (y[i + 1] - y[i - 1]) / (2 * h)
            a = -1 - h * fz(x, y[i], z) / 2
            b = 2 + h * h * fy(x, y[i], z)
            c = -1 + h * fz(x, y[i], z) / 2
            d = y[i - 1] - 2 * y[i] + y[i + 1] - h * h * f(x, y[i], z)
            den = b - a * t[i - 1]
            k[i] = (d - a * t[i - 1]) / den
            t[i] = c / den
        end
        v[n - 1] = k[n - 1]; vc = v[n - 1]
        y[n - 1] = y[n - 1] + v[n - 1]

        for i in (n - 2).downto 1
            v[i] = k[i] - t[i] * v[i + 1]
            y[i] = y[i] + v[i]
            vc = v[i] if vc.abs < v[i].abs
        end
        kc = kc + 1
    end

    for i in 0..n
        puts y[i]
    end

    include Math
    def f(x) a * x ** (b * x) end
    def f1(y) log(y) end
    def f2(x) x * log(x) end
    def f3(a) exp(a) end
    def f4(b) b end

    sx = sy = sx2 = sxy = ym = 0; m = n + 1

    for i in 0..n
        sy = sy + f1(y[i])
        sx = sx + f2(x)
        sxy = sxy + f1(y[i]) * f2(x)
        sx2 = sx2 + f2(x) ** 2
        ym = ym + y[i] / m
    end

    b = (sxy - sx * sy / m) / (sx2 - sx * sx / m)
    a = (sy - b * sx) / m
    sn = sd = 0.0
    a = f3(a)
    b = f4(b)

    for i in 1..m
        sn = sn + (y[i] - f(x)) ** 2
        sd = sd + (y[i] - ym) ** 2
    end
    r2 = 1 - sn / sd

    puts "a=#{a}, b=#{b}, r=#{r}"
    for i in 0..n
        puts "y[#{i}] = #{y[i]}"
    end
end


def aquifero
    print "Entre N: "
    n = eval gets.chomp
    print "Entre T, S, H, TI, TEMPO: "
    t, s, h, ti, tempo = eval "[#{gets.chomp}]"
    print "Entre R(x, y, t): "
    @r = gets.chomp
    include Math
    def r(x, y, t) eval @r end

    p = s * h ** 2 / (4 * t)

    # criar listas que vão ser usadas
    x = []
    y = []
    c = []
    v = []
    u = []

    for i in 1..n
        print "Entre X(#{i}), Y(#{i}): "
        x[i], y[i] = eval "[#{gets.chomp}]"
        c[i] = 0
        v[i] = []
        for j in 1..4
            print "Entre V(#{i},#{j}): "
            v[i][j] = eval gets.chomp
            if v[i][j] == 0
                print "Entre CI"
                ci = eval gets.chomp
                c[i] = c[i] + ci
            end
        end
        u[i] = 0
    end

    k = u[0] = 0; te = ti
    d = 1

    while d == 1 and k <= (tempo / p).floor
        d = 0
        w = []
        for i in 1..n
            w[i] = c[i] + r(x[i], y[i], te) * h ** 2 / t
            for j in 1..4
                w[i] = w[i] + u[v[i][j]]
            end
            w[i] = w[i] / 4
            d = 1 if (w[i] - u[i]).abs > tol
        end
        k = k + 1; te = te + p
        puts "te = #{te}"
        for i in 1..n
            u[i] = w[i]
            puts "u[#{i}] = #{u[i]}"
        end
    end
end
