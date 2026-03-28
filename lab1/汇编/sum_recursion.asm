recursive_sum(int*, int):
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     QWORD PTR [rbp-24], rdi
        mov     DWORD PTR [rbp-28], esi
        cmp     DWORD PTR [rbp-28], 1
        jne     .L2
        mov     rax, QWORD PTR [rbp-24]
        mov     eax, DWORD PTR [rax]
        cdqe
        jmp     .L3
.L2:
        mov     DWORD PTR [rbp-4], 0
        jmp     .L4
.L5:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        lea     rdx, [0+rax*4]
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rdx
        mov     ecx, DWORD PTR [rax]
        mov     eax, DWORD PTR [rbp-28]
        sub     eax, DWORD PTR [rbp-4]
        cdqe
        sal     rax, 2
        lea     rdx, [rax-4]
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rdx
        mov     edx, DWORD PTR [rax]
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        lea     rsi, [0+rax*4]
        mov     rax, QWORD PTR [rbp-24]
        add     rax, rsi
        add     edx, ecx
        mov     DWORD PTR [rax], edx
        add     DWORD PTR [rbp-4], 1
.L4:
        mov     eax, DWORD PTR [rbp-28]
        mov     edx, eax
        shr     edx, 31
        add     eax, edx
        sar     eax
        cmp     DWORD PTR [rbp-4], eax
        jl      .L5
        mov     eax, DWORD PTR [rbp-28]
        mov     edx, eax
        shr     edx, 31
        add     eax, edx
        sar     eax
        mov     DWORD PTR [rbp-28], eax
        mov     edx, DWORD PTR [rbp-28]
        mov     rax, QWORD PTR [rbp-24]
        mov     esi, edx
        mov     rdi, rax
        call    recursive_sum(int*, int)
        nop
.L3:
        leave
        ret