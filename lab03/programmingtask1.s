.data
    
i: .word 0

a: .word 7

b:
    .word 0
    .word 0
    .word 0


.text 
    # BEGIN PROLOGUE
    addi sp, sp, -12    # begin by adding space on stack
    sw s0, 0(sp)        # Storing s0 old value
    sw s1, 4(sp)        # Storing s1 old value
    sw s2, 8(sp)        # Storing s2 old value
    # END PROLOGUE
    la s0, i            # storing i address in so
    lw s0, 0(s0)        # Storing i value in so
    
    la s1, a            # storing a address in s1
    lw s1, 0(s1)        # Storing a value in s1
    
    la s2, b            # storing b address in s2
    
    addi t0, x0, 3      # storing 3 in t0
    addi t3, t3, 0      # initialization 0 for iteration of array

loop: 
    slli t1, s0, 2      # multiply by 4 so that we can traverse in array
    mul t2, s0, s1      # i*a
    add t2, t2, s1      # a + (i * a)
    
    add t3, s2, t1      # this will iterate the address of array b
    sw t2, 0(t3)        # entering value of a + (i * a) in b[i]
    addi s0, s0, 1      # k=k+1
    jal x0, cond        # jump back to loop
    
cond:    
    blt s0, t0, loop    # checking if i is less than 3
    li a0, 10            # terminating 
    ecall                # terminating

   
