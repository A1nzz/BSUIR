 org $8000 ; abcd*efgh = ab*ef*10000 + ab*gh*100 + cd*ef*100 + cd*gh

 stx $100 ; Xh(ab) - $100, Xl(cd) - $101
 sty $102 ; Yh(ef) - $102, Yl(gh) - $103
 ldaa $101
 ldab $103
 mul ; cd*gh
 stab $503 ; ячейки $500-$503 - байты ответа
 staa $600 ; cd*gh 2ой байт

 clra
 clrb€
 ldaa $101
 ldab $102
 mul ; cd*ef
 stab $601 ; cd*ef 2ой байт
 staa $700 ; cd*ef 3ий байт

 clra
 clrb
 ldaa $100
 ldab $103
 mul ; ab*gh
 stab $602 ; ab*gh 2ой байт
 staa $701 ; ab*gh 3ий байт

 clra
 clrb
 ldx #$0000
 ldab $600
 abx
 daa
 ldab $601
 abx
 daa
 ldab $602
 abx
 daa
 xgdx
 stab $502
 staa $702 ; то что перешло от 2ого байта в 3ий

 clra
 clrb
 ldaa $100
 ldab $102
 mul ; ab*ef
 stab $703 ; ab*ef 3ий байт
 staa $800 ; ab*ef 4ый байт

 clra
 clrb
 ldx #$0000
 ldab $700
 abx
 daa
 ldab $701
 abx
 daa
 ldab $702
 abx
 daa
 ldab $703
 abx
 daa
 xgdx
 stab $501
 staa $801 ; то что перешло от 3его байта в 4ый

 clra
 clrb
 adda $800
 adda $801
 staa $500

