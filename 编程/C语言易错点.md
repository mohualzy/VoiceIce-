
1. **"The scanf/fgets Trap"** 

   如果scanf和fgets连用的话，除了处理fgets后的回车，一定要记得处理scanf后留在缓冲区的回车！！！

2. **memset(\*ptr, value, size)**

   - 定义于<string.h>中
   - 若数组类型非char，则value只能为0或-1
   - size不能是指针的sizeof

3. **strlen和sizeof**

   - sizeof是关键字，编译前就已执行；strlen是函数，运行时执行
   - sizeof算字节，strlen算长度
   - sizeof会算上'\0'（无论有多少），strlen不算'\0'
   - sizeof只计算指针本身的字节；strlen算指针也是长度，但只能算char\*型