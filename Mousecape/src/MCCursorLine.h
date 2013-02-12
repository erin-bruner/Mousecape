//
//  MCCursorLine.h
//  Mousecape
//
//  Created by Alex Zielenski on 2/8/13.
//  Copyright (c) 2013 Alex Zielenski. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MCCursor.h"

@class MCCursorLine;
@protocol MCCursorLineDataSource <NSObject>

@required
- (NSUInteger)numberOfCursorsInLine:(MCCursorLine *)cursorLine;
- (MCCursor *)cursorLine:(MCCursorLine *)cursorLine cursorAtIndex:(NSUInteger)index;

@end

@interface MCCursorLine : NSView
@property (assign) CGFloat wellWidth;
@property (assign) BOOL    shouldAllowSelection;
@property (copy)   NSColor *highlightColor;
@property (assign) id <MCCursorLineDataSource> dataSource;
@property (assign) NSUInteger selectionKeyMask;
- (void)reloadData;
@end