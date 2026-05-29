```php

<?php

header('Content-Type: text/plain; charset=UTF-8');

if (!isset($_GET['user'], $_GET['token'], $_GET['sig'], $_GET['ts'], $_GET['nonce'])) {
    readfile(__FILE__);
    exit;
}

$user   = (string)$_GET['user'];
$token  = (string)$_GET['token'];
$sig    = (string)$_GET['sig'];
$ts     = (int)$_GET['ts'];
$nonce  = (string)$_GET['nonce'];

# `PHP 的 NULL 合并运算符`
# 如果前面的值不存在 / 为空，就用后面的默认值

# `X-Forwarded-For`
# 是 HTTP 请求头，用来携带真实客户端 IP
# `::1` 是 IPv6 版本的本地回环地址
$xff = $_SERVER['HTTP_X_FORWARDED_FOR'] ?? '';
# 只有当 127.0.0.1 和 ::1 两个都找不到的时候，才会拦你
if (strpos($xff, '127.0.0.1') === false && strpos($xff, '::1') === false) {
    exit('hacker!');
}

# 前者判断`能不能正常Base64解码`
# 后者判断`字符是不是标准Base64字符`
if (base64_decode($nonce) === false || !preg_match('/^[A-Za-z0-9+\/=]+$/', $nonce)) {
    exit('hacker!!');
}

# 传的 ts 必须是`最近 60 秒内的时间`
if (time() - $ts <= 60) {
    // ok
} else {
    exit('expired!');
}

# 
if (strpos($user, 'admin') == false) {

    $key = $_COOKIE['authkey'] ?? 'NULL';
    $mac = hash_hmac('md5', $user . $token . $ts, $key);

    if (substr($mac, 0, 6) == substr($sig, 0, 6)) {

        $stored_hash = '0e830400451993494058024219903391'; 
        if (md5($token) == $stored_hash) {
            @readfile('/flag');
        } else {
            exit('hacker!!!');
        }

    } else {
        exit('hacker!!!!');
    }

} else {
    exit('blocked user');
}
```