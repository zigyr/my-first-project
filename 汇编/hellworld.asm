; 数据段：定义要输出的字符串（0DH=回车，0AH=换行，24H=$是DOS 9号功能的结束符）
DSEG SEGMENT
    MESS DB 'Hello,world!',0DH,0AH,24H  ; 字符串+回车换行+结束符
DSEG ENDS

; 堆栈段：定义256字（512字节）的堆栈空间，PARA STACK指定为堆栈段
SSEG SEGMENT PARA STACK
    DW 256 DUP(?)  ; 256个未初始化的字，作为堆栈空间
SSEG ENDS

; 代码段：程序核心逻辑
CSEG SEGMENT
    ASSUME CS:CSEG, DS:DSEG, SS:SSEG  ; 修正：原行末尾多了一个逗号
BEGIN:  ; 程序入口点
    ; 初始化数据段寄存器DS（8086不能直接MOV DS, 立即数，需通过AX中转）
    MOV AX, DSEG
    MOV DS, AX

    ; DOS 21H中断的9号功能：输出以$结尾的字符串
    MOV DX, OFFSET MESS  ; DX = 字符串首地址
    MOV AH, 9            ; AH = 9（指定功能号）
    INT 21H              ; 调用DOS中断，输出字符串

    ; DOS 21H中断的4CH号功能：程序正常退出，返回DOS
    MOV AH, 4CH
    INT 21H
CSEG ENDS
END BEGIN  ; 指定程序入口点为BEGIN，汇编器据此设置CS:IP