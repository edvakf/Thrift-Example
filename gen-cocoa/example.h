/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#import <Foundation/Foundation.h>

#import "TProtocol.h"
#import "TApplicationException.h"
#import "TProtocolException.h"
#import "TProtocolUtil.h"
#import "TProcessor.h"
#import "TObjective-C.h"
#import "TBase.h"


typedef int64_t int;

@interface Complex : NSObject <TBase, NSCoding> {
  int __real;
  int __imaginary;

  BOOL __real_isset;
  BOOL __imaginary_isset;
}

#if TARGET_OS_IPHONE || (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@property (nonatomic, getter=real, setter=setReal:) int real;
@property (nonatomic, getter=imaginary, setter=setImaginary:) int imaginary;
#endif

- (id) init;
- (id) initWithReal: (int) real imaginary: (int) imaginary;

- (void) read: (id <TProtocol>) inProtocol;
- (void) write: (id <TProtocol>) outProtocol;

- (void) validate;

#if !__has_feature(objc_arc)
- (int) real;
- (void) setReal: (int) real;
#endif
- (BOOL) realIsSet;

#if !__has_feature(objc_arc)
- (int) imaginary;
- (void) setImaginary: (int) imaginary;
#endif
- (BOOL) imaginaryIsSet;

@end

@interface ZeroDivisionException : NSException <TBase, NSCoding> {
}

- (id) init;

- (void) read: (id <TProtocol>) inProtocol;
- (void) write: (id <TProtocol>) outProtocol;

- (void) validate;

@end

@protocol ArithmeticService <NSObject>
- (Complex *) add: (Complex *) i1 i2: (Complex *) i2;  // throws TException
- (Complex *) subtract: (Complex *) i1 i2: (Complex *) i2;  // throws TException
- (Complex *) multiply: (Complex *) i1 i2: (Complex *) i2;  // throws TException
- (Complex *) divide: (Complex *) i1 i2: (Complex *) i2;  // throws ZeroDivisionException *, TException
@end

@interface ArithmeticServiceClient : NSObject <ArithmeticService> {
  id <TProtocol> inProtocol;
  id <TProtocol> outProtocol;
}
- (id) initWithProtocol: (id <TProtocol>) protocol;
- (id) initWithInProtocol: (id <TProtocol>) inProtocol outProtocol: (id <TProtocol>) outProtocol;
@end

@interface ArithmeticServiceProcessor : NSObject <TProcessor> {
  id <ArithmeticService> mService;
  NSDictionary * mMethodMap;
}
- (id) initWithArithmeticService: (id <ArithmeticService>) service;
- (id<ArithmeticService>) service;
@end

@interface exampleConstants : NSObject {
}
@end
