//
//  nswindow.h
//  acme
//
//  Created by Camilo Sasuke Thomas Borregaard Soerensen on 02/02/22.
//  Copyright (c) 2022 Camilo Sasuke Thomas Borregaard Soerensen. All rights reserved.
//
#pragma once


#include <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include <CoreGraphics/CoreGraphics.h>

class acme_window_bridge;
@class ns_acme_impact;


@interface ns_acme_window : UIWindow
{
@public
   
   acme_window_bridge *       m_pacmewindowbridge;
   ns_acme_impact *           m_pnsacmeimpact;
   //NSWindowController *       m_pwindowcontroller;

}
-(instancetype) init: (CGRect) rectangle with_acme_window_bridge:(acme_window_bridge * )pacmewindowbridge;

@end
 
