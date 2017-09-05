//
//  SignalCache.h
//  SNReference
//
//  Created by Jonathan Glanz on 1/15/12.
//  Copyright (c) 2012 Signal360 All rights reserved.
//

#import <Foundation/Foundation.h>

@class SignalCache;
@class SignalCacheDownloader;

@protocol SignalCacheDownloaderDelegate <NSObject>

@optional
- (void) signalCacheDownloader: (SignalCacheDownloader *)downloader withSuccess: (BOOL) success;
@end

@interface SignalCache : NSObject

//Used to statically reference the cache and contents
+ (BOOL) directoryExistsAtPath: (NSString *) path;
+ (SignalCache *)sharedInstance;
+ (BOOL) isArchiveURL: (NSURL *) url;
+ (NSString *) archivePath: (NSString *) localPath;
+ (NSString *) archiveIndexPath:(NSString *)localPath;
+ (BOOL) supportsCachingURL: (NSURL *) url;

//Retrieve a content path, if one does not exist then go download it!
- (NSString *) contentPathForURL: (NSURL *) url withDelegate: (id<SignalCacheDownloaderDelegate>) delegate;

- (NSString *) contentPathForURL: (NSURL *) url withData: (NSData *) data withDelegate: (id<SignalCacheDownloaderDelegate>) delegate;

//Manage the cache state
- (void) clear;
- (void) persist;

//Used to create new cache filenames
- (NSString *) newCachedFilenameFromURL:(NSURL *) url;

//Used for delegate callbacks when a download completes
- (void) notifyDelegatesDownloader: (SignalCacheDownloader *) downloader completedWithSuccess: (BOOL) success;


@end


@interface SignalCacheDownloader : NSObject

- (id) initWithURL: (NSURL *) url andLocalPath: (NSString *) localPath andData:(NSData*)data;

@property (nonatomic, retain) NSURL * url;
@property (nonatomic, retain) NSString * localPath;

@end