#### 匹配括号(){}[]的顺序
1. {}() 返回 true
2. {()}[] 返回 true
3. [{]} 返回 false
4. )( 返回 false


##### 运行配置      
IDE： codeblocks
环境: windows   
配置codeblocks 中文显示：   
    1. Settings->Editor->General settings->Encoding settings -> Use encoding...UTF-8    
    2. Settings->Compiler->Global compiler settings -> Compiler settings -> Other compiler options :添加如下：  
        -finput-charset=UTF-8   
        -fexec-charset=GBK  

