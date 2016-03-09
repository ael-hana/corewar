.name "Blitzkrieg"
.comment "Ach Ja!"

init:
		sti			r1, %:alive, %1
		sti			r1, %:defense, %1
		sti			r1, %:deflow, %1
		sti			r1, %:defhigh, %1
		sti			r1, %:begin, %1
		ld			%0, r16
		fork		%:defense

alive:
		live		%1
		zjmp		%:alive

defense:
		live		%1
		fork		%:defhigh

deflow:
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
		zjmp		%:deflow

defhigh:
		live		%1
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		st			r16, -300
		zjmp		%:defhigh

begin:
		live		%1

end:
