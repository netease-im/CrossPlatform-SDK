#import "NIMDispatch.h"

#pragma mark - IO 线程
//公用的IO读写同步线程
static const void * const NIMDispathIOQueueSpecificKey = "NIMSamplesDispathIOQueueSpecificKey";
dispatch_queue_t NIMDispathIOQueue()
{
    static dispatch_queue_t queue;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        queue = dispatch_queue_create("com.netease.samples.io", DISPATCH_QUEUE_SERIAL);
        dispatch_queue_set_specific(queue, NIMDispathIOQueueSpecificKey, (void *)NIMDispathIOQueueSpecificKey, NULL);
    });
    return queue;
}


void nim_io_async(dispatch_block_t block)
{
    dispatch_queue_t queue = NIMDispathIOQueue();
    dispatch_async(queue,^{
        @autoreleasepool {
            block();
        }
    });
}


void nim_io_sync_safe(dispatch_block_t block)
{
    if (dispatch_get_specific(NIMDispathIOQueueSpecificKey))
    {
        @autoreleasepool {
            block();
        }
    }
    else
    {
        dispatch_queue_t queue = NIMDispathIOQueue();
        dispatch_sync(queue,^{
            @autoreleasepool {
                block();
            }
        });
    }
}

#pragma mark - Queue Operation

void nim_main_sync(dispatch_block_t block){
    
    @autoreleasepool{
        if ([NSThread isMainThread]) {
            block();
        } else {
            dispatch_sync(dispatch_get_main_queue(), block);
        }
    }
}

void nim_main_async(dispatch_block_t block){
   
    @autoreleasepool{
        if ([NSThread isMainThread]) {
            block();
        } else {
            dispatch_async(dispatch_get_main_queue(), block);
        }
    }
}
