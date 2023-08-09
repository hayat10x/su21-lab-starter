.globl main

.text 

main: 
    la a0, num
    lw a0, 0(a0)
    jal factorial
    la s0, result
    sw a0, 0(s0)
    j write_tohost
    
factorial: 
    addi sp, sp, -8
    sw a0, 4(sp)
    sw ra, 0(sp)
    addi t0, x0, 1 
    bgt a0, t0, else 
    addi a0, x0, 1 
    addi sp, sp, 8 
    jr ra 
else: 
    addi a0, a0, -1 
    jal factorial 
    lw ra, 0(sp) 
    lw t1, 4(sp) 
    addi sp, sp, 8 
    mul a0, t1, a0 
    jr ra 


.data    
num: .word 5
result: .word 0

write_tohost:
li x1, 1
sw x1, tohost, t5

.align 12
.section ".tohost","aw",@progbits;                            
.align 4; .global tohost; tohost: .dword 0;                     
.align 4; .global fromhost; fromhost: .dword 0;

