TITLE Program Template     (template.asm)

; Author: Sami Talibi
; Last Modified: 4/14
; OSU email address: talibis@oregonstate.edu
; Course number/section: 271 - 400
; Project Number:   1              Due Date: 4/14
; Description: Uses a loop to ask whether the user wants to continue or not. then asks for 2 numbers to calculate the sum, product, difference, and quotiont of them. The program has a method to make sure the second number is less than the first. 
; also rounds to the nearest .001 using the FPU stack. 
INCLUDE Irvine32.inc

; (insert constant definitions here)

.data
introduction	BYTE	"Elementary Arithmetic   By: Sami Talibi", 0
plus			BYTE	" + ", 0
minus			BYTE	" - ", 0
multiplication	BYTE	" x ", 0
division		BYTE	" / ", 0
equals			BYTE	" = ", 0
remainder		BYTE	" remainder ", 0
remainderholder	DWORD	?
instructions	BYTE	"Enter 2 numbers, and I'll show you the sum, difference, product, quotient, and remainder. ", 0
extracredit		BYTE	"Press (1) to continue or (2) to exit ", 0
lessextra		BYTE	"The second number must be less than the first! ", 0
divextra		BYTE	"Calculated and displaying the quotient as a floating-point number", 0
entryone		DWORD	? ; holds the first number the user enters
entrytwo		DWORD	? ; holds the second number the user enters
plusresult		DWORD	? 
minusresult		DWORD	?
multiplicationresult	DWORD	?
divisionresult	DWORD	? 
extracinput		DWORD	? ; the following variables are used for the FPU stack and rounding
extradecimal	real10	?
extraround		dword	1000


; (insert variable definitions here)

.code
main PROC
;introduction
	mov	edx, OFFSET	introduction
	call	WriteString
	call	CrLF
plusultra: 
;extra credit
mov	edx, offset	extracredit
call	writestring
call	crlf

call	readint
mov	extracinput, eax
cmp	eax, 2 ;the user will be asked to enter 1 to continue or 2 to quit. use cmp and jmps to route the user to specific labels to achieve this
je	exi
jg	plusultra
cmp	eax, 1
jl	plusultra

; instruction and introduction
	mov	edx, OFFSET	instructions
	call	WriteString
	call	CrLF
; get numbers
	call	ReadInt
	mov	entryone, eax
	call	ReadInt
	mov entrytwo, eax
	;extracredit part 2
	cmp	eax, entryone ; comparison here to make sure second number is less than the first and appropriate jmp.
	jl	UA
	mov	edx, offset	lessextra
	call writestring
	call crlf
jmp plusultra

UA:
;calculations

;division for .001 EC
fild	entryone
fild	entrytwo
fdiv	
fild	extraround
fmul
frndint
fild	extraround
fdiv
fstp	extradecimal


mov	eax, entryone ; regular division
mov	ebx, entrytwo
cdq
div ebx
mov divisionresult, eax
mov	remainderholder, edx

;multiplication
mov	eax, entryone
mov	ebx, entrytwo
mul	ebx
mov	multiplicationresult, eax

;addition
mov	eax, entryone
mov	ebx, entrytwo
add	eax, ebx
mov plusresult, eax

;subtraction
mov eax, entryone
mov ebx, entrytwo
sub eax, ebx
mov minusresult, eax

; report results
;addition
mov	eax, entryone
call	 Writedec
mov	edx, OFFSET plus
call	WriteString
mov eax, entrytwo
call	Writedec
mov edx, OFFSET equals
call	writestring
mov eax, plusresult
call	writedec
call	crlf

;subtraction
mov	eax, entryone
call	 Writedec
mov	edx, OFFSET minus
call	WriteString
mov eax, entrytwo
call	Writedec
mov edx, OFFSET equals
call	writestring
mov eax, minusresult
call	writeint
call	crlf

;multiplication
mov	eax, entryone
call	 Writedec
mov	edx, OFFSET multiplication
call	WriteString
mov eax, entrytwo
call	Writedec
mov edx, OFFSET equals
call	writestring
mov eax, multiplicationresult
call	writedec
call	crlf

;division
mov	eax, entryone
call	 Writedec
mov	edx, OFFSET division
call	WriteString
mov eax, entrytwo
call	Writedec
mov edx, OFFSET equals
call	writestring
mov eax, divisionresult
call	writedec
mov edx, offset remainder
call	writestring
mov eax, remainderholder
call	writedec
call	crlf

mov	edx, OFFSET	divextra
call	writestring
call	crlf
mov	eax, entryone
call	 Writedec
mov	edx, OFFSET division
call	WriteString
mov eax, entrytwo
call	Writedec
mov edx, OFFSET equals
call	writestring
fld		extradecimal
call	writefloat
call crlf

mov	eax, extracinput ; make sure the user wants to continue
cmp	eax, 1
je plusultra
exi:
exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
