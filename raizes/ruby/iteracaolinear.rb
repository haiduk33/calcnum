# encoding: utf-8
# Algoritmo ITERAÇÃO LINEAR
require "./base"

def iteracaolinear x0, &g
  x1 = g.call(x0)
  @nmi.times do
    x2 = g.call(x1)
    return x1 if (x2 - x1).abs < @tol and (x1 - x0).abs < @tol
    x0, x1 = x1, x2
  end
  return :nmi
end

