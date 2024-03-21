//
//  ViewController.m
//  MyTestApp
//
//  Created by Wei Zhang on 2023/8/10.
//

#import "ViewController.h"
#import <objc/runtime.h>

#import "ReviewViewController.h"

#import "MultiLineViewController.h"


@interface Father : NSObject

@end

@implementation Father

@end

@interface  Son : Father

@end

@implementation Son

- (id)init{
    self = [super init];
    if (self) {
        NSLog(@"%@", NSStringFromClass([self class]));
        NSLog(@"%@", NSStringFromClass([super class]));
    }
    return self;
}
@end



@interface AnotherClass : NSObject
@end

@implementation AnotherClass

- (void)myFallbackMethod {
    NSLog(@"Fallback method invoked in AnotherClass!");
}

@end

@interface MyClass : NSObject

@end

@implementation MyClass

// 第一阶段：动态方法解析
+ (BOOL)resolveInstanceMethod:(SEL)sel {
    if (sel == @selector(myDynamicMethod)) {
        class_addMethod([self class], sel, (IMP)dynamicMethodIMP, "v@:");
        return YES;
    }
    return [super resolveInstanceMethod:sel];
}

void dynamicMethodIMP(id self, SEL _cmd) {
    NSLog(@"Dynamic method resolved and invoked!");
}

// 第二阶段：备用接收者
- (id)forwardingTargetForSelector:(SEL)aSelector {
    if (aSelector == @selector(myFallbackMethod)) {
        return [AnotherClass new];
    }
    return [super forwardingTargetForSelector:aSelector];
}

// 第三阶段：完整消息转发
- (void)forwardInvocation:(NSInvocation *)anInvocation {
    SEL selector = [anInvocation selector];
    if ([[AnotherClass new] respondsToSelector:selector]) {
        [anInvocation invokeWithTarget:[AnotherClass new]];
    } else {
        [super forwardInvocation:anInvocation];
    }
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector {
    if (aSelector == @selector(nonExistentMethod)) {
        //如果这里是nil，就报错
        return [NSMethodSignature signatureWithObjCTypes:"i20@0:8i16"];
    }
    return [super methodSignatureForSelector:aSelector];
}

@end



@interface Person : NSObject<NSCopying,NSMutableCopying>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSArray *nameArray;

@end

@implementation Person

- (id)copyWithZone:(nullable NSZone *)zone {
    Person *p = [[Person allocWithZone:zone] init];
    p.name = [self.name copy];
    p.nameArray = [self.nameArray copy];
    return p;
}

- (id)mutableCopyWithZone:(NSZone *)zone {
    Person *p = [[Person allocWithZone:zone] init];
    p.name = [self.name mutableCopy];
    p.nameArray = [self.nameArray mutableCopy];
    return p;
}

- (void)dealloc {
    NSLog(@"Person dealloc....");
}

@end


typedef void (^TestDoWorkBlock)(void);

@interface ViewController ()

@property (nonatomic, copy) NSString *aString;

@property (nonatomic, weak) Person *person;


@property (nonatomic, copy) TestDoWorkBlock doWork;


@end

@implementation ViewController


- (id)valueForUndefinedKey:(NSString *)key {
    return nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
//    Son *son = [[Son alloc] init];
    
    UIButton *abtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 100, 80, 80)];
    abtn.backgroundColor = [UIColor redColor];
    [abtn setTitle:@"标记1" forState:UIControlStateNormal];
    [self.view addSubview:abtn];
    [abtn addTarget:self action:@selector(buttonActionHitTestA:) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *bBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 280, 80, 80)];
    bBtn.backgroundColor = [UIColor blueColor];
    [bBtn setTitle:@"标记2" forState:UIControlStateNormal];
    [self.view addSubview:bBtn];
    [bBtn addTarget:self action:@selector(buttonActionHitTestB:) forControlEvents:UIControlEventTouchUpInside];
    
}


- (void)buttonActionHitTestA:(UIButton *)aButtOn {
    //关于测试的HitTest的
    dispatch_queue_t queue = dispatch_queue_create(@"com.button.action", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(queue, ^{
        NSLog(@"立即派发通知的线程打印：%@ ", [NSThread currentThread]);
        [NSNotificationCenter.defaultCenter postNotificationName:@"userCenterNotification" object:nil];
    });
}

- (void)buttonActionHitTestB:(UIButton *)aButtOn {
    MultiLineViewController *vc = [[MultiLineViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}


-(void)tets1 {
    //    NSString *testValueKey = [self valueForKey:@"haotiantest"];
    //
    //    NSLog(@" %@", testValueKey);
    //
        
    //    UIButton *button = [[UIButton alloc] initWithFrame:CGRectMake(100, 200, 200, 200)];
    //    [self.view addSubview:button];
    //    button.backgroundColor = [UIColor blueColor];
    //    [button addTarget:self action:@selector(buttonAction:) forControlEvents:UIControlEventTouchUpInside];
        
        
    //    Person *p = [Person new];
    //    p.name = @"yida";
        
        
    //    [p addObserver:[TimeProxy callWithTarget:self] forKeyPath:@"name" options:NSKeyValueObservingOptionNew context:nil];
    //    [p addObserver:[TimeProxy callWithTarget:self] forKeyPath:@"name" options:NSKeyValueObservingOptionNew context:nil];
    //    p.name = @"haotian";
        
    //    Person *p1 = [[Person alloc] init];
    //    NSMutableArray *list = [NSMutableArray arrayWithObjects:@"name1",@"name2", nil];
    //    p1.nameArray = list;
    //
    //    Person *p2 = [p1 copy];
    //    [list addObject:@"name3"];
    //
    //    Person *p3 = [p1 mutableCopy];
    //    [list addObject:@"name4"];
    //
    //    NSLog(@"p1=%p ;;;;   p2=%p ;;;;;   p3=%p", p1, p2, p3 );
    //
    //    NSLog(@"p1.name=%@ ;;;;   p2.name=%@ ;;;;;   p3.name=%@", p1.nameArray, p2.nameArray, p3.nameArray );
        
        
    //    NSMutableArray *originalArray = [NSMutableArray arrayWithObjects:@1, @2, @3, nil];
    //    NSMutableArray *copiedArray = [originalArray mutableCopy];
    //
    //    // 修改原始数组中的元素
    //    [originalArray replaceObjectAtIndex:0 withObject:@4];
    //
    //    // 输出原始数组和副本数组
    //    NSLog(@"Original Array: %@", originalArray);
    //    NSLog(@"Copied Array: %@", copiedArray);

    //    NSString *key1 = @"thisishaotian";
    //    self.aString = key1;
    //
    //    NSLog(@"begin: %p---after: %p", key1, self.aString);
    //
    //    key1 = @"hell yida";
    ////
    //    NSLog(@"打印变量的地址  %p, %p", self.aString, key1);
    //
    //    self.aString = @"hello yida2";
    //
    //    NSLog(@"打印变量的地址  %p, %p", self.aString, key1);
        
    //    NSString *aString = @"Hello World";
    //    NSString *copyString = [aString copy];
    //    NSMutableString *mutableString =  [aString mutableCopy];
    //
    //    NSLog(@"origin: %p  copy:%p  mutable: %p", aString,  copyString,   mutableString);
        
        
    //    self.person  = [[Person alloc] init];
    //    self.person.name = @"yida";
    //
    //    NSString *name = [self valueForKeyPath:@"person.name"];
    //
    //    NSLog(@".....%@....", name);
        

    //    __weak Person *weakPerson ;
    //
    //    {
    //
    //        Person *ppp = [[Person alloc]  init];
    //        ppp.name = @"yida";
    //
    //        __weak typeof(ppp) weakP = ppp;
    //        [weakP addObserver:self forKeyPath:@"name" options:NSKeyValueObservingOptionNew context:nil];
    //        weakP.name = @"222";
    //
    //        weakPerson = weakP;
    //
    //    }
    //
    //    weakPerson.name = @"cccc";
    //
    //    [weakPerson removeObserver:self forKeyPath:@"name"];
        
    //    Person *weakPerson = [[Person alloc] init];
        
    //    __weak  typeof(Person) *person = weakPerson;
    //    __block int a = 1;
    //    self.doWork = ^{
    //        a = 2;
    //    };
    //
    //    NSLog(@"测试Block的堆栈信息   %@ ", self.doWork);
        
    //    [self testBlock];
        
        NSMutableString *mmcc = [[NSMutableString alloc] initWithString:@"kaixin"];
        
        self.aString = mmcc;
        
        [mmcc appendString:@"CCCCCC"];
        
        NSLog(@"%@ - %@ ", self.aString,  mmcc);
}


- (void)testBlock {
//    
//    __weak typeof(self) __weakSelf = self;
    
//    int a =  2122121;
//    __strong void (^ StrongBlock)(void ) = ^(void) {
//        NSLog(@"dededede  %ld", a);
//    };
//    NSLog(@"%@", StrongBlock);
    
}




- (void)tests {
    // Do any additional setup after loading the view.
    

//    MyClass *obj = [MyClass new];
            
    // 第一阶段：动态方法解析
//    [obj performSelector:@selector(myDynamicMethod)];
    
    // 第二阶段：备用接收者
//    [obj performSelector:@selector(myFallbackMethod)];
    
    // 第三阶段：完整消息转发
//    [obj performSelector:@selector(nonExistentMethod)];
    
}


@end
