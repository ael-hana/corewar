.name "Blitzkrieg"
.comment "Ach Ja!"

init:
		sti			r1, %:alive, %1
		sti			r1, %:copy, %1
		ld			%4294967296, r16
		fork		%:copy

alive:
		live		%1
		zjmp		%:alive

copy:
		live		%1
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		st			r16, 200
		zjmp		%:copy
