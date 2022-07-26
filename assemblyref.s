==> add/add.s <==
.section .data

data:
    .int 40

.section .text
.globl _start


_start:
     nop  ; no operation, used for gdb debugger breakpoint
     movl	$0,%eax
     movl	$0,%ebx
     movl	$0,%ecx
     movb	$20,%al
     addb	$10,%al
     addb	$30,%al
     movl	$122,%ebx
     addl	data,%ebx
     nop  ;no operation
     nop

==> arithmetic/add_sub.s <==
.section .text

.globl _start

_start:
     mov $0,%eax
     mov var2,%eax
     add var2,%eax
     sub var2,%eax
     mov $60,%rax
     mov $0,%rdi
     syscall

var1:
    .WORD 1000

var2:
    .WORD 2000

==> arithmetic/inc_dec.s <==
.text

.globl _start

_start:
      nop
      mov myWord,%bx
      inc %bx
      dec %bx
      nop
      nop

myWord:
    .WORD 1000

==> bswap/endian.s <==
.section .text

.globl _start

_start:
      nop
      movl $0x12345678,%ebx
      bswap %ebx
      nop
      nop

==> bubblesort/bubble.s <==
#for(out = array_size -1; out > 0; out--){
#   for(in = 0; in < out; in++){
#        if(array[in] > array[in+1]){
#            swap(array[in],array[in + 1]);
#        }
#    }
#}

.section .data

values:
     .int 10,12,6,9,13,67,5,3,87,56

.section .text
.globl _start

_start:
     nop
     movl $values,%esi
     movl $9,%ecx
     movl $9,%ebx

top: 
     movl (%esi),%eax
     cmp %eax,4(%esi)
     jge skip
     xchg %eax,4(%esi)
     movl %eax,(%esi)  

skip:
    add $4,%esi
    dec %ebx # inner loop
    jnz top
    dec %ecx #outer loop
    jz end
    movl $values,%esi
    movl %ecx,%ebx
    jmp top

end:
    movl $1,%eax
    movl $0,%ebx
    int $0x80
    nop
    nop

==> call/call.s <==
.section .text

.globl _start

_start:
      nop
      movl $65,%eax
      movl $89,%ebx
      call _bottom
      movl $77,%ecx
      ret

_bottom:
      nop
      addl $100,%eax
      addl $50,%ebx
      ret

==> call_c_lib/hello_NASM.s <==
.text
.globl main

main:
     mov $message,%rdi
     call puts
     ret

message: 
       .asciz "Hello, world\n"


#***NASM equivalent*** 
#
#
#global main
#extern puts
#
#main:
#    mov rdi,message
#    call puts
#    ret
#
#message: db "Good day",0



==> call_c_lib/hello.s <==
.text
.globl main

main:
     mov $message,%rdi
     call puts
     ret

message: 
       .asciz "Hello, world\n"


#***NASM equivalent*** 
#
#
#global main
#extern puts
#
#main:
#    mov rdi,message
#    call puts
#    ret
#
#message: db "Good day",0



==> case_converter/toupper.s <==
.section .data 
string1:
       .ascii "This is a test of the conversion program.\n"

length:
       .int 43

.section .text
.globl _start

_start:
      nop
      leal string1,%esi #load effective address
      movl %esi,%edi # destination register
      movl length,%ecx  # register used as counter for loop instruction
      cld  # clear df flag

top:      
      lodsb   # loads instruction can be lodsb, lodsw or lodsl, used to place string value in eax register
      cmpb $'a',%al     # $'a' refers to ascii symbol 'a'
      jl skip
      cmpb $'z',%al     # $'a' refers to ascii symbol 'a'
      jg skip
      subb $0x20,%al

skip:
     stosb  # stos used to place string in another memory location stosb, stosw, stosl
     loop top

exit:
    movl $1,%eax
    movl $0,%ebx
    int $0x80
    nop
    nop

==> commandlinearguments/command_NASM.s <==
#int main(int argc, char ** argv) used for arguments from commandline
# argc = %rdi, argv = %rsi in assembly language 

.section .text

.globl main

main:
    push %rdi   #save rdi (on stack)
    push %rsi   #save rsi on stack
    sub $8,%rsp #align stack before call
    
    mov (%rsi),%rdi
    call puts

    add $8,%rsp  # restore rsp to pre-align value
    pop %rsi     # restore rsi
    pop %rdi     # restore rdi
    add $8,%rsi  # point to next number
    dec %rdi     # decrement number of arguments
    jnz main     # rdi holds number of arguments

    ret


#***NASM equivalent***
#
#section .text
#global main
#extern puts
#
#main:
#    push rdi
#    push rsi
#    sub rsp,8
#    mov rdi,[rsi]
#    call puts
#    add rsp,8
#    pop rsi
#    pop rdi
#    add rsi,8   ; point to next argument
#    dec rdi 
#    jnz main
#
#    ret 
  

==> commandlinearguments/command.s <==
#int main(int argc, char ** argv) used for arguments from commandline
# argc = %rdi, argv = %rsi in assembly language 

.section .text

.globl main

main:
    push %rdi   #save rdi (on stack)
    push %rsi   #save rsi on stack
    sub $8,%rsp #align stack before call
    
    mov (%rsi),%rdi
    call puts

    add $8,%rsp  # restore rsp to pre-align value
    pop %rsi     # restore rsi
    pop %rdi     # restore rdi
    add $8,%rsi  # point to next number
    dec %rdi     # decrement number of arguments
    jnz main     # rdi holds number of arguments

    ret


#***NASM equivalent***
#
#section .text
#global main
#extern puts
#
#main:
#    push rdi
#    push rsi
#    sub rsp,8
#    mov rdi,[rsi]
#    call puts
#    add rsp,8
#    pop rsi
#    pop rdi
#    add rsi,8   ; point to next argument
#    dec rdi 
#    jnz main
#
#    ret 
  

==> commandlinearguments/commnew.s <==
#int main(int argc, char ** argv) used for arguments from commandline
# argc = %rdi, argv = %rsi in assembly language 

.section .text

.globl _start

_start:
    pop %rdi   #save rdi (on stack)
    pop %rsi   #save rsi on stack
    sub $8,%rsp #align stack before call
    
    mov (%rsi),%rdi
    #call puts

    add $8,%rsp  # restore rsp to pre-align value
    #pop %rsi     # restore rsi
    #pop %rdi     # restore rdi
    add $8,%rsi  # point to next number
    dec %rdi     # decrement number of arguments
    jnz _start     # rdi holds number of arguments

    ret


#***NASM equivalent***
#
#section .text
#global main
#extern puts
#
#main:
#    push rdi
#    push rsi
#    sub rsp,8
#    mov rdi,[rsi]
#    call puts
#    add rsp,8
#    pop rsi
#    pop rdi
#    add rsi,8   ; point to next argument
#    dec rdi 
#    jnz main
#
#    ret 
  

==> conditional_jump/cond_jump.s <==
.section .text

.globl _start

_start:
      nop
      movl $15,%eax
      movl $30,%ebx
      movl $0,%ecx
      cmp %eax,%ebx
      jge greater
      nop
      int $0x80

greater:
       addl $40,%ecx
       movl $1,%eax
       movl $3,%ebx
       int $0x80     
       nop
       nop


==> conditional_jump/jmp.s <==
.section .text

.globl _start

_start:
      nop
      movl $34,%eax
      jmp _bottom
      movl $67,%eax
      movl $56,%eax
 
_bottom:
      nop
      movl $15,%ebx
      movl $1,%eax
      movl $0,%ebx
      int $0x80  

==> fibonacci/fib_NASM.s <==
.section .data
format:
      .asciz "%20ld\n"    

.text

.globl main

main:
    push %rbx #pushes onto the stack
    movl $50,%ecx #counter
    xor %rax,%rax #will hold current number
    xor %rbx,%rbx #will hold the next number
    inc %rbx #increments %rx
    
top:
    # printf takes arguments and doesn't return anything so necessry to push onto the stack otherwise printf may destroy them
    push %rax
    push %rcx
    mov $format,%rdi #1st argument to printf
    mov %rax,%rsi    #2nd arg
    xor %rax,%rax
    call printf

    pop %rcx
    pop %rax

    mov %rax,%rdx #save current number
    mov %rbx,%rax #next number -> current number
    add %rdx,%rbx  #next number
    loop top

    pop %rbx
    ret


#***NASM Equivalent***
#
#section .text
#global main
#extern printf
#
#main:
#    push rbx
#    mov ecx,50
#    xor rax,rax
#    xor rbx,rxb
#    inc rbx
#    
#top:
#    push rax
#    push rcx
#
#    mov rdi,format  ; 1st parameter of function
#    mov rsi,rax     ; 2nd parameter of function
#    xor rax,rax
#    call printf
#    pop rcx 
#    pop rax
#
#    mov rdx,rax  ; save the current number
#    mov rax,rbx  ; next number = current number
#    add rbx,rdx  ; get the new number
#    dec ecx  
#    jnz top
#
#format: db "%20ld",10,0

==> fibonacci/fib.s <==
.section .data
format:
      .asciz "%20ld\n"    

.text

.globl main

main:
    push %rbx #pushes onto the stack
    movl $50,%ecx #counter
    xor %rax,%rax #will hold current number
    xor %rbx,%rbx #will hold the next number
    inc %rbx #increments %rx
    
top:
    # printf takes arguments and doesn't return anything so necessry to push onto the stack otherwise printf may destroy them
    push %rax
    push %rcx
    mov $format,%rdi #1st argument to printf
    mov %rax,%rsi    #2nd arg
    xor %rax,%rax
    call printf

    pop %rcx
    pop %rax

    mov %rax,%rdx #save current number
    mov %rbx,%rax #next number -> current number
    add %rdx,%rbx  #next number
    loop top

    pop %rbx
    ret


#***NASM Equivalent***
#
#section .text
#global main
#extern printf
#
#main:
#    push rbx
#    mov ecx,50
#    xor rax,rax
#    xor rbx,rxb
#    inc rbx
#    
#top:
#    push rax
#    push rcx
#
#    mov rdi,format  ; 1st parameter of function
#    mov rsi,rax     ; 2nd parameter of function
#    xor rax,rax
#    call printf
#    pop rcx 
#    pop rax
#
#    mov rdx,rax  ; save the current number
#    mov rax,rbx  ; next number = current number
#    add rbx,rdx  ; get the new number
#    dec ecx  
#    jnz top
#
#format: db "%20ld",10,0

==> floating_point_mix_c_assem/sum.s <==
.text

.globl sum

sum:
   xorpd %xmm0,%xmm0 # initialize to zero, floating point registers
   cmp $0,%rsi       # check if length is zero
   je done

top:
   addsd (%rdi),%xmm0 # add the current array element
   add $8,%rdi        # move to next array element
   dec %rsi
   jnz top

done:
   ret


==> getpower/power_NASM.s <==
#int main(int argc, char ** argv) used for arguments from commandline
# argc = rdi -name of program is usually passed in as an argument here so in order to check if two variables have been passed for x^y
# needs to be three arguments
# argv = rsi
.text
.globl main

main:
    #by pushing three registers, the stack will be aligned to raise the call function
    push %r12
    push %r13
    push %r14

    cmp $3,%rdi    # number of arguments must be 2 + 1 (name of program)
    jne error1

    mov %rsi,%r12  #argv

    # use esi, to hold value of base and eax to hold running product
    mov 16(%r12),%rdi   #argv[2] = y
    call atoi  #converts string to an integer - places 'y' in eax
    cmp $0,%eax
    jl error2
    mov %eax,%r13d

    mov 8(%r12),%rdi   # argv[1] = x
    call atoi          # x in eax ; places 'x' in eax
    mov %eax,%r14d     # x in r14d

    mov $1,%eax

tpp:
    test %r13d,%r13d  # test keyword used to perform a bitwise &
    jz found
    imull %r14d,%eax
    dec %r13d
    jmp tpp

found: 
     mov $answer,%rdi
     movslq %eax,%rsi
     xor %rax,%rax
     call printf
     jmp done

error1:
    mov $wrongArgumentCount,%edi
    call puts 
    jmp done

error2:
    mov $negativeExponentDetected,%edi
    call puts 
    jmp done

done:
    pop %r14
    pop %r13
    pop %r12

    ret

.section .data
answer:
      .asciz "%d\n"

wrongArgumentCount:
      .asciz "Program requires exactly 2 arguments.\n"

negativeExponentDetected:
      .asciz "Only positive exponents allowed.\n"


#*** NASM equivalent ***
#
#section .text
#extern printf
#extern puts
#extern atoi
#
#global main
#
#main:
#     push,r12
#     push,r13
#     push,r14
#
#     cmp rdi,3
#     jne error1
#     
#     mov r12,rsi   ; argv
#     mov rdi,[r12+16]   ; argv[2]
#     call atoi
#     cmp eax,0
#     jl error2
#     mov r13d,eax    ; y value (the exponent in r13d)   
#     mov rdi,[r12+8] ; argv[1]
#     call atoi       ; x in eax
#     mov r14d,eax    ; x in r14d
#
#top:
#     test r13d,r13d
#     jz found
#     imul eax,r14d
#     dec r13d
#     jmp top
#
#found:
#     mov rdi,answer
#     movsxd rsi,eax
#     xor rax,rax
#     call printf 
#
#error1:
#     mov edi,wrongArgumentCount
#     call puts
#     jmp done
#
#error2:
#     mov edi,badExponentType
#     call puts
#     jmp done
#
#done:
#     pop r14
#     pop r13
#     pop r12
#     ret
#
#wrongArgumentCount: db "Program requires exactly two arguments",10,0
#badExponentType: db "Only positive exponents allowed",10,0 
#
#answer: db "%d",10,0
   

==> getpower/power.s <==
#int main(int argc, char ** argv) used for arguments from commandline
# argc = rdi -name of program is usually passed in as an argument here so in order to check if two variables have been passed for x^y
# needs to be three arguments
# argv = rsi
.text
.globl main

main:
    #by pushing three registers, the stack will be aligned to raise the call function
    push %r12
    push %r13
    push %r14

    cmp $3,%rdi    # number of arguments must be 2 + 1 (name of program)
    jne error1

    mov %rsi,%r12  #argv

    # use esi, to hold value of base and eax to hold running product
    mov 16(%r12),%rdi   #argv[2] = y
    call atoi  #converts string to an integer - places 'y' in eax
    cmp $0,%eax
    jl error2
    mov %eax,%r13d

    mov 8(%r12),%rdi   # argv[1] = x
    call atoi          # x in eax ; places 'x' in eax
    mov %eax,%r14d     # x in r14d

    mov $1,%eax

tpp:
    test %r13d,%r13d  # test keyword used to perform a bitwise &
    jz found
    imull %r14d,%eax
    dec %r13d
    jmp tpp

found: 
     mov $answer,%rdi
     movslq %eax,%rsi
     xor %rax,%rax
     call printf
     jmp done

error1:
    mov $wrongArgumentCount,%edi
    call puts 
    jmp done

error2:
    mov $negativeExponentDetected,%edi
    call puts 
    jmp done

done:
    pop %r14
    pop %r13
    pop %r12

    ret

.section .data
answer:
      .asciz "%d\n"

wrongArgumentCount:
      .asciz "Program requires exactly 2 arguments.\n"

negativeExponentDetected:
      .asciz "Only positive exponents allowed.\n"


#*** NASM equivalent ***
#
#section .text
#extern printf
#extern puts
#extern atoi
#
#global main
#
#main:
#     push,r12
#     push,r13
#     push,r14
#
#     cmp rdi,3
#     jne error1
#     
#     mov r12,rsi   ; argv
#
#     mov rdi,[r12+16]   ; argv[2]
#     call atoi
#     cmp eax,0
#     jl error2
#     mov r13d,eax    ; y value (the exponent in r13d)   
#
#     mov rdi,[r12+8] ; argv[1]
#     call atoi       ; x in eax
#     mov r14d,eax    ; x in r14d
#
#     mov eax,1
#top:
#     test r13d,r13d
#     jz found
#     imul eax,r14d
#     dec r13d
#     jmp top
#
#found:
#     mov rdi,answer
#     movsxd rsi,eax
#     xor rax,rax
#     call printf 
#
#error1:
#     mov edi,wrongArgumentCount
#     call puts
#     jmp done
#
#error2:
#     mov edi,badExponentType
#     call puts
#     jmp done
#
#done:
#     pop r14
#     pop r13
#     pop r12
#     ret
#
#wrongArgumentCount: db "Program requires exactly two arguments",10,0
#badExponentType: db "Only positive exponents allowed",10,0 
#
#answer: db "%d",10,0
   

==> mixing_c_assem/max1.s <==
.section .data
var1:
    .int 30
var2:
    .int 40
var3:
    .int 20
message1:
    .asciz "B is greatest\n"

message2:
    .asciz "C is greatest\n"

message3:
    .asciz "A is greatest\n"

.section .text

.globl _start

_start:
      movl var1,%esi
      movl var2,%edi
      movl var3,%ebp
      cmp %esi,%edi
      jge bgreater
      cmp %esi,%ebp
      jge cgreater
      mov $1,%rax
      mov $1,%rdi
      mov $message3,%rsi
      mov $15,%rdx
      syscall
      jmp exit

bgreater:
      cmp %edi,%ebp
      jge cgreater
      mov $1,%rax
      mov $1,%rdi
      mov $message1,%rsi
      mov $15,%rdx
      syscall
      jmp exit
  
cgreater:
      mov $1,%rax
      mov $1,%rdi
      mov $message2,%rsi
      mov $15,%rdx
      syscall
      jmp exit

exit:
     mov $60,%rax
     mov $0,%rdi
     syscall      


==> mixing_c_assem/max,s <==
.section .text 
.global getmax

==> mixing_c_assem/max.s <==
# cmov : compare move, cmovb, cmovw, cmovl
# %rax register holds the return value of a function, all other registers as normally specified for arguments

.section .text
.globl getmax

getmax:
      mov %rdi,%rax
      cmp %rsi,%rax
      cmovl %rsi,%rax
      cmp %rdx,%rax
      cmovl %rdx,%rax
      ret

==> recursive_factorial/fact.s <==
.text 

.globl factorial

factorial:
         cmp $1,%rdi    # n<=1 
         jnbe bottom    # if not jump to recursive function
         mov $1,%rax 
         ret

bottom:
         push %rdi
         dec %rdi
         call factorial
         pop %rdi        #restore n, when popped off the stack goes back into %rdi
         imul %rdi,%rax  # n * factorial(n-1)
         ret

==> recursive_factorial/newfact.s <==
.text 

.globl _start

_start:
       mov $3,%rdi

factorial:
         cmp $1,%rdi    # n<=1 
         jnbe bottom    # if not jump to recursive function
         mov $1,%rax 
         ret

bottom:
         push %rdi
         dec %rdi
         call factorial
         pop %rdi        #restore n
         imul %rdi,%rax  # n * factorial(n-1)
         ret

==> rep/rep.s <==
.section .data
value1:
      .ascii "This is a test string.\n"

.section .bss
      .lcomm output,23

.section .text
.globl _start

_start:
      nop 
      leal value1,%esi # source register
      leal output,%edi # destination register
      movl $23,%ecx
      cld   # clears direction flag, sets to zero, used for rep instruction as wel as movsx etc, can be set to 0 or 1
      rep movsb  # will increment through until has moved entire string

      movl $1,%eax
      movl $0,%ebx
      int $0x80


==> sal/sal.s <==
# sal destination   ; shift arithemtic left destination left by one value (equiv to multiplying by 2)
# sal %cl,destination 
# sal shifter,destination 

.section .data
value1:
      .int 25

.section .text
.globl _start
_start:
      nop
      movl $10,%ebx
      sall %ebx
      movb $2,%cl
      sall %cl,%ebx
      sall $2,%ebx
      sall value1 
      sall $2,value1

      int $0x80


==> stack_exp/stack.s <==
# rbp - base pointer register points to the botom of current stack frame
# rsp - stack pointer register, points to the top of current stack frame
# push rsi  - increments rsp and pushes rsi onto the top of the stack
# pop rax   - pops what is on the top of the stack and puts it into rax

.section .data

SYS_WRITE: .int 1
STD_OUT: .int 1   
SYS_EXIT: .int 60
EXIT_CODE: .int 0
BAD_ARG_COUNT: .asciz "Program accepts exactly 2 arguments only.\n"
NEW_LINE: .asciz "\n"

.section .bss
      .lcomm output,23

.section .text
.globl _start

# int main(int argc, char ** argv)
# [rsp] - top of stack = argc
# [rsp + 8] first argv[1]
# [rsp +16] second argv[2]

_start:
      xor %rbx,%rbx
      xor %r12,%r12
      mov $0,%rsi
      pop %rcx  # argc = rcx, gets arg count from stack
      cmp $3,%rcx
      jne argcError
      #add $8,%rsp
      pop %rsi        # skip argv[0] the program name
      pop %rsi        # get argv[1]
#      mov $1,%rax
#      mov $1,%rdi
#      mov $5,%rdx
#      syscall

      jmp str_to_int  # will convert string to int

next1:
      mov %rbx,%r10   # arg1 number in r10
      xor %rbx,%rbx
      pop %rsi        # pops argv[2] off the stack and places in rsi register
      jmp str_to_int  # will convert string to int

next2:
      mov %rbx,%r11   # arg2 number in r11
      add %r11,%r10   # add arg1 + arg2
      mov %r10,%rax
      xor %r12,%r12
      mov $0,%rsi 

      jmp int_to_str

str_to_int:
      cld
      xor %rcx,%rcx
      mov $1,%rdi

top:
      xor %rax,%rax
      lodsb
      subb $48,%al      # subtract 48 from ascii value to get integer value
      movzx %al,%rax

      cmp $10,%rax
      jge read
      cmp $0,%rax
      jl read
      push %rax
      inc %rcx
      jmp top
 
read:
      pop %rax
      mul %rdi          # rax = rax * rcx
      imul $10,%rdi
      add %rax,%rbx     # rax = rax + number
      dec %rcx
      jz done1
      jmp read

int_to_str:
      mov $0,%rdx
      mov $10,%rbx
      div %rbx
      add $48,%rdx
      push %rdx     # push to rsp
      inc %r12
      cmp $0x0,%rax
      jne int_to_str
      jmp print

print:
      mov $1,%rax 
      mul %r12     #multiply by length of array
      mov $8,%r12  
      mul %r12
      mov %rax,%rdx  

      mov $1,%rax
      mov $1,%rdi
      mov %rsp,%rsi
      syscall
      mov $1,%rax
      mov $1,%rdi
      mov $NEW_LINE,%rsi
      mov $3,%rdx
      syscall
      jmp exitt

argcError:
      mov $1,%rax
      mov $1,%rdi
      mov $BAD_ARG_COUNT,%rsi
      mov $45,%rdx
      syscall
      jmp exitt

exitt:
      mov $60,%rax
      mov $0,%rdi
      syscall

done1:
     add $1,%r12
     cmp $2,%r12
     je next2
     jmp next1

==> stringcompare/compare.s <==
# cmps used to compare strings : cmpsb, cmpsw, cmpsl

.section .data
var1:
    .ascii "Test"

var2:
    .ascii "Test"

.section .text
.globl _start

_start:
      nop
      movl $1,%eax
      leal var1,%esi
      leal var2,%edi
      cld 
      cmpsl 
      je equal
      movl $1,%ebx
      int $0x80

equal:
     movl $0,%ebx
     int $0x80


==> stringcompare/sentencecompare.s <==
# rep instruction belongs to a family of instructions repe/repne (if equal/not equal), repz (if zero), repnz (if not zero)  

.section .data
var1:
    .ascii "This is a test of cmps instructions.\n"

var2:
    .ascii "This is a test of cmps instructions.\n"

.section .text
.globl _start

_start:
      nop
      leal var1,%esi
      leal var2,%edi
      movl $37,%ecx
      cld

top:
      repe cmpsb
      jne unequal
      #loop top
      movl $1,%eax
      movl $0,%ebx
      int $0x80 

unequal:
     movl $1,%eax
     movl $1,%ebx
     int $0x80

==> stringsearch/scan.s <==
#scas - scan string nistrction, scasb, scasw, scasl uses eedi and esi registers

.section .data
string1:
       .ascii "This- is a test a long text string to scan"
length:
       .int 42
string2:
       .ascii "*"

.section .text
.globl _start
 
_start:
      nop 
      leal string2,%esi
      leal string1,%edi
      movl length,%ecx
      lodsb # used to place string value from esi in eax register
      cld
      repne scasb  # scasb function uses string in source esi to scan string in destination edi
      jne notfound
      movl $1,%eax 
      movl $0,%ebx
      int $0x80
      #subw length,%cx    
      #neg %cx

notfound:
      movl $1,%eax 
      movl $1,%ebx
      int $0x80

==> strings/string1.s <==
#movsb : moving a single byte
#movsw : moving a 16-bit word
#movsl : moving a 32-bit long word

#   movel $ myvar,%edi  ; use of $ symbol refers to memory address of variable
# lea : loading effective address doesn't use dollar sign to reference memory addrwss

.section .data
value1:
     .ascii "This is a test string.\n"

# .bss used for uninitialized code variables, i.e. for storing incoming data,
# .lcomm = local common variable,  output, 23 characters long
.section .bss 
      .lcomm output,23

.section .text
.globl _start

_start:
      nop
      leal value1,%esi # source register
      leal output,%edi # destination register
      movsb
      movsw
      movsl
      movl $1,%eax
      movl $0,%ebx
      int $0x80

==> strings/string2.s <==
#loop instruction automatically looks into the ecx register for count (number of iterations of loop instruction)

.section .data
value1:
      .ascii "This is a test string.\n"

.section .bss
      .lcomm output,23

.section .text
.globl _start

_start:
      nop
      leal value1,%esi # source register
      leal output,%edi # destination register
      movl $23,%ecx

load:
     movsb 
     loop load

     movl $1,%eax
     movl $0,%ebx
     int $0x80

==> sub/sub.s <==
.section .data

data:
    .int 40

.section .text
.globl _start

_start:
      nop
      movl $0,%eax
      movl $0,%ebx
      movb $20,%al  # mov long word
      subb $10,%al  # sub byte
      movsx %al,%eax
      movw $100,%cx
      subw %cx,%bx     # sub word  "0 - 100"
      movsx %bx,%ebx       
      movl $100,%edx
      subl %eax,%edx   # sub long word 
      subl data,%eax
      subl %eax,data   # to print data, use x/d &data

      movl $1,%eax
      movl $0,%ebx
      int $0x80

==> syscall/syscall.s <==
# https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
# https://filippo.io/linux-syscall-table/

.section .data
var1:
    .int 30
var2:
    .int 40
var3:
    .int 20
message1:
    .asciz "B is greatest\n"

message2:
    .asciz "C is greatest\n"

message3:
    .asciz "A is greatest\n"

message:
       .asciz "Hello, world\n"

.section .text

.globl _start
_start:
      mov $1,%rax  # System call number in rax, function =  ksys_write(unsigned int fd, const char __user *buf, size_t count)
      mov $1,%rdi  # unsigned int fd: file handle 1, i.e. stdout file handle 2 = stderr, file handle 0 = stdin
      mov $message,%rsi  # move message into const char __user *buf
      mov $13,%rdx # specifies number of bytes (size_t_count)
      syscall
      mov $60,%rax # System call to sys_exit - do_group_exit(int exit_code)
      mov $0,%rdi  # argument for int exit code
      syscall

