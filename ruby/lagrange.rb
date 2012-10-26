# encoding: utf-8
# Algoritmo LAGRANGE

# Espera receber uma lista de pares [x, y]
# assume que y = f(x), isto é, x não se repete
# Retorna um lambda capaz de calcular xm
# Por exemplo:
#     > f = lagrange [[1, 2], [2, 4], [3, 2]]
#     > f.call(1.5)
#     3.5
#     > f.call(2.25)
#     3.875
def lagrange pontos
  pontos = pontos.sort
  lambda do |x|
    pontos.reduce(0) do |y, (xk, yk)|
      y + yk * pontos.reduce(1) do |p, (xi, _)|
        xi != xk ? p * (x - xi) / (xk - xi) : p
      end
    end
  end
end

