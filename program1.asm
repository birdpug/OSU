TITLE Program Template     (template.asm)

; Author:
; Last Modified:
; OSU email address: 
; Course number/section:
; Project Number:                 Due Date:
; Description:

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
entryone		DWORD	?
entrytwo		DWORD	?
plusresult		DWORD	?
minusresult		DWORD	?
multiplicationresult	DWORD	?
divisionresult	DWORD	?
extracinput		DWORD	?
extradecimal	dword	?
extraround		dword	1000


; (insert variable definitions here)

.code
main PROC
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
cmp	eax, 2
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
	cmp	eax, entryone
	jl	UA
	mov	edx, offset	lessextra
	call writestring
	call crlf
jmp plusultra

UA:
;calculations

;division
fild	entryone
fild	entrytwo
fdiv	
fild	extraround
fmul
frndint
fild	extraround
fdiv
fstp	extradecimal


mov	eax, entryone
cdq
mov	ebx, entrytwo
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

mov	eax, extracinput
cmp	eax, 1
je plusultra
exi:
exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
