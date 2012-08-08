# encoding: utf-8
# Algoritmo BISSEÇÃO
require "./base"

Calcnum::algoritmo :bissecao do |xi, xf|
  break :erro_intervalo if f(xi) * f(xf) > 0
  tabela 'k', 'xi', 'xf', 'xm', 'f(xm)'
  iterar do |k|
    xm = (xi + xf) / 2
    fxm = f(xm)
    tabela k, xi, xf, xm, fxm
    break xm if (xf - xi).abs < tol and fxm.abs < tol
    xi, xf = f(xm) * f(xi) < 0 ? [xi, xm] : [xm, xf]
  end
end

