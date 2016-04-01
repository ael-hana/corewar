.comment "I'M ALIIIIVE" ;toto
.name "zork"			#tutu

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
