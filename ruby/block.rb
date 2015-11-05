#!/usr/bin/env ruby
# block.rb
# Demostrates de use of blocks

require 'prime'

primo	  = []
perfecto = []

(1..100).each { |x| primo.push x if Prime.prime? x}

(1..100).each do |x| 
	divisores = []
	(x/2).downto(1) { |n| divisores.push n if x % n == 0}

	perfecto.push x if divisores.inject(0) { |mem, var| mem + var} == x
end

p primo
p perfecto