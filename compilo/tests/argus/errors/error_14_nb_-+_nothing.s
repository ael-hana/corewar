.comment "I'M ALIIIIVE"
.name "zork"

l2:		sti r1, %:live, %-
		and r1, %0, r1

live:	live %1
		zjmp %:live
