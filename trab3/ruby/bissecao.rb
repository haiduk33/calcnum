# encoding: utf-8
# Algoritmo BISSEÇÃO
require "./base"

Calcnum::algoritmo :bissecao do |xi, xf|
  break :erro_intervalo if f(xi) * f(xf) > 0
  iterar do
    xm = (xi + xf) / 2
    break xm if (xf - xi).abs < tol and f(xm).abs < tol
    xi, xf = f(xm) * f(xi) < 0 ? [xi, xm] : [xm, xf]
  end
end

