//
//  MultiLineViewController.m
//  MyTestApp
//
//  Created by Wei Zhang on 2024/3/19.
//

#import "MultiLineViewController.h"
#import "ReviewViewController.h"

@interface MultiLineViewController ()


@end

@implementation MultiLineViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    
    [[NSNotificationCenter defaultCenter] addObserver:self 
                                             selector:@selector(userCenterClick:)
                                                 name:@"userCenterNotification" object:nil];
    
    
    UIButton *bBtn = [[UIButton alloc] initWithFrame:CGRectMake(100, 280, 80, 80)];
    bBtn.backgroundColor = [UIColor blueColor];
    [bBtn setTitle:@"标记2" forState:UIControlStateNormal];
    [self.view addSubview:bBtn];
    [bBtn addTarget:self action:@selector(buttonActionHitTestB:) forControlEvents:UIControlEventTouchUpInside];
    
    
}



- (void)userCenterClick:(NSNotification *)notifi {
    //主线程的部分
    NSLog(@"当前的线程打印：  %@ ", [NSThread currentThread]);
    dispatch_async(dispatch_get_main_queue(), ^{
        NSLog(@"是否可以在主线程队列中执行 %@ --  %@  ", [NSThread currentThread], notifi);
    });
}

- (void)buttonActionHitTestB:(UIButton *)aButtOn {
    ReviewViewController *vc = [[ReviewViewController alloc] init];
    [self.navigationController pushViewController:vc animated:YES];
}


@end
