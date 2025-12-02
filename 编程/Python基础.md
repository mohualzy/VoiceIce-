# 目录

- [第一部分](#第一部分)
  - [注释](#注释)
  - [基础关键字、语法](#基础关键字、语法)
  - [数据容器](#数据容器)
  - [函数](#函数)
- [第二部分](#第二部分)
  - [文件处理](#文件处理)
  - [模块、库、包](#模块、库、包)
- [第三部分](#第三部分)
  - [类与对象](#类与对象)
# 读前须知

本篇笔记并不旨于让你成为一个python大佬，只力求能读懂github/AI项目的部分代码，学会写一些简单、基础的功能。python部分语法与C语言相似，就止于一提，不再过多赘述。

在阅读本篇笔记之前，请在你的电脑上配置好python环境，建议使用vscode来跑代码

[python的path配置](https://www.bilibili.com/video/BV1HZ4y1K7P7?t=2.2)
[vscode中配置python解释器](https://www.bilibili.com/video/BV1tF411M7hy?t=1.8)
# 第一部分

## 注释

c/cpp中用/\*或//的形式进行注释，而python采取如下两种注释方式
```
# 用井号进行单行注释

'''
用三引号
进行
多行注释
'''
```
## 基础关键字、语法
### int、float、str、bool等数据类型

与C语言不同,python中定义变量不需要写关键字，直接定义即可，如图

![[Pasted image 20251122141340.png|200]]
这几个关键字的作用，在python中主要用于**强制转换**，如
```
x = 5
x = str(x) #x的类型由整型变为字符串型（python中字符属于字符串）
```
双引号和单引号包围起来的都是str（字符串）类型

bool型分为True和False两种（*须大写！*）

空值型为None(*不同于C中的NULL*)

**（特别注意：int强转会四舍五入，而不是C语言中的截断）**

另：python中不需要写分号，一行就是一个语句

### 输入输出

输出：**print**
输出：**input**
```
#例子：
x = input() #你在终端输入一个数
print(x)
```
**重要细节**：input输入的东西会自动转成字符串类型，如果想输入数字进行运算的话，需要用int或float进行强转
### 运算符

\*\*代表乘方，如2\*\*3=8

/号在python中正常进行数学除法，如5/2\==2.5, 1/9\==1.111111112

//为取整，如5//2\==2

！一般只用于!=表示不等于，逻辑判断中用not
```
x = not (2 > 3)
if not x == 5 ：
```
其余与C类似

### 格式化

python可以使用+号进行字符串拼接，如
```
print("你好:" + "我是月") #结果为"你好:我是月"
```
但无法进行数字类型与字符串类型的拼接，所以引入格式化（format）
一般形式如下：
```
x = 5
print(f"我要输出一个x，它的值是{x}")
```

结果为：
![[Pasted image 20251122144753.png|]]
与C中的%d、%f等差不多，但python更常用f格式化语法

### if-else

基本形式：
```
if (a > b):        #一定得写冒号
	a = a + b      #以缩进的形式代替C语言中的大括号
	print(a)
elif (a == b):     #elif就是C语言中的else if
	print(a)
else:              #else后面也得写冒号
	b = b - a
	print(b)       
```

### while/for循环

while循环与C语言基本没区别，不讲

着重讲**for循环**

先看一下基本形式：
```
for i in range(0,5):    ''' i是临时变量，range(0,5)指从0到4，这句话与C语言中的
							for (int i = 0; i < 5; i++)意思相同
```
in是一个与for绑定的关键字，字面意思，在......之中

再如：
```
words = "hello world"
for word in words:    # 遍历字符串
	print(word)       # 结果为 h
							  e
							  l 
							......#python一行语句为一行，所以在循环中会自动换行
```
如果不想自动换行，就把输出语句改为：
```
print(word,end="")    #结果为：hello world
```
**注意：C语言中本来需要大括号包围起来的语法，如if-else、while、for等，在python中都以冒号加缩进的形式实现**

## 数据容器

### 列表（list）

形式：\[]

例如：x = \[1, 2, 4, 8], y = \["张乐冉"，"徐筱佩"，"程佳琦"，"吕芷涵"]

列表允许嵌套，即a = \[\[1, 2, 3], \["nihao", "666"]]（其实除字符串外都允许）

#### 处理方法(大多数都是通用的，所以其他的底下就不重复写了)

1. **索引** 
- *正向索引*
   x\[0] = 1, y\[1] = "徐筱佩"
- *逆向索引*
   x\[-1] = 8, x\[-2] = 4
- 嵌套索引
   a\[0]\[1] = 2, a\[1]\[0] = "nihao"
2. **查询**
   查找某元素的下标

   功能：查找指定元素在列表的下标，如果找不到，报错ValueError

   语法：列表.index(元素)

   name_list=\['tom','lily','sam']

   print(name_list.index('tom'))        列表的第一个元素 结果是0
3. **增添**
- *插入*
   
   语法：列表.insert(下标, 元素)，在指定的下标位置，插入指定的元素

   name_list=\[1,2,3]

   name_list.insert(1,'a')

   print(name_list)   #1,a,2,3      在第二个位置插入元素‘a’,其他元素往后挪
- *追加*
   
   语法：列表.append(元素)，用于在列表末尾添加一个新的元素。这个元素可以是任何数据类型，如数字、字符串、列表、字典等。

   name_list=\[1,2,3]

   name_list.append(\[4,5,6])

   print(name_list)         结果为\[1,2,3,\[4,5,6]]

4. **删除**
- *索引删除*
  语法1： del 列表\[下标]

  name_list=\[1,2,3]

  del name_list\[0]

  print(name_list) # 结果是\[2,3]

  语法2：列表.pop(下标)

  name_list=\[1,2,3]

  a=name_list.pop\[0]

  print(name_list)  结果为\[2,3]

  print(a)           结果为1

  pop和del 的区别是 pop是把列表中的指定元素取出来并且可以赋值给一个变量，而del仅仅是把列表中的指定元素删除

- *删除指定元素*
  语法：列表.remove(元素) 移除列表中第一个匹配的指定的元素

  name_list=\[1,2,3,2]

  name_list.remove(2)

  print(name_list)              结果为 \[1,3,2]

- *清空*
  语法：列表.clear()

  name_list=\[1,2,3,2]

  name_list.clear()

  print(name_list)   结果为 \[]  （空列表）
5. **获取长度** 
   语法：len(列表)

   name_list=\[1,2,3,2]

   print(len(name_list))     结果为4 列表中一共有4个元素
6. **统计某元素数量** 
   语法：列表.count(元素) 统计指定元素在列表中的个数

   name_list=\[1,2,3,2]

   name_list.count(2)

   print(name_list.count(2))     结果为2 列表中元素2一共有2个
### 元组（tuple）

形式：()

例如：x = (1, 2, 3)

**元组中的元素不可修改**，其他与列表基本相同

#### 处理方法

与列表基本相同，但不能进行增删操作
### 字符串（string）

x = "abcd44342"

x\[1] = "b"

#### 特有方法

1. **替换**
   语法：字符串.replace(字符串1，字符串2）

   功能：将字符串内的全部：字符串1，替换为字符串2

   注意：因为字符串是不可以修改的，所以是得到了一个新字符串哦

   t1='abcdefg'

   t2=t1.replace('a','b')

   print(t2)            结果为bbcdefg

   print(t1)        结果为abcdefg 可以看到原字符串不变，是得到了一个新的字符串

2. **分割**
   语法：字符串.split(分隔符字符串）

   功能：按照指定的分隔符字符串，将字符串划分为多个字符串，并存入列表对象中

   注意：字符串本身不变，而是得到了一个列表对象

   t1='a b c d'

   t2=t1.split(' ')

   print(t1)         结果为a b c d

   print(t2)        结果为'a','b','c','d' 可以看到，字符串按照给定的 进行了分割，变成多个子字符串，并存入一个列表对象中。

3. **规整化**（去除前后两端空格或其他指定字符）
   语法：字符串.strip()

   t1='!abcd!'

   t2=t1.strip('!')

   print(t1)             结果为 '!abcd!'

   print(t2)             结果为abcd

### 集合（set）

形式：{}

例如：x = {1, 2, 3}

**集合中不允许出现重复元素**

### 字典

**重点！**
- 字典的定义，同样使用{}，不过存储的元素是一个个的：键值对

  如下语法：
  my_dict={key:value,key:value,key:value}

  使用{}存储原始，每一个元素是一个键值对

  每一个键值对包含key和value（用冒号分隔）

  键值对之间使用逗号分隔

  注意: key不能是可变类型

  value可以是任意类型的数据
  
  key不可重复，重复会对原有数据覆盖

  
  my_dict={'a' : 1, 'b' : 2, 'c' : 3}

- 后缀有keys()，values()和items()三种，字面意思

  x = \{"张乐冉" : 95，"徐筱佩" : 96，"程佳琦" : 97，"吕芷涵" : 98}

  key = x.keys(), value = x.values(), item = x.items()

  print(key)       

  print(value)     

  print(item)      

  结果如图
  ![[Pasted image 20251202170047.png]]


- 嵌套字典（json中最为常见）

  ![[Pasted image 20251202170234.png]]

## 函数

1. 形式：def + 函数名（形参）：

   函数内容记得也要缩进（1个tab）

   调用与C语言一样

   函数内部的变量均为局部变量，既可以在函数前定义一个全局变量，也可以在函数内定义的变量名前加上global关键字使其变为全局变量

2. 多返回值

```
   def receive():
		return 1, 2, "a"
		
	x, y, z = receive()
	print(x,y,z)        #结果为1，2，a
```

3. 传参方式

- **位置传参、关键字传参，缺省传参**

```
  def user_info(name, gender, age):
	  print(f"姓名是{name},性别是{gender},年龄是{age}.")
	  
  user_info(小陆，男，18)     #对应位置输入实参
  ----------------------------------------------
  user_info(name = "小陆", age = 18, gender = "男“)     #形参名加上实参，可以忽略位置            
  ----------------------------------------------
  def user_info(name, gender, age = 18):  #在定义函数时就设置默认值，但只能给最后一个参数设置
```

- **不定长参数**

  有时我们不知道要传多少参数（或者懒得写），可以使用如下形式，想传多少参数就传多少

```
  def user_info(*args):
	  print(args)
	  
  user_info("小陆")        #结果为小陆
  ----------------------------------------------
  user_info("小陆", 18)    #结果为小陆,18
```

4. **异常（bug）处理**

   有时我们写的函数执行起来可能会发生各种各样的错误（非语法错误），比如程序要求用户输入一个数字，但用户输入一个字母，然后提交，这样程序就会直接停止，无法进行下一步操作，这就很不优雅

   解决方法：如果我们可以将用户的错误捕获起来，然后返回上一步操作，并对用户进行错误提示，用户就可以紧接着继续输入，程序继续执行。

   代码演示：

```
   def capture(num):
	   try:                       #如果出现bug，程序就会不执行try后面的语句
		   num += 1 
		   return num
	   except Exception as e:     #捕获所有异常情况，标准语句，不用修改
		   print("请输入1个数字！")
```
5. **跨文件调用（下节会讲）**

   模块文件：每一个python源文件都可以是一个模块文件
   
   可以在一个python文件中定义函数 然后在另一个文件中使用 import 文件名导入
   
   导入这个模块 导入之后，就可以使用 模块名.变量/模块名.函数的方式， 使用这个模块中定义的函数

--------------------------------------------------------------------
# 第二部分

## 文件处理

   **基本步骤**

   通常，文件操作包含以下几个基本步骤：

   打开文件：使用 open() 函数打开指定的文件，获取文件对象。
   操作文件：对文件对象进行读取、写入等操作。
   关闭文件：使用 close() 方法关闭文件，释放系统资源
   
 **1. 打开文件**

   在 Python 中，使用 open() 函数来打开文件，其基本语法如下：

        file = open(file_path, mode)
   
   file_path：文件的路径，可以是相对路径或绝对路径。

   mode：文件的打开模式，常见的模式有：

   - ‘r’：只读模式，默认值。用于读取文件内容，如果文件不存在会抛出 FileNotFoundError 异常。
   - ‘w’：写入模式，用于创建新文件或覆盖原有文件内容。如果文件不存在，会创建新文件；如果文件已存在，会清空原有内容。
   - ‘a’：追加模式，用于在文件末尾追加内容。如果文件不存在，会创建新文件。
   - ‘b’：二进制模式，可与其他模式结合使用，如 ‘rb’ 表示以二进制只读模式打开文件。
   - ‘+’：读写模式，可与其他模式结合使用，如 ‘r+’ 表示以读写模式打开文件。

**2. 读取文件**

   打开文件后，可以使用以下方法读取文件内容：

   - read() 方法  
    读取整个文件内容，返回一个字符串

        # 以只读模式打开文件
         file = open('example.txt', 'r') 
        # 读取整个文件内容 
         content = file.read() print(content) 
        # 关闭文件 
         file.close()

   - readlines() 方法  
    读取文件中的所有行，返回一个包含每行内容的列表

        file = open('example.txt', 'r') 
        lines = file.readlines() 
        for line in lines: 
	        print(line) 
	    file.close()

**3. 写入文件**

   使用 write() 方法可以向文件中写入内容：

        # 以写入模式打开文件
         file = open('example.txt', 'w')
        # 写入内容 
         file.write('Hello, World!\n') 
         file.write('This is a test file.\n') 
        # 关闭文件 
         file.close()

   **在写入模式下，如果文件已存在，原有内容会被覆盖。如果需要追加内容，可以使用追加模式 ‘a’：**

        # 以追加模式打开文件
         file = open('example.txt', 'a') 
        # 追加内容 
         file.write('This is additional content.\n') 
        # 关闭文件 
         file.close()

**4. 使用with语句**

   为了避免忘记关闭文件，可以使用 with 语句，它会在代码块执行完毕后自动关闭文件：

        # 使用 with 语句打开文件 
         with open('example.txt', 'r') as file:
	         content = file.read() 
	         print(content) 
	    # 文件会自动关闭
## 模块、库、包

#### import 
   
   在讲这部分内容之前，需要先对import这个关键字进行阐述

   import是Python中用来导入模块、函数、类或变量的\[关键字]。它就像是一个“搬运工”，把其他地方的代码搬到你的程序中，让你不用重复造轮子。

   使用方法：

1. import  模块
2. from 模块 import 函数
3. import  模块 as xxx      (xxx是你可以随便取的绰号，跟C语言typedef一样)
4. from 模块 import \*     导入模块中的所有内容

#### 模块：文件级别的组织
   
   首先，Python的“模块”指的是一个文件，也就是 .py 结尾的那个文件。它就是一个 Python 文件，用来放代码的，功能就是组织代码，解决代码复用的问题。

   比如，写个简单的工具函数，想在其他项目里用，只需保存成 .py 文件，然后导入就行了。这就相当于“模块”了。

   示例：

```
   # 在tool.py文件中定义一个比较大小的函数
   
   def compare(a, b):
	   if a > b:
		   return a
	   elif(a == b):
		   return "equal"
	   else:
		   return b
```

```
   # 在main.py文件中调用这个函数
   
   import tool
   a = 3, b = 2
   result = tool.compare(a, b)       #注意格式，是文件名.函数
```

#### 库：成套的工具集合

   库呢，其实是多个模块的集合。也就是说，一个库往往由多个模块组成，是一组功能相关的模块集合。

   比如说 requests 这个库，它是用来做 HTTP 请求的，模块多得很，不止一个 requests.py。你要用这个库，通常会先**安装**（下文会讲到）它，然后用其中的功能。比如我们请求一个网页：

        import requests
        response = requests.get\('https://api.example.com/data')
        print(response.json())

#### 包：带有结构的文件夹

   那么包（Package）又是什么？简单说，包就是“带有 __init__.py 文件的文件夹”。听着简单？它确实也不复杂，但有了它，库里的模块组织就有层级结构了。包允许我们将模块分层组织，适合于大型项目或库。很多Python大厂库，比如Django和Flask，都是通过包的方式组织代码。

   假设我们想设计一个数据处理的库，包含文本处理、图像处理和音频处理模块。可以按以下方式创建包结构：

```
data_processing/
│
├── __init__.py      # 标记为包    #每个文件夹里都要有 `__init__.py` 文件。没有这个文                                   件，Python 就不知道该文件夹是包，会把它当成普通文件夹处理。 
├── text_processing/
│   ├── __init__.py   # 标记为包
│   └── text_utils.py
├── image_processing/
│   ├── __init__.py   # 标记为包
│   └── image_utils.py
└── audio_processing/
    ├── __init__.py   # 标记为包
    └── audio_utils.py
```

   有了这个结构，我们就可以方便地在外部导入子模块，比如：

```
   from data_processing.text_processing import text_utils
   from data_processing.image_processing import image_utils
```

   这里的 `__init__.py` 主要是告诉 Python：这是一整个“包”，这样就能让我们写的代码更整洁、组织得更有层次，尤其是在涉及到大量模块时，非常方便。

#### 安装

   有些模块是python自带的，类似于C语言中的头文件，直接include\<头文件名>即可，python中直接import + 模块即可，如随机数模块，时间戳模块

   但有些模块/库是python没有的，比如上文提到的requests库，我们要想导入它必须先将其安装到我们的python环境里

1. **基本安装命令**：pip install（或python -m pip install) + 模块/库

   使用方法：打开你的cmd/powershell/bash（也可以直接在vscode里按ctrl+~打开自带终端，然后输入pip install + 你需要的模块/库

2. **虚拟环境**

   很多时候，我们做这个项目需要这个库/模块，但做另外一个项目不需要，如果我们一股脑地全把模块/库安装在全局环境中，可能会发生：
   - 依赖冲突：不同的项目可能需要不同版本的同一个库。例如，一个项目可能需要Django 2.2，而另一个项目可能需要Django 3.0。在虚拟环境中，每个项目可以拥有自己独立的依赖，不会相互干扰。
    
   - 污染系统Python环境：如果直接在系统Python中安装各种包，可能会使得系统Python环境变得臃肿，并且可能导致包版本冲突。使用虚拟环境可以保持系统Python环境的干净。

   所以，我们会在每个项目目录下创建一个虚拟环境（venv）目录

   - **创建方法**

```
   # 在你的vscode项目终端下
   python -m venv .venv   # 创建虚拟环境，最后一个是环境名称（一般起名为.venv）
   
   .venv\Scripts\activate  # 激活虚拟环境
   
   deactivate      # 退出虚拟环境（如果你想的话）
```

--------------------------------------------------------------------
# 第三部分

## 类与对象

### 简单概念

- **类(class)**：
  类是创建对象的模板或蓝图，定义了对象的属性（成员变量）和行为（方法）。

  类就像一张设计图纸，比如“手机设计图”。图纸上规定了手机有哪些部分（属性）和功能（方法）。

- **对象(object)**

  通过类，你可以创建多个对象，每个对象都可以有不同的属性值和执行相同的操作。
  
  就像根据图纸制造出来的具体手机。比如，根据同一张图纸可以制造出很多部手机，它们都有相同的结构和功能，但每部手机都是独立的，可以有不同的颜色、不同的电量。

- **属性**（成员变量）

  定义类的特征，通常在类的构造方法 `__init__` 中初始化。

  就像手机的颜色、品牌、电量。在类中，我们通过***self.属性名**来定义和访问。

- **方法**（成员函数）

  定义类的行为，通常是类可以执行的操作。

  比如手机中的打电话、充电。在类中，方法就是函数，但第一个参数必须是self，这样方法才能访问这个对象的属性。

### 基本形式 

```
class Dog:
	# 初始化方法 (构造函数)
    def __init__(self, name, age):
        self.name = name   # 对象的属性
        self.age = age     # 对象的属性
 
    # 类的方法
    def bark(self):
        print(f"{self.name} says Woof!")
 
    # 创建一个 Dog 类的对象
	dog1 = Dog("Buddy", 5)
 
	# 访问对象的属性
	print(f"Dog's name is {dog1.name}, age is {dog1.age}")
 
	# 调用对象的方法
	dog1.bark()
```

**解释：**

   - \_\_init\_\_ 方法是类的构造函数，它在对象创建时被自动调用，用于初始化对象的属性。
   
   - self 是指向当前对象的引用，通过它你可以访问对象的属性和方法。

   - 在 dog1 = Dog("Buddy", 5) 这一行，创建了一个 Dog 类的对象，传入 name 和 age 属性。
   
   - dog1.bark() 调用了 Dog 类的方法 bark，输出 Buddy says Woof!。

### 内置方法

#### 构造方法

   构造方法：**__init__**(前后各两个英文下划线)
```
class Student :
	name = None
	age = None
	birth = None
	num = None
	
	def __init__(self, name, age, birth, num):
		self.name = name
		self.age = age
		self.birth = birth
		self.num = num

stu = Student("lxc", 18, "9月19日", "18326389857")
print(f"She is {stu.name}, a {stu.age}-year-old girl born on {stu.birth}, with a telnum {stu.num}.")
```
   这样我们在类外面用变量接收Student时，便可直接在括号中传入实参

#### 字符串方法

   在前文Student类的构造中，如果我们直接print(stu)，结果就是stu的内存地址
   
![[Pasted image 20251122195035.png]]
   
   如果我们想直接打印出Student中的内容的话，可以采取字符串方法，形式如下：
```
# 其他不变，只是在类中多加了这么两行
	def __str__(self):
		return f"She is {stu.name}, a {stu.age}-year-old girl born on {stu.birth}, with a telnum {stu.num}."
```
   此时我们直接打印stu，就会出现我们return的内容了

#### 其他内置方法

   形式都差不多，\_\_lt\_\_，\_\_le\_\_，\_\_eq\_\_

   感兴趣的可以自己去了解一下，在此不作过多赘述（实际上是我也记不住doge）

#### 测试

   在其他脚本导入我们写好的这个脚本前，往往要进行测试，看看这个模块运行是否正常

   方式：
```
# 在 my_script.py 里：
print("徐筱佩说：v我50")

if __name__ == "__main__":    # 在这句话之后的全部只能在这个模块内部运行，被其他文                                 件导入时不会运行
    print("张乐冉大声地吐槽了一句")
```

--------------------------------------------------------------------
                        ***未完待续***
