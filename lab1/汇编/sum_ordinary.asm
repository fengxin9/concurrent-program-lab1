sum_ord(int*, long long&, int):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi
        mov     QWORD PTR [rbp-32], rsi
        mov     DWORD PTR [rbp-36], edx
        mov     rax, QWORD PTR [rbp-32]
        mov     QWORD PTR [rax], 0
        mov     DWORD PTR [rbp-4], 0
        jmp     .L2
.L3:
        mov     rax, QWORD PTR [rbp-32]
        mov     rdx, QWORD PTR [rax]
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        lea     rcx, [0+rax*4]
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rcx
        mov     eax, DWORD PTR [rax]
        cdqe
        add     rdx, rax
        mov     rax, QWORD PTR [rbp-32]
        mov     QWORD PTR [rax], rdx
        add     DWORD PTR [rbp-4], 1
.L2:
        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-36]
        jl      .L3
        nop
        nop
        pop     rbp
        ret