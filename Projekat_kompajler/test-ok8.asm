
funkcija:
		PUSH	%14
		MOV 	%15,%14
@funkcija_body:
		ADDS	8(%14),16(%14),%0
		MOV 	%0,8(%14)
		ADDU	12(%14),12(%14),%0
		ADDU	%0,20(%14),%0
		MOV 	%0,12(%14)
		MOV 	8(%14),%13
		JMP 	@funkcija_exit
@funkcija_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$24,%15
@main_body:
		MOV 	$1,-4(%14)
		MOV 	$4,-8(%14)
		MOV 	$9,-20(%14)
		MOV 	$3,-24(%14)
			PUSH	%0
			PUSH	-24(%14)
			PUSH	-8(%14)
			PUSH	-20(%14)
			PUSH	-4(%14)
			CALL	funkcija
			ADDS	%15,$16,%15
		MOV 	%13,%0
		MOV 	%0,-12(%14)
			PUSH	%0
			PUSH	$9
			PUSH	$5
			PUSH	$3
			PUSH	$1
			CALL	funkcija
			ADDS	%15,$16,%15
		MOV 	%13,%0
		MOV 	%0,-16(%14)
		MOV 	-12(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET