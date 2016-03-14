.comment "I'M ALIIIIVE"
.name "zork"

l2:		l3:
		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
