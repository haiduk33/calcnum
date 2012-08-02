# encoding: utf-8
# Algoritmo SECANTES
require "./base"

def secantes x0, x1, &f
  @nmi.times do
    p = f.call(x1) / f.call(x0)
    x = x1 - (x0 - x1) * p / (1.0 - p)
    return x if (x1 - x0).abs < @tol and f.call(x).abs < @tol
    x0, x1 = x1, x
  end
  return :nmi
end

