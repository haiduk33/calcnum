# encoding: utf-8
# Exemplo interativo
require './bissecao'
require './falsaposicao'
require './newtonraphson'
require './iteracaolinear'
require './secantes'

include Calcnum

def entrada msg, tipo
  begin
    print "#{msg}: "
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

def opcao msg, opcoes
  opcoes.each_with_index {|m, i| puts "#{i + 1}. #{m[1]}"}
  begin
    print "#{msg}: "
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
  @tabelar = true
  @nmi, nmi = entrada 'Entre com o NMI (Número Máximo de Iterações)', :Integer
  @tol, tol = entrada 'Entre com a tolerância (exemplo: 0.001 ou 1.0e-3 ou 1e-3)', :Float
  equacao, eq = entrada 'Entre com a equação (exemplo: cos(x) = x, ou sen(x) - x = 0)', :Equation
  metodo, met = opcao 'Escolha um método', [
    [:bissecao, 'Bisseção'],
    [:falsaposicao, 'Falsa Posição'],
    [:newtonraphson, 'Newton-Raphson'],
    [:iteracaolinear, 'Iteração Linear'],
    [:secantes, 'Secantes']
  ]
  params, par = entrada 'Entre com os parametros para o método (exemplo: [0.6, 0.8] ou 1.0)', :Floats
  puts
  puts "Resolvendo a equação '#{eq}' pelo método '#{met}' com parâmetros #{params.inspect} ..."
  aplicar metodo, *params, &equacao
  puts
rescue Interrupt
  puts
  puts
ensure
  puts "Fim do programa."
end

