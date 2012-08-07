# encoding: utf-8
# Algoritmo NEWTON-RAPHSON
require "./base"

Calcnum::algoritmo :newtonraphson do |x0|
  def df(x) (f(x + tol) - f(x - tol)) / (2 * tol); end
  iterar do
    x = x0 - f(x0) / df(x0)
    break x if (x - x0).abs < tol and f(x).abs < tol
    x0 = x
  end
end

