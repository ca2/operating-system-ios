//
//  _c_mm.h
//  acme_macos
//
//  Created by Camilo Sasuke on 2021-05-11 11:19 BRT <3ThomasBS_!!
//

//
//  apple.h
//  acme
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 21/07/17.
//
//
#pragma once

// C and Objective-C include

#ifdef __OBJC__
#include "NSObject+DDExtensions.h"
#include "DDInvocationGrabber.h"

char * __strdup(NSString * str);

#endif


#ifdef MM

void copy(NSRect & rectangle, const INT_RECTANGLE * lpcrect);
void copy(INT_RECTANGLE * lprect, const NSRect & rectSrc);
void screen_coordinates_aware_copy(NSRect & rectangle, const INT_RECTANGLE * lpcrect);
void screen_coordinates_aware_copy(INT_RECTANGLE * lprect, const NSRect & rectSrc);

#endif


#include "graphics.h"
#include "ns_exception.h"
#include "time.h"

void ns_launch_app(const char * psz, const char ** argv, int iFlags);
bool ns_open_file(const char * psz);
void ns_main_post(dispatch_block_t block);

void apple_on_open_file(const char ** psza, int iCount, const char * pszExtra);
void apple_accumulate_on_open_file(const char ** psza, int iCount, const char * pszExtra);
void apple_on_new_file();


//void acme_application_main(int argc, char *argv[], const char * pszCommandLine);



int is_window(oswindow window);

void ns_main_send(dispatch_block_t block, unsigned int uiMillis = -1);
void ns_main_post(dispatch_block_t block);

