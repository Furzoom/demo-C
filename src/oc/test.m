#import <Foundation/Foundation.h>

int main(void)
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    NSLog(@"Hello, Objective-C");
    unichar c = u'加';
    NSLog(@"The character is: %C", c);
    [pool drain];
    return 0;
}
