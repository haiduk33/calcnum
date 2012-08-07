def format_num num
  "% 12.8f" % num rescue "%s" % num
end

def get_max_width column
  column.collect{|ele| format_num(ele).length}.max
end

def print_table table
  pads = []
  (0..table[0].length).each do |i|
    pads << get_max_width(table.collect{|row| row[i]})
  end
  table.each do |row|
    row.zip(pads).each do |line, pad|
      print format_num(line).ljust(pad + 1)
    end
    puts
  end
end
