<?php

require __DIR__.'/vendor/autoload.php';
require __DIR__.'/gen-php/My/Example/Types.php';
require __DIR__.'/gen-php/My/Example/ArithmeticService.php';

use Thrift\Transport\TBufferedTransport;
use Thrift\Transport\TPhpStream;
use Thrift\Protocol\TJsonProtocol;

class ArithmeticServiceImpl implements \My\Example\ArithmeticServiceIf
{
    public function add(\My\Example\Complex $i1, \My\Example\Complex $i2)
    {
        return new \My\Example\Complex([
            'real' => $i1->real + $i2->real,
            'imaginary' => $i1->imaginary + $i2->imaginary,
        ]);
    }

    public function subtract(\My\Example\Complex $i1, \My\Example\Complex $i2)
    {
        return new \My\Example\Complex([
            'real' => $i1->real - $i2->real,
            'imaginary' => $i1->imaginary - $i2->imaginary,
        ]);
    }

    public function multiply(\My\Example\Complex $i1, \My\Example\Complex $i2)
    {
        return new \My\Example\Complex([
            'real' => $i1->real * $i2->real - $i1->imaginary * $i2->imaginary,
            'imaginary' => $i2->real * $i1->imaginary + $i1->real * $i2->imaginary,
        ]);
    }

    public function divide(\My\Example\Complex $i1, \My\Example\Complex $i2)
    {
        $i2_length_squaread = $i2->real * $i2->real + $i2->imaginary * $i2->imaginary;
        if ($i2_length_squaread == 0) {
            throw new \My\Example\ZeroDivisionException();
        }
        return new \My\Example\Complex([
            'real' => ($i1->real * $i2->real + $i1->imaginary * $i2->imaginary) / $i2_length_squaread,
            'imaginary' => ($i1->imaginary * $i2->real - $i1->real * $i2->imaginary) / $i2_length_squaread,
        ]);
    }
}


header('Content-Type: application/x-thrift');

$handler   = new ArithmeticServiceImpl();
$processor = new \My\Example\ArithmeticServiceProcessor($handler);

$transport = new TBufferedTransport(new TPhpStream(TPhpStream::MODE_R | TPhpStream::MODE_W));

$protocol = new TJsonProtocol($transport, true, true);

$transport->open();
$processor->process($protocol, $protocol);
$transport->close();


