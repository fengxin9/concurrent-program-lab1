matrix_product(int**, int*, long long*, int):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-24], rdi
        mov     QWORD PTR [rbp-32], rsi
        mov     QWORD PTR [rbp-40], rdx
        mov     DWORD PTR [rbp-44], ecx
        mov     DWORD PTR [rbp-4], 0
        jmp     .L2
.L3:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        lea     rdx, [0+rax*8]
        mov     rax, QWORD PTR [rbp-40]
        add     rax, rdx
        mov     QWORD PTR [rax], 0
        add     DWORD PTR [rbp-4], 1
.L2:
        mov     eax, DWORD PTR [rbp-4]
        cmp     eax, DWORD PTR [rbp-44]
        jl      .L3
        mov     DWORD PTR [rbp-8], 0
        jmp     .L4
.L7:
        mov     DWORD PTR [rbp-12], 0
        jmp     .L5
.L6:
        mov     eax, DWORD PTR [rbp-12]
        cdqe
        lea     rdx, [0+rax*8]
        mov     rax, QWORD PTR [rbp-40]
        add     rax, rdx
        mov     rcx, QWORD PTR [rax]
        mov     eax, DWORD PTR [rbp-8]
        cdqe
        lea     rdx, [0+rax*8]
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rdx
        mov     rax, QWORD PTR [rax]
        mov     edx, DWORD PTR [rbp-12]
        movsx   rdx, edx
        sal     rdx, 2
        add     rax, rdx
        mov     edx, DWORD PTR [rax]
        mov     eax, DWORD PTR [rbp-8]
        cdqe
        lea     rsi, [0+rax*4]
        mov     rax, QWORD PTR [rbp-32]
        add     rax, rsi
        mov     eax, DWORD PTR [rax]
        imul    eax, edx
        movsx   rdx, eax
        mov     eax, DWORD PTR [rbp-12]
        cdqe
        lea     rsi, [0+rax*8]
        mov     rax, QWORD PTR [rbp-40]
        add     rax, rsi
        add     rdx, rcx
        mov     QWORD PTR [rax], rdx
        add     DWORD PTR [rbp-12], 1
.L5:
        mov     eax, DWORD PTR [rbp-12]
        cmp     eax, DWORD PTR [rbp-44]
        jl      .L6
        add     DWORD PTR [rbp-8], 1
.L4:
        mov     eax, DWORD PTR [rbp-8]
        cmp     eax, DWORD PTR [rbp-44]
        jl      .L7
        nop
        nop
        pop     rbp
        ret