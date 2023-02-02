.model small
.stack 100h
.data

    string_request db "Please, enter string:", 0Dh, 0Ah, '$'
    string_word_request db 0dh,0ah,"Please, enter the word from string:", 0Dh, 0Ah, '$' 
    string_word_request_2 db 0dh,0ah,"Please, enter the word to insert:", 0Dh, 0Ah, '$'
    warning_string db 0dh,0ah,"Invalid Input! Try again:", 0Dh, 0Ah, '$'
    string db 200,200 dup('$')      
    string_word db 200,200 dup('$') 
    string_word_insert db 200,200 dup('$') 
    result db 200, 202 dup('$')
    to_new_string db 0dh, 0ah, '$'     

.code        
start:  

print_str macro out_str
    mov ah, 9
    mov dx, offset out_str
    int 21h
endm 
    read_str macro in_str
    mov ah, 0Ah
    mov dx, offset in_str
    int 21h
endm

    mov ax, @data
    mov ds, ax
    print_str string_request
    jmp l
empty_str:
    print_str warning_string     
l:
    read_str string  
    cmp string[1], 0
    je empty_str
        
    print_str string_word_request    
    jmp q

string_word_warning: 
    print_str warning_string    
q:     
    read_str string_word  

    mov di, 2              ; string
    mov si, 2              ; string_word   
    xor cx,cx  


start_check:   
 
    cmp string[di],' '
    jne x
    inc di
    jmp start_check
        
x:   
    mov bl, string[di]         
    cmp string_word[si], bl
    jnz bad_symbol
     
good_symbol:
    
    inc di
    inc si     
    cmp string_word[si],' '
    je final_check
    cmp string_word[si],0dh
    je final_check
    
    jmp x

bad_symbol:
    cmp string_word[si], 0dh
    je string_word_warning
    mov si, 2
a:
    inc di
    cmp string[di],' '
    je start_check
    cmp string[di], 0dh
    je string_word_warning
    jmp a
    
final_check:
         
    cmp string[di],' '
    je delete_w1_inc
    cmp string[di], 0dh   
    je delete_w1_inc
    jmp string_word_warning
      
    
delete_w1_inc:
    dec di     
      
delete_w1: 
    mov string[di], ' '  
    dec di
    dec si  
    inc cx
    cmp si, 2         
    jne delete_w1  
    
 
mov si,2
inserting_first_part:
    mov bh, string[si]
    mov result[si], bh  
    inc si
    cmp string[si], ' '
    jne inserting_first_part 
mov cx, si    
print_str string_word_request_2
read_str string_word_insert
mov di, 2    
mov  result[si], ' '
inc si
inserting_word:
    mov bh, string_word_insert[di]    
    mov result[si], bh
    inc si
    inc di
    cmp string_word_insert[di], '$'
    jne inserting_word 
       
mov di, cx 
dec si
mov result[si], ' ' 
inc si
move_idx_to_last_part:
    inc di
    cmp string[di], ' '    
    je move_idx_to_last_part     
insert_last_part:
    mov bh, string[di]
    mov result[si], bh
    inc di
    inc si
    cmp string[di], '$'
    jne insert_last_part
    
print_str to_new_string   
print_str result+2    
     
mov ax,4c00h   
int 21h   
end start