
y:
		WORD	1
f:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$4,%15
@f_body:
		MOV 	8(%14),%0
		ADDS	8(%14), $1, 8(%14)
		ADDS	%0,$13,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%0
		ADDS	-4(%14), $1, -4(%14)
		ADDS	%0,$7,%0
		MOV 	%0,8(%14)
		ADDS	8(%14),-4(%14),%0
		MOV 	%0,%13
		JMP 	@f_exit
@f_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
		SUBS	%15,$8,%15
@main_body:
			PUSH	%0
			PUSH	$0
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-4(%14)
		MOV 	-4(%14),%0
		ADDS	-4(%14), $1, -4(%14)
		ADDS	%0,$3,%0
			PUSH	%0
			PUSH	%0
			CALL	f
			ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,y
		MOV 	-4(%14),%0
		ADDS	-4(%14), $1, -4(%14)
		MOV 	y,%1
		ADDS	y, $1, y
		ADDS	%0,%1,%0
		ADDS	%0,$42,%0
		MOV 	%0,-8(%14)
		ADDS	-4(%14),y,%0
		ADDS	%0,-8(%14),%0
		MOV 	%0,%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET