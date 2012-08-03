# encoding: utf-8
# Algoritmo NEWTON-RAPHSON
require "./base"

def derivada &f
  return lambda {|x| (f.call(x + @tol) - f.call(x - @tol)) / (2 * @tol)}
end

def newtonraphson x0, &f
  df = derivada(&f)
  algoritmo do
    x = x0 - f.call(x0) / df.call(x0)
    return x if (x - x0).abs < @tol and f.call(x).abs < @tol
    x0 = x
  end
end

