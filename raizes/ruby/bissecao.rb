# encoding: utf-8
# Algoritmo BISSEÇÃO
require "./base"

def bissecao xi, xf, &f
  return :intervalo if f.call(xi) * f.call(xf) > 0
  algoritmo do
    xm = (xi + xf) / 2
    return xm if (xf - xi).abs < @tol and f.call(xm).abs < @tol
    xi, xf = f.call(xm) * f.call(xi) < 0 ? [xi, xm] : [xm, xf]
  end
end

