<?php

highlight_file(__FILE__);

class test{
    public $a = "helloa";
    private $b = "hellob";
    protected $c = "helloc";
}

$a = new test();

echo serialize($a);