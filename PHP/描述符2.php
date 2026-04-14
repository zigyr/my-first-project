<?php
$a = "hello, world";

// 构造shell命令：把$a的内容用echo输出，并重定向到stderr（>&2）
$cmd = "echo '$a' >&2";

// 配置管道：stdout(1)用pipe，stderr(2)也用pipe（方便我们读取）
$descriptorspec = [
    0 => ["pipe", "r"],  // stdin
    1 => ["pipe", "w"],  // stdout
    2 => ["pipe", "w"]   // stderr
];

// 执行命令
$process = proc_open($cmd, $descriptorspec, $pipes);

// 读取stdout（正常输出，这里因为>&2，所以是空）
$stdout = stream_get_contents($pipes[1]);
// 读取stderr（错误输出，这里就是$a的内容）
$stderr = stream_get_contents($pipes[2]);

// 关闭管道和进程
fclose($pipes[0]);
fclose($pipes[1]);
fclose($pipes[2]);
proc_close($process);

// 输出结果
echo "【stdout 内容】: " . $stdout . PHP_EOL;
echo "【stderr 内容】: " . $stderr . PHP_EOL;