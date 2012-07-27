# Base para aplicar metodos

def aplicar metodo, *args, &fun
  case r = method(metodo).call(*args, &fun)
  when :intervalo
    puts "Não há garantia de existencia de raiz neste intervalo"
  when :nmi
    puts "Ultrapassou o NMI."
  when Symbol
    puts "Erro desconhecido."
  else
    puts "Raiz: #{r}"
  end
end

