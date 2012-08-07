# encoding: UTF-8
# Exemplo estatico
require './bissecao'
require './falsaposicao'
require './iteracaolinear'
require './newtonraphson'
require './secantes'

include Calcnum

@tol = 1e-15
@nmi = 100

def exemplo titulo, metodo, equacoes
  puts "[#{titulo}]"
  for eq in equacoes
    puts "Equação: #{eq[0]}"
    eq[1].each {|arg| aplicar metodo, *arg, &eq[0].to_eq}
    puts
  end
end

eq1 = "cos(x) = x"
eq2 = "exp(x) = 3 * x"

exemplo "Bisseção", :bissecao, [
  [eq1, [[0.6, 0.8]]]
]
exemplo "Falsa Posição", :falsaposicao, [
  [eq1, [[0.6, 0.8]]]
]
exemplo "Iteração Linear", :iteracaolinear, [
  [eq1, [[0.6]]],
  [eq2, [[0.6]]]
]
exemplo "Newton-Raphson", :newtonraphson, [
  [eq1, [[2.0]]],
  [eq2, [[1.0], [2.0]]]
]
exemplo "Secantes", :secantes, [
  [eq1, [[0.0, 1.0]]]
]

