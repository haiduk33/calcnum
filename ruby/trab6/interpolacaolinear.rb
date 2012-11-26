# encoding: utf-8
# Algoritmo INTERPOLAÇÃO LINEAR

x = [1, 2, 3, 4]
y = [3, 5, 6, 8]

if x.length != y.length
  puts "x e y possuem tamanhos diferentes!"
  exit
else
  n = x.length - 1
  xm = gets.to_f
end

if xm >= x[0] and xm <= x[n]
  i = 0
  while x[i] < xm and i <= n
    i += 1
  end
  den = x[i] - x[i - 1]
  a = (y[i] - y[i - 1]) / den
  b = (x[i] * y[i - 1] - x[i - 1] * y[i]) / den
  ym = a * xm + b
  puts "x=#{xm}, y=#{ym}"
else
  puts "#{xm} está fora dos limites de interpolação."
end

