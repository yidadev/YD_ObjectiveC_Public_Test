//
//  ReviewViewController.m
//  MyTestApp
//
//  Created by Wei Zhang on 2024/3/19.
//

#import "ReviewViewController.h"

@interface Node : NSObject

@property (nonatomic, strong) Node *next;
@property (nonatomic, assign) NSInteger value;

@end


@implementation Node


@end



@interface ReviewViewController ()

@end

@implementation ReviewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
//    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(centerClick:) name:@"SayHello" object:self];
    
//    [[NSNotificationCenter defaultCenter] postNotificationName:@"SayHello" object:nil];
    
    NSString *a1 = [NSString stringWithFormat:@"aaaa"];
    NSString *a2 = @"hello world";
    NSString *a3 = [NSString stringWithFormat:@"hello world  aaaaaa"];
    
    NSLog(@"-----  %@", a1.class);
    NSLog(@"-----  %@", a2.class);
    NSLog(@"-----  %@", a3.class);
    
    
    NSArray *arr1 = [NSArray arrayWithObject:@"1"];
    NSArray *arr2 = @[];
    NSArray *arr3 = [NSArray arrayWithObjects:@"1",@"2", nil];
    NSMutableArray *arr4 = [NSMutableArray arrayWithObjects:@"2",@"3",@"4", nil];
    
    NSLog(@"------  %@ ", arr1.class);
    NSLog(@"------  %@ ", arr2.class);
    NSLog(@"------  %@ ", arr3.class);
    NSLog(@"------  %@ ", arr4.class);
    
    
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

- (void)printNode:(Node *)node {
    while (node) {
        NSLog(@"%-ld",node.value);
        node = node.next;
    }
    
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
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
