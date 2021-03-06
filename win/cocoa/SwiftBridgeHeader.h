//
//  SwiftBridgeHeader.h
//  NetHackCocoa
//
//  Created by C.W. Betts on 8/9/15.
//
//

#ifndef SwiftBridgeHeader_h
#define SwiftBridgeHeader_h

#define NHSTDC

#import <objc/objc.h>
#include "hack.h"
#include "Inventory.h"

extern struct window_procs cocoa_procs;

extern void (*decgraphics_mode_callback)(void);

static inline BOOL Swift_Invis() {
	return ((HInvis || EInvis || \
			 pm_invisible(youmonst.data)) && !BInvis);
}

#import "NotesWindowController.h"
#import "MessageWindowController.h"
#import "NhEventQueue.h"
#import "NhCommand.h"

#import "NSString+NetHack.h"
#import "NSString+Z.h"

#import "NhWindow.h"

static inline void Swift_panic(const char* str) NORETURN;
static inline void Swift_panic(const char* str)
{
	panic("%s", str);
}

static inline int SwiftObjToGlyph(struct obj *object)
{
	return obj_to_glyph(object);
}

static inline int glyphToTile(int glyph)
{
	extern short glyph2tile[];
	return glyph2tile[glyph];
}

#endif /* SwiftBridgeHeader_h */
