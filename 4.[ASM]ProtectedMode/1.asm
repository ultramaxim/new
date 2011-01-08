	org 7c00h
_1:
	xor ax,ax
	mov ss,ax
	mov sp,ax
	mov es,ax
	mov	ds,sp
	
	mov ah,2h
	mov	al,4h
	mov ch,0h
	mov cl,2h
	mov dh,0h
	mov bx,_2
	int 13h

	cmp ah,00h
	jne read_err

	jmp	read_ok
read_err:
	mov	al,1h
	mov	bl,1h
	mov	bh,0h
	mov	cx,_2-error
	mov	bp,error
	mov	ah,13h
	int	10h
read_ok:
	cli
	hlt

error db "Error while reading!"
_2:
db 510-(_2-_1) dup(0)
db 55h,0aah
