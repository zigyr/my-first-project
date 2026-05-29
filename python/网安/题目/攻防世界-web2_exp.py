"""
<?php
$miwen="a1zLbgQsCESEIqRLwuQAyMwLyq2L5VwBxqGA3RQAyumZ0tmMvSGM2ZwB4tws";

function encode($str){
    $_o=strrev($str);
    // echo $_o;
        
    for($_0=0;$_0<strlen($_o);$_0++){
       
        $_c=substr($_o,$_0,1);
        $__=ord($_c)+1;
        $_c=chr($__);
        $_=$_.$_c;   
    } 
    return str_rot13(strrev(base64_encode($_)));
}

highlight_file(__FILE__);
/*
   逆向加密算法，解密$miwen就是flag
*/
?> 
"""
import codecs
import base64

miwen="a1zLbgQsCESEIqRLwuQAyMwLyq2L5VwBxqGA3RQAyumZ0tmMvSGM2ZwB4tws" 

def str_rot13(str):
    return codecs.encode(str, 'rot_13')

def strrev(str):
    return str[::-1]

ss = base64.b64decode(strrev(str_rot13(miwen))).decode('utf-8')

code = ''.join(chr(ord(s)-1) for s in ss)
    
print(strrev(code))

