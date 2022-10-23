 org $8000
 ldab #128
 ldx #$8000
 ldy #$8200
fill:
 ldaa $0,x
 staa $0,y
 inx
 iny
 decb
 bne fill

 ldaa #%00100000
 staa $8200
 ldx #$8200
 ldab #$ff
loop:
 ldaa #%00100000
 anda $0,x
 bne set1
con1:
 ldaa #%00000100
 anda $0,x
 bne set2
con2:
 inx
 decb
 bne loop
 jmp end
 
set1:
 bset $0,x,#%00010000
 jmp con1
set2:
 bset $0,x,#%00010000
 jmp con2
end: