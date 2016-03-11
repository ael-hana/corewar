.name "Blitzkrieg"
.comment "Ach Ja!"

init:
		sti			r1, %:alive, %1
		sti			r1, %:wall, %1
		sti			r1, %:clear, %1
#		sti			r1, %:rush, %1
#		sti			r1, %:circ, %1
		ld			%42424242, r4
		ld			%-200, r2
		fork		%:wall
		ld			%0, r16
#		zjmp		%:alive

rush:		#1365 pour 3, 2048 pour 2 et 1024 pour 4
		st			r4, 240
		st			r4, 512
		st			r4, 740
		st			r4, 1000
		st			r4, 1500
		zjmp		%:alive

prewall:
		fork		%:wall
		ld			%-232, r2

wall:
		live		%1
		ld			%4, r3
		sti			r4, r2, %0
		sub			r2, r3, r2
		ld			%0, r16
		xor			r2, %-328, r5
		zjmp		%:prewall
		ld			%0, r16
		zjmp		%:wall

		aff			r2
		fork		%:test
		ld			%42, r2
		aff			r2
		ld			%0, r16
		zjmp		%:clear

test:
		ld			%45678, r3
		ld			%2345678, r4
		aff			r2

#init:
#		sti			r1, %:alive, %1
		sti			r1, %:clear, %1
		ld			%55575043, r2
		ld			%42, r3
		ld			%-210, r14
		ld			%1879703763, r12
#		aff			r3
#		ld			%33, r6
#		add			r2, r3, r2
#		xor			r3, r15, r4
#		zjmp		%:init
#		ld			%4, r3i
#		fork		%:clear

clear:
		live		%1
		ld			%190057486, r10
		ld			%269090600, r11
		st			r10, 211
		st			r11, 210

#		ld			%8, r13
#		sub			r12, r13, r12
		ld			%0, r16

#move:
#		sti			r12, r14, r16		#clear ? XX ?
#		zjmp		%-202				#clear ?

alive:
		live		%1
		zjmp		%:alive
