# encoding: utf-8
# Algoritmo ITERAÇÃO LINEAR
require "./base"

Calcnum::algoritmo :iteracaolinear do |x0|
  def g(x) f(x) + x; end
  x1 = g(x0)
  tabela 'k', 'x0', 'x1', 'g(x1)'
  iterar do |k|
    x2 = g(x1)
    tabela k, x0, x1, x2
    break x1 if (x2 - x1).abs < tol and (x1 - x0).abs < tol
    x0, x1 = x1, x2
  end
end

