//
//  display.hpp
//  windowing_ios
//
//  Created by Camilo Sasuke on 27/05/21 19:43 BRT <3ThomasBS_!!
//  From windowing_macos on 2022-05-11 02:13 <3ThomasBorregaardSorensen!!
//
#pragma once


#include "aura/windowing/display.h"


namespace windowing_ios
{


   class CLASS_DECL_WINDOWING_MACOS display :
      virtual public ::windowing::display
   {
   public:
      
   
      display();
      ~display() override;

      
      ::raw::count get_monitor_count() override;
      
      
      ::point_i32 _get_mouse_cursor_position() override;
   
   };



} // namespace windowing_ios



