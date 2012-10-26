# encoding: utf-8
# Algoritmo AJUSTE-POLINOMIAL
include Math

x = [nil, 10,    20,    30,    40,    50]
y = [nil, 1.293, 1.000, 0.800, 0.654, 0.546]

if x.length != y.length
  puts "x e y possuem tamanhos diferentes!"
  exit
else
  m = x.length - 1
  n = gets.to_i
end

# montagem do sistema

r = []
b = []
r[0] = m
b[0] = 0
sy2 = 0

for k in 1..m
  b[0] += y[k]
  sy2 += y[k] ** 2
end

a = []
c = []
a[0] = []
a[0][n + 1] = b[0]
for i in (1..n).map{|x| 2*x}
  r[i - 1] = r[i] = b[i / 2] = 0
  for k in 1..m
    r[i - 1] += x[k] ** (i - 1)
    r[i] += x[k] ** i
    b[i / 2] += y[k] * x[k] ** (i / 2)
  end
  a[i / 2] = []
  a[i / 2][n + 1] = b[i / 2]
end
for i in 0..n
  for j in i..n
    a[i][j] = r[i + j]
  end
  c[i] = 0
end

# resolução do sistema

for i in 0..n
  for j in i..(n + 1)
    s = a[i][j]
    for k in 0..(i - 1)
      s -= a[k][i] * a[k][j]
    end
    if i == j
      t = 1.0 / sqrt(s)
      a[i][j] = t
    else
      a[i][j] = t * s
    end
  end
end
for i in n.downto 0
  s = a[i][n + 1]
  for k in (i + 1)..n
    s -= a[i][k] * c[k]
  end
  c[i] = s * a[i][i]
end

# cálculo de R2

r2 = 0
for i in 0..n
  r2 += c[i] * (b[i] - r[i] * b[0] / m)
end
r2 /= sy2 - b[0] ** 2 / m

# resultado

def p x
  #"%.6f" % x
  x.to_s
end

puts c.map{|z| p z}.join " "
puts p r2

