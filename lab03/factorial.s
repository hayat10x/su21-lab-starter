.data
n: .word 8

.text
main:
    la s2, n         # load the address of n in s2
    addi t0, x0, 1   # Initialize loop counter t0 to 1
    addi t1, x0, 1   # Initialize factorial result t1 to 1
    lw t3, 0(s2)     # load the value at address s2 in t3

loop:
    mul t1, t1, t0   # Multiply the factorial result t1 by the loop counter t0
    addi t0, t0, 1   # Increment the loop counter t0
    ble t0, t3, loop  # Check if t0 is less than or equal to n, if true, continue the loop
    add a1, x0, t1
    li a0, 1
    ecall
    addi a1, x0, '\n'
    addi a0,x0,11
    ecall
    li a0, 10
    ecall

    
