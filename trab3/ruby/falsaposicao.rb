# encoding: utf-8
# Algoritmo BISSEÇÃO
require "./base"

Calcnum::algoritmo :falsaposicao do |xi, xf|
  break :erro_intervalo if f(xi) * f(xf) > 0
  tabela 'k', 'xi', 'xf', 'xm', 'f(xm)'
  iterar do |k|
    p = f(xi) / f(xf)
    xm = xi - (xf - xi) * p / (1 - p)
    fxm = f(xm)
    tabela k, xi, xf, xm, fxm
    break xm if ((xf - xm).abs < tol or (xi - xm).abs < tol) and fxm.abs < tol
    xi, xf = f(xm) * f(xi) < 0 ? [xi, xm] : [xm, xf]
  end
end

