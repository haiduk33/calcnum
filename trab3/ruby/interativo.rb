# encoding: utf-8
# Exemplo interativo
require './bissecao'
require './falsaposicao'
require './newtonraphson'
require './iteracaolinear'
require './secantes'

include Calcnum

def entrada tipo
  begin
    input = gets.chomp
    res = case tipo
    when :Equation
      input.to_eq
    when :Floats
      input.tr(',[]()', ' ').split.map{|f| Float(f)}
    else
      method(tipo).call(input)
    end
    return [res, input]
  rescue
    puts 'Não reconhecido, tente denovo.'
    retry
  end
end

def opcao opcoes
  opcoes.each_with_index {|m, i| puts "#{i + 1}. #{m[1]}"}
  begin
    o = gets
    if o == 0
      for op in opcoes
        return op if op[1].upcase.start_with o.upcase
      end
    end
    op = opcoes[o.to_i - 1]
    raise if op.nil?
    return op
  rescue
    puts 'Opção inválida.'
    retry
  end
end

begin
  puts 'Entre com o NMI (Número Máximo de Iterações):'
  @nmi, nmi = entrada :Integer
  puts

  puts 'Entre com a tolerância (exemplo: 0.001 ou 1.0e-3 ou 1e-3):'
  @tol, tol = entrada :Float
  puts

  puts 'Entre com a equação (exemplo: cos(x) = x, ou sen(x) - x = 0):'
  equacao, eq = entrada :Equation
  puts

  puts 'Escolha um método'
  metodo, met = opcao [
    [:bissecao, 'Bisseção'],
    [:falsaposicao, 'Falsa Posição'],
    [:newtonraphson, 'Newton-Raphson'],
    [:iteracaolinear, 'Iteração Linear'],
    [:secantes, 'Secantes']
  ]
  puts

  puts 'Entre com os parametros para o método (exemplo: [0.6, 0.8] ou 1.0):'
  params, par = entrada :Floats
  puts

  puts "Resolvendo a equação '#{eq}' pelo método '#{met}' com parâmetros #{params.inspect} ..."
  aplicar metodo, *params, &equacao
  puts
rescue Interrupt
  puts
ensure
  puts
  puts "Fim do programa."
end

