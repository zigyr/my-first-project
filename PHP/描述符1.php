<?php
$a = "hello, world";

// 1. 正常输出到 stdout（标准输出，终端默认白色）
echo "【stdout 正常输出】: " . $a . PHP_EOL;

// 2. 输出到 stderr（标准错误，终端默认红色/高亮）
// 方式1：直接写STDERR（推荐）
fwrite(STDERR, "【stderr 错误输出】: " . $a . PHP_EOL);

// 方式2：用error_log（自动写stderr）
// error_log("【stderr 错误输出】: " . $a);