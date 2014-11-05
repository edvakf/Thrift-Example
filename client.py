#!/usr/bin/env python

import sys
sys.path.append('gen-py/my/example/')
import ArithmeticService
import ttypes
from ttypes import *
from thrift import Thrift
from thrift.transport import TTransport
from thrift.transport import THttpClient
from thrift.protocol import TJSONProtocol

host = "localhost"
port = "7890"
uri = "/api.php"

transport = THttpClient.THttpClient(host, port, uri)
transport = TTransport.TBufferedTransport(transport)
protocol = TJSONProtocol.TJSONProtocol(transport)

client = ArithmeticService.Client(protocol)

transport.open()

e = client.add(
    Complex(real = 2, imaginary = 3),
    Complex(real = 4, imaginary = 5))

print(e)

transport.close()



