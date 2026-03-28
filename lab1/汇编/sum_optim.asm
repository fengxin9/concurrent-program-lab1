sum_ord(int*, long long&, int):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-40], rdi
        mov     QWORD PTR [rbp-48], rsi
        mov     DWORD PTR [rbp-52], edx
        mov     QWORD PTR [rbp-8], 0
        mov     QWORD PTR [rbp-16], 0
        mov     DWORD PTR [rbp-20], 0
        jmp     .L2
.L3:
        mov     eax, DWORD PTR [rbp-20]
        cdqe
        lea     rdx, [0+rax*4]
        mov     rax, QWORD PTR [rbp-40]
        add     rax, rdx
        mov     eax, DWORD PTR [rax]
        cdqe
        add     QWORD PTR [rbp-8], rax
        mov     eax, DWORD PTR [rbp-20]
        cdqe
        add     rax, 1
        lea     rdx, [0+rax*4]
        mov     rax, QWORD PTR [rbp-40]
        add     rax, rdx
        mov     eax, DWORD PTR [rax]
        cdqe
        add     QWORD PTR [rbp-16], rax
        add     DWORD PTR [rbp-20], 2
.L2:
        mov     eax, DWORD PTR [rbp-20]
        cmp     eax, DWORD PTR [rbp-52]
        jl      .L3
        mov     rdx, QWORD PTR [rbp-8]
        mov     rax, QWORD PTR [rbp-16]
        add     rdx, rax
        mov     rax, QWORD PTR [rbp-48]
        mov     QWORD PTR [rax], rdx
        nop
        pop     rbp
        ret