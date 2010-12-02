org 7c00h
_1:
xor ax,ax
mov ss,ax
mov sp,ax
mov es,ax

mov ah,2h
mov al,1h
mov ch,0h
mov cl,2h
mov dh,0h
mov bx,_2
int 13h

mov ah,13h
mov al,1h
mov bl,1h
mov bh,0h
mov cx,_4-mes
mov bp,_2
int 10h
cli
hlt
_2:
db 510-(_2-_1) dup(0)
db 55h,0aah
mes db "IT WORKS!!!",0h
_4:
db 512-(_4-mes) dup(0)
	