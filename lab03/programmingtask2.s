.data  
number: .word 3         # stored number in memory

.text 
dataarray:
# dataarray functin begin
    # BEGIN PROLOGUE
    addi sp, sp, -44    # begin by adding space on stack
    sw s0, 0(sp)        # Storing s0 old value
    sw ra, 4(sp)        # Storing ra old value
    # from 4 onward I have assigned the memory in stack in array of size 10
    # END PROLOGUE
    addi s0, x0, 0       # used s0 to hold i variable
    la a0, number       # load address of number in a0
    lw a0, 0(a0)        # load value of number in a0
    li t0, 10            # initializing 10 in t0  
    addi t3, x0, 8      # storing location of array base address from sp
    # checking condition and running loop
condition:    
    blt s0, t0, loop    # checking condition if i<10
    li a0, 10           # for terminating program
    ecall
loop: 
    jal compare         # jump to compare and link the next address in ra
    add sp, sp, t3      # going to array address
    sw a2, 0(sp)       # store array[i] value in stack by using t3 and sp
    sub sp, sp, t3      # restoring old sp pointer
    addi t3, t3, 4      # this is the number that will add 4 in each loop so that we can move to next element of array
    addi s0, s0, 1      # i = i + 1
    j condition
# dataarray functin end

compare:
# compare functin begin
    addi sp, sp ,-12    # making space
    sw a0, 8(sp)        # storing a0 old value
    sw a1, 4(sp)        # storing a1 old value 
    sw ra, 0(sp)        # storing ra previous value before calling sub function
    add a0, a0, x0      # passing number to a0(function argument 1)
    add a1, s0, x0      # passing i value in a1(function argument 2)
    jal subt            # jump to subt function and link
    lw ra, 0(sp)        # storing old ra value
    bge a2, x0,return1  # if (sub(a,b))>=0 return 1

    lw a0, 8(sp)        # storing a0 old value
    lw a1, 4(sp)        # storing a1 old value 
    addi sp, sp ,12     # restpring stack
    addi a2, x0, 0      # else return 0
    jr ra               # jump to function dataarray without linking
return1:
    addi a2, x0, 1      # returning 1
    lw a0, 8(sp)        # storing a0 old value
    lw a1, 4(sp)        # storing a1 old value 
    addi sp, sp ,12     # restpring stack
    jr  ra              # jump to function dataarray without linking
# compare functin end    

subt:
# subt functin begin
    addi sp, sp ,-12     # making space
    sw a2, 8(sp)        # for returning value
    sw a0, 4(sp)        # storing a0 old value
    sw a1, 0(sp)        # storing a1 old value 4
    sub a2, a0, a1      # a - b
    lw a0, 4(sp)        # a0 previous value
    lw a1, 0(sp)        # a1 previous value
    # a3 value will remain in register as it will return value
    addi sp, sp, 12      # restoring stack
    jr ra               # jump to ra without linking
# subt functin end


