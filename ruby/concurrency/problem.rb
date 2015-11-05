#!/usr/bin/env ruby 
# problem.rb

class Semaforo

	def initialize(semaforo, valor)
		@semaforo = semaforo
		@valor = valor.to_i
	end

end

seller = Semaforo.new('sells', 3)

p seller.methods.sort


