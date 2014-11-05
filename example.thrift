namespace java my.example
namespace py my.example
namespace php My.Example

typedef i64 int

struct Complex {
  1: int real,
  2: int imaginary,
}

service ArithmeticService
{
  Complex add(1:Complex i1, 2:Complex i2),
  Complex subtract(1:Complex i1, 2:Complex i2),
  Complex multiply(1:Complex i1, 2:Complex i2),
  Complex divide(1:Complex i1, 2:Complex i2),
}


