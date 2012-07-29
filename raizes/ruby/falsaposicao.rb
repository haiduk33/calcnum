# encoding: utf-8
# Algoritmo BISSEÇÃO
require "./base"

def falsaposicao xi, xf, &f
  unless f.call(xi) * f.call(xf) > 0
    @nmi.times do
      p = f.call(xi) / f.call(xf)
      xm = xi - (xf - xi) * p / (1 - p)
      return xm if ((xf - xm).abs < @tol or (xi - xm).abs < @tol) and f.call(xm).abs < @tol
      xi, xf = f.call(xm) * f.call(xi) < 0 ? [xi, xm] : [xm, xf]
    end
    return :nmi
  else
    return :intervalo
  end
end

