# encoding: utf-8
# Algoritmo INTERPOLBI
require './lagrange'

# Espera receber uma lista de pares de
# listas de pares em que
# Retorna um lambda que calcula o valor interpolado
# Exemplo:
#     > f = interpolbi [
#     >  [1, [[1, 2], [2, 3], [3, 4]]],
#     >  [3, [[1, 6], [2, 9], [3, 12]]],
#     >  [2, [[1, 4], [2, 6], [3, 8]]],
#     >  [4, [[1, 8], [2, 12], [3, 16]]]
#     > ]
#
def interpolbi pontos
  pontos = pontos.sort
  lambda do |*x|
    lagrange pontos.map {|x1, pts|
      [x1, lagrange(pts).call(x[1])]
    }.call(x[0])
  end
end

