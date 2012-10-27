# encoding: utf-8
# Algoritmo SECANTES
require "./base"

Calcnum::algoritmo :secantes do |x0, x1|
  tabela 'k', 'x0', 'x1', 'p', 'x'
  iterar do |k|
    p = f(x1) / f(x0)
    x = x1 - (x0 - x1) * p / (1.0 - p)
    tabela k, x0, x1, p, x
    break x if (x - x1).abs < tol and f(x).abs < tol
    x0, x1 = x1, x
  end
end

