# encoding: utf-8
# Algoritmo BISSEÇÃO
require "./base"

def falsaposicao xi, xf, &f
  unless f.call(xi) * f.call(xf) > 0
    algoritmo do
      p = f.call(xi) / f.call(xf)
      xm = xi - (xf - xi) * p / (1 - p)
      return xm if ((xf - xm).abs < @tol or (xi - xm).abs < @tol) and f.call(xm).abs < @tol
      xi, xf = f.call(xm) * f.call(xi) < 0 ? [xi, xm] : [xm, xf]
    end
  else
    return :intervalo
  end
end

