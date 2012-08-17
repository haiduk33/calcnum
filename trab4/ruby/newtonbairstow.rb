# encoding: utf-8
# Algoritmo NEWTON-BAIRSTOW(N,A)
require "mathn"
require "./base"

Calcnum.algoritmo :eq2g do |p|
  deltaroot = Math.sqrt(p[1] ** 2 - 4 * p[2] * p[0])
  [(-p[1] + deltaroot) / (2 * p[2]), (-p[1] - deltaroot) / (2 * p[2])]
end

Calcnum.algoritmo :newtonbairstow do |a|
  @a = a
  m = n = a.length - 1
  a = a.map {|x| x / @a[-1]}
  def aproxpq
    v = @a.dup.reduce [0, 0, 0] {|m, e| (m << e.abs).sort.reverse[0..-2]}
    [Float(v[0] / v[2]), Float(v[1] / v[2])]
  end
  p, q = aproxpq
  b, c, res = [], [], []
  while m > 2
    b[m + 2] = b[m + 1] = c[m + 2] = c[m + 1] = 0
    tabela 'k', 'p', 'q'
    iterar do |k|
      m.downto 0 do |i|
        b[i] = a[i] - p * b[i + 1] - q * b[i + 2]
        c[i] = b[i + 1] - p * c[i + 1] - q * c[i + 2]
      end
      d = c[1] ** 2 - (c[0] - b[1]) * c[2]
      if d.abs > 0
        dp = Float((b[1] * c[1] - b[0] * c[2]) / d)
        dq = Float((b[0] * c[1] - b[1] * (c[0] - b[1])) / d)
        p += dp
        q += dq
        tabela k, p, q
        break if dp.abs + dq.abs < tol
      else
        break m = 0
      end
    end
    if m != 0
      res += eq2g([q, p, 1])
      m -= 2
      0.upto m do |i|
        a[m - i] = b[m + 2 - i]
      end
      p, q = aproxpq
    end
  end
  if m == 2
    q, p = b[2,3]
    res += eq2g([q, p, 1])
  elsif m != 0
    res << -b[2]
  end
  res
end

