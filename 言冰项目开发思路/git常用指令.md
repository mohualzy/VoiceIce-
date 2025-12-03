
# 创建

1. **mkdir**
   - 创建一个目录

2. **touch**
   - 创建一个文件
# 编辑

1. **echo**
   - echo “xxx” 文件名 ——在文件里加上这句话（若没有这个文件就会自动新建一个）

2. **vim/vi**
   - 用vim编辑器对文件内容进行编辑
   - i键进入编辑模式，编辑完毕按下Esc + :wq 退出vim模式

# 查看

1. **cd**
   - 切换目录
   - cd .. ：回退目录

2. **ls**
   - 查看当前目录的文件和子目录
   - ls-a ：显示包括隐藏文件
   - ls-l  ：以长格式显示文件
   - git ls-files : 列出追踪（tracked）文件

3. **git status
   - 查看工作区和暂存区文件的状态（tracked/untracked，add，commit……)

4. **git diff**
   - 查看修改前后的差异

# 暂存

**git add**
- git add . 提交当前目录下所有已修改或未追踪的文件到暂存区
- git add \*+后缀名 对所有拥有此后缀的文件进行操作 

# 提交

**git commit**


# 删除
