//
//  NIMDispatch.h
//  NIM
//
//  Created by dudu on 2018/9/7.
//
#ifndef NIM_Eab_Dispatch_h
#define NIM_Eab_Dispatch_h

#import <Foundation/Foundation.h>

typedef BOOL(^nim_io_trans_block)(void);
#ifdef __cplusplus
extern "C" {
#endif
    
    @class NIMDatabase;
#pragma mark - IO 队列
    
    void nim_io_async(dispatch_block_t block);
    
    void nim_io_sync_safe(dispatch_block_t block);
        
#pragma mark - Queue Operation

    void nim_main_sync(dispatch_block_t block);

    void nim_main_async(dispatch_block_t block);

#ifdef __cplusplus
}
#endif
#endif
