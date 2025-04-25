.model small
.stack 100h
.data
    msg1 db ,"the capital letter is : $"   ; Character to print
    msg2 db ,"enter the letter : $"
.code
main proc
    mov bx,@data
    mov ds,bx
    
    mov dx , offset msg2
    mov ah,09h          
    int 21h
    
    
    mov ah,01h
    int 21h
    sub al,20h
    mov bl,al 
    
    mov ah,02h
    mov dl,10
    int 21h
    
    mov ah,02h
    mov dl,13
    int 21h
    
    mov dx , offset msg1
    mov ah,09h
    int 21h
    
    mov ah, 02h
    mov dl, bl             
    int 21h               
    
main endp
end main