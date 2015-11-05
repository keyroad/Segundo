#!/usr/bin/env ruby
# block.rb
# Demostrates de use of blocks

primos	  = []
perfectos = []

(1..100).to_a

def saluda(name)
	name.each {|e| yield e}
end

saluda( %w[manolo juan pepe nicasio alberto]) { |nombre| puts "hola, #{nombre}."}