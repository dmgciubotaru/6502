;
; Startup code for cc65 (supervision version)
;

        .export         _exit
        .export         __STARTUP__ : absolute = 1      ; Mark as startup

        .import         _main
        .import         initlib, donelib, copydata
        .import         zerobss
        .import         __RAM_START__, __RAM_SIZE__     ; Linker generated
        .import         __STACKSIZE__                   ; Linker generated

        .include "zeropage.inc"


.code
        .segment "STARTUP"

reset:
        jsr     zerobss

        ; Initialize data.
        jsr     copydata

        lda     #<(__RAM_START__ + __RAM_SIZE__ + __STACKSIZE__)
        ldx     #>(__RAM_START__ + __RAM_SIZE__ + __STACKSIZE__)
        sta     sp
        stx     sp+1            ; Set argument stack ptr
        jsr     initlib
        jsr     _main
_exit:  jsr     donelib
exit:   jmp     exit


.proc   irq
	jmp irq
.endproc

.proc   nmi
	jmp nmi
.endproc

        .segment "VECTORS"

.word   nmi
.word   reset
.word   irq
