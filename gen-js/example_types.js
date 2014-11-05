//
// Autogenerated by Thrift Compiler (0.9.1)
//
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
//


Complex = function(args) {
  this.real = null;
  this.imaginary = null;
  if (args) {
    if (args.real !== undefined) {
      this.real = args.real;
    }
    if (args.imaginary !== undefined) {
      this.imaginary = args.imaginary;
    }
  }
};
Complex.prototype = {};
Complex.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
      if (ftype == Thrift.Type.I64) {
        this.real = input.readI64().value;
      } else {
        input.skip(ftype);
      }
      break;
      case 2:
      if (ftype == Thrift.Type.I64) {
        this.imaginary = input.readI64().value;
      } else {
        input.skip(ftype);
      }
      break;
      default:
        input.skip(ftype);
    }
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

Complex.prototype.write = function(output) {
  output.writeStructBegin('Complex');
  if (this.real !== null && this.real !== undefined) {
    output.writeFieldBegin('real', Thrift.Type.I64, 1);
    output.writeI64(this.real);
    output.writeFieldEnd();
  }
  if (this.imaginary !== null && this.imaginary !== undefined) {
    output.writeFieldBegin('imaginary', Thrift.Type.I64, 2);
    output.writeI64(this.imaginary);
    output.writeFieldEnd();
  }
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

ZeroDivisionException = function(args) {
};
Thrift.inherits(ZeroDivisionException, Thrift.TException);
ZeroDivisionException.prototype.name = 'ZeroDivisionException';
ZeroDivisionException.prototype.read = function(input) {
  input.readStructBegin();
  while (true)
  {
    var ret = input.readFieldBegin();
    var fname = ret.fname;
    var ftype = ret.ftype;
    var fid = ret.fid;
    if (ftype == Thrift.Type.STOP) {
      break;
    }
    input.skip(ftype);
    input.readFieldEnd();
  }
  input.readStructEnd();
  return;
};

ZeroDivisionException.prototype.write = function(output) {
  output.writeStructBegin('ZeroDivisionException');
  output.writeFieldStop();
  output.writeStructEnd();
  return;
};

