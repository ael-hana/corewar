.name "Blitzkrieg"
.comment "Ach Ja!"

init:
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

#alive:
#		live		%1
#		zjmp		%:alive
