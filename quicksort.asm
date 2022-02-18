data_seg segment
arr dw 0001h,0003h,0007h,0004h,0005h,0006h,0009h,0012h,0008h,0002h,1211h,0054h,0660h,2222h,0000h,0010h,0020h,0024h，0002h,0004h,1110h,0056h,8945h,0008h,1056h,0011h,0016h,0018h,0020h;测试数据，测试中运行时间为20~35s，结果正确存在内存0714C处附近
data_seg ends ;定义数据段
stack_seg segment stack
ST dw 200 DUP(?)
stack_seg ends ;定义堆栈段
code_seg segment ; 定义代码段
  assume cs:code_seg,ds:data_seg,ss:stack_seg
  start:
  MOV ax,data_seg
  Mov DS,AX
  mov si,0  ;low指针
  mov di,100 ;high指针  默认上限排序100，排序更大的可以进一步增加初值，实现覆盖
  call QuickSort   ;调用程序
  mov ax,4c00h
  int 21h
QuickSort proc near
  push si
  push di
  call findposition       ;入栈记录位置调用函数完出栈实现递归
  pop di
  pop si
  push di
  push ax                  ;返回ax记录si
  cmp ax,0000h                  ;ax为0执行右端递归
  jbe next1              ;说明递归结束不用执行
  sub ax,2
  mov di,ax                        ;设置递归终止条件
  cmp si,di
  jae next1
  call QuickSort
  next1:nop    ;递归结束不执行即可
  pop ax
  add ax,2 ;从右边开始，因为是从栈中取出的 ,+2
  mov si,ax
  pop di
  cmp si,di
  jae next2
  call QuickSort
  next2:nop
  ret


   ;每次调用为一个值找到应在的位置
QuickSort endp

findposition proc near
  mov bx,arr[si]
p1:
  cmp si,di
  jae return     ;先从右扫描到小于bx(定位值）位置，循环终止条件为si<=di(low<=high)                      
  mov ax,arr[di]                        
  cmp ax,bx
  jae p2                ;小于继续左移
  mov ax,arr[di]        ;alow=ahigh  ++low
 
 mov arr[si],ax
   add si,2

  jmp p3
p2:
  sub di,2
  jmp p1
p3:
  cmp si,di             ;向右扫描直至alow>bx
  jae return
  mov ax,arr[si]
  cmp bx,ax
  jae p4                                   
  mov ax,arr[si]          ;ahign=alow     --high
 
  mov arr[di],ax
   sub di,2
  jmp p1
p4:
  add si,2
  jmp p3
  
return: 

  mov arr[si],bx          ;a[si]=bx，并返回记录si的ax
  mov ax,si
  ret
findposition endp
code_seg ends
 end start