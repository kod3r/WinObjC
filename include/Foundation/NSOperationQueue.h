/*
Original Author: Michael Ash on 11/9/08
Copyright (c) 2008 Rogue Amoeba Software LLC

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/
#ifndef _NSOPERATIONQUEUE_H_
#define _NSOPERATIONQUEUE_H_

#import <Foundation/NSObject.h>

@class NSArray,NSMutableArray,NSOperation,NSCondition,NSThread;

enum {
    NSOperationQueueDefaultMaxConcurrentOperationCount = -1
};

enum {
    NSOperationQueuePriority_Count = 3
};

struct NSOperationQueuePriv;
FOUNDATION_EXPORT_CLASS
@interface NSOperationQueue : NSObject {
    struct NSOperationQueuePriv *priv;
}
- (id)init;

#pragma mark Managing Operations in the Queue

- (void)addOperation: (NSOperation *)op;

- (void)addOperations:(NSArray *)ops waitUntilFinished:(BOOL)wait;

- (NSArray *)operations;

- (NSUInteger)operationCount;

- (void)cancelAllOperations;

- (void)waitUntilAllOperationsAreFinished;

#pragma mark Managing the Number of Running Operations

- (NSInteger)maxConcurrentOperationCount;
- (void)setMaxConcurrentOperationCount:(NSInteger)count;

#pragma mark Managing the Queue Name

- (NSString *)name;
- (void)setName:(NSString *)newName;

#pragma mark Suspending Operations

- (BOOL)isSuspended;
- (void)setSuspended:(BOOL)suspend;

#pragma mark Getting Specific Operation Queues

+ (id)currentQueue;
+ (id)mainQueue;

- (void)addOperationWithBlock:(void (^)(void))block;

@end

#endif /* _NSOPERATIONQUEUE_H_ */