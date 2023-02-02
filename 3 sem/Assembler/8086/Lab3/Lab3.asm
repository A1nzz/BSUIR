.model	small
.stack	100h
.data            
MaxArrayLength              equ 30            
            
ArrayLength                 dw  ?
InputArrayLengthMsgStr      db 0Ah,0Dh,'Input array length: $'                                
ErrorInputMsgStr            db 0Ah,0Dh,'Incorrect value! TRY AGAIN',0Ah,0Dh, '$' 
ErrorInputArrayLengthMsgStr db 0Ah,0Dh,'Array length should be not less than 0 and not bigger than 30!', '$'
LowRangeMsg                 db 0Ah,0Dh,'Input lower range value: $'
UpRangeMsg                  db 0Ah,0Dh,'Input upper range value: $'
ResultMsg                   db 0Ah,0Dh,'Result: $'                                
InputMsgStr                 db 0Ah, 0Dh,'Input element (-32 768..32 767) : $'
    
                                
NumBuffer                   dw 0

NumLength                   db 7
EnterredNum                 db 9 dup('$')              


LINE                        db 3 dup(?),10,13,'$'

counter                     dw 0
low                         dw ?
high                        dw ?             
minus                       db  0  
Array                       dw  MaxArrayLength dup (0) 
                                
                              
.code      

start:                            
mov	ax,@data                      
mov	ds,ax                                                           
xor	ax,ax                         

call inputRange                               
call inputArrayLength              
call inputArray
lea dx, ResultMsg
call print
mov ax, counter
call PRINTNUMBER
mov ax,4C00h
int 21h     

inputRange proc near
    mov cx, 1           
    inputLowLoop:
       lea dx, LowRangeMsg
       call print
       push cx                    
       call inputElementBuff
       pop cx
       mov low, ax           
    loop inputArrayLengthLoop
    mov cx, 1
    inputUpLoop:
       lea dx, UpRangeMsg
       call print
       push cx                    
       call inputElementBuff
       pop cx
       mov high, ax
       mov ax, low
       cmp high,ax
       jle UpError                        
    loop inputUpLoop  
    ret      
endp

UpError:
call ErrorInput
jmp  inputUpLoop
    
inputArrayLength proc near
    mov cx, 1           
    inputArrayLengthLoop:
       lea dx, InputArrayLengthMsgStr
       call print
       push cx                    
       call inputElementBuff
       pop cx
       mov ArrayLength,ax
       cmp ArrayLength,0
       jle lengthError
       cmp ArrayLength,30
       jg  lengthError
                            
    loop inputArrayLengthLoop     
    ret      
endp

lengthError:
    call ErrorInput
    jmp  inputArrayLengthLoop
    
inputArray proc
    xor di,di                     
                                               
    mov cx,ArrayLength            
    inputArrayLoop:
       lea dx, InputMsgStr
       call print
       push cx                    
       call inputElementBuff
       pop cx      
       
       mov Array[di], ax
       mov ax, high
       sub ax, Array[di]
       js ContinueLoop 
       mov ax, Array[di]
       sub ax, low
       
       lea di,di+2
       jns updateCounter 
       continueLoop:
                            
    loop inputArrayLoop           
    ret      
endp  

updateCounter:
    add counter, 1 
    jmp continueLoop

resetNumBuffer proc
    mov NumBuffer, 0    
    ret
endp    

; integer input
inputElementBuff proc                                         
    xor ax,ax
    xor cx,cx    
    mov al,NumLength    
    mov [EnterredNum],al
    mov [EnterredNum+1],0
    lea dx,EnterredNum
    call input    
    mov cl,[EnterredNum+1]
    lea si,EnterredNum
    add si,2    
    xor ax,ax 
    xor bx,bx
    xor dx,dx
    mov dx,10        
    NextSym:
         xor ax,ax
         lodsb
         cmp bl,0
         je checkMinus    
    checkSym:         
         cmp al,'0'
         jl badNum
         cmp al,'9'
         jg badNum
         
         sub ax,'0'
         mov bx,ax
         xor ax,ax
         mov ax,NumBuffer
         
         imul dx
         jo badNum
         cmp minus,1
         je doSub
         add ax, bx
         comeBack:
         jo badNum
         mov NumBuffer,ax
         mov bx,1
         mov dx,10         
    loop NextSym 

    mov ax,NumBuffer
    mov minus,0    
    
    finish:     
    call resetNumBuffer                        
    ret 
doSub:
    sub ax,bx
    jmp comeBack       
checkMinus:
    inc bl
    cmp al, '-'    
    je SetMinus    
    jmp checkSym                  
SetMinus:
    mov minus,1
    dec cx
    cmp cx,0
    je badNum
    jmp NextSym    
badNum:
    clc
    mov minus,0
    call ErrorInput
    call resetNumBuffer
    jmp inputElementBuff                            
endp

; IO    
PRINTNUMBER PROC
    mov dl,10
    push ax

    ; Fill the line with space
    mov cx,3
    lea bx,LINE
    FILL:
        mov byte ptr [bx],' '
        inc bx
        loop FILL

    ; Check is negative
    cmp ax,0
    jge NEXT
    neg ax

    ; Convert Number to ASCII
    NEXT:
        cbw
        div dl
        dec bx
        add ah,'0'
        mov [bx],ah
        cmp al,0
        jne NEXT

    ; Check Is Negative
    pop ax
    cmp ax,0
    jge DISPLAY

    dec bx
    mov byte ptr [bx],'-'

    ; Print the number
    DISPLAY:
        mov ah,9
        lea dx,LINE
        int 21h

    ret
PRINTNUMBER ENDP
     
input proc near
    mov ah,0Ah
    int 21h
    ret
input endp

print proc
    mov ah, 9 
    int 21h
    ret
    endp print

ErrorInput proc                   
    lea dx, ErrorInputMsgStr      
    call print                    
    ret                           
endp
    
