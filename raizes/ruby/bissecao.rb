require "base"
# Algoritmo BISSEÇÃO

def bissecao xi, xf, &f
  unless f.call(xi) * f.call(xf) > 0
    @nmi.times do
      xm = (xi + xf) / 2
      return xm if (xf - xi).abs < @tol and f.call(xm).abs < @tol
      xi, xf = f.call(xm) * f.call(xi) < 0 ? [xi, xm] : [xm, xf]
    end
    return :nmi
  else
    return :intervalo
  end
end

include Math

@tol = 1e-3
@nmi = 100

f = lambda {|x| x - cos(x)}

aplicar :bissecao, 0.6, 0.8, &f

