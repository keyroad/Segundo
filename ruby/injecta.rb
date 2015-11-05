#!/usr/bin/env ruby
# injecta.rb

class Array
	def inject(acumulador)
		for i in (0...self.size)
			acumulador = yield acumulador, self[i]
		end
		acumulador
	end
end

p [1,4,2,5,3,7,6].inject(0) { |acu, x| acu + x}