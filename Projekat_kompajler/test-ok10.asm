
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$12,%15
@main_body:
		MOV 	$0,-12(%14)
		MOV 	$0,-4(%14)
		MOV 	$0,-8(%14)
		SUBS	%15,$4,%15
		MOV $1, -16(%14)
@for_begins0:
		CMPS 	-16(%14),$10
		JGES	@for_end0
		SUBS	%15,$4,%15
		MOV $1, -20(%14)
@for_begins1:
		CMPS 	-20(%14),$8
		JGES	@for_end1
		ADDS	-12(%14),$1,-12(%14)
		ADDU	-20(%14),$1,-20(%14)
		JMP		@for_begins1
@for_end1:
		ADDS	%15,$4,%15
		ADDU	-16(%14),$1,-16(%14)
		JMP		@for_begins0
@for_end0:
		ADDS	%15,$4,%15
		SUBS	%15,$4,%15
		MOV $1, -24(%14)
@for_begins2:
		CMPS 	-24(%14),$3
		JGES	@for_end2
		SUBS	-4(%14),-24(%14),%0
		MOV 	%0,-8(%14)
		ADDU	-24(%14),$1,-24(%14)
		JMP		@for_begins2
@for_end2:
		ADDS	%15,$4,%15
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET