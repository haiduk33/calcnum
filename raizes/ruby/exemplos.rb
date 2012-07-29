# encoding: UTF-8
# Exemplo estatico
require './bissecao'
require './falsaposicao'
require './iteracaolinear'
require './newtonraphson'

@tol = 1e-3
@nmi = 100

def exemplo titulo, metodo, equacoes
  puts "[#{titulo}]", ""
  for eq in equacoes
    puts "Equação: #{eq[0]}"
    eq[1].each {|arg| aplicar metodo, *arg, &eq[0].to_eq}
    puts
  end
end

exemplo "Bisseção", :bissecao, [
  ["x - cos(x) = 0", [[0.6, 0.8]]]
]
exemplo "Falsa Posição", :falsaposicao, [
  ["x - cos(x) = 0", [[0.6, 0.8]]]
]
exemplo "Iteração Linear", :iteracaolinear, [
  ["exp(x) / 3 = 0", [[0.6]]]
]
exemplo "Newton-Raphson", :newtonraphson, [
  ["exp(x) - 3 * x = 0", [[1.0], [2.0]]],
  ["x - cos(x) = 0", [[2.0]]]
]

