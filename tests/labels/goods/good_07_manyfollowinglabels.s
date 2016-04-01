.comment "I'M ALIIIIVE"
.name "zork"

l1:
l2:
l5:
l7:
l8:	sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
