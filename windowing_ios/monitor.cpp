//
//  monitor.cpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 27/05/21 19:48 BRT <3ThomasBS_!!
//
#include "framework.h"
#include "monitor.h"


void ns_monitor_cgrect(int i, CGRect * p);
void ns_workspace_cgrect(int i, CGRect * p);


namespace windowing_ios
{


   monitor::monitor()
   {

      //m_pMonitor2 = this;
   
   }


   monitor::~monitor()
   {
      

   }


   void monitor::get_monitor_rectangle(::RECTANGLE_I32 * prectangle)
   {
      
      CGRect r;
      
      ns_monitor_cgrect((int) m_iIndex, &r);
      
      __copy(prectangle, r);
      
      //return ::success;
      
   }


   void monitor::get_workspace_rectangle(::RECTANGLE_I32 * prectangle)
   {
      
      CGRect rectWorkspace;
      
      ns_workspace_cgrect((int) m_iIndex, &rectWorkspace);
      
      __copy(prectangle, rectWorkspace);
      
      //return ::success;
      
   }


} // namespace windowing_ios





void ns_main_monitor_cgrect(CGRect * p);



RECTANGLE_I32 get_main_screen_rectangle()
{

   RECTANGLE_I32 rectangle{};
   
   CGRect r;
   
   ns_main_monitor_cgrect(&r);
   
   screen_coordinates_aware_copy(rectangle, r);

   return rectangle;
   
   //return true;
   
}
