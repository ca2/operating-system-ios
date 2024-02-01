//
//  node.cpp
//  node_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/Oct/22 09:24
//
#include "framework.h"
#include "node.h"
#include "aura/platform/session.h"
#include "aura/platform/system.h"
#include "aura/user/user/user.h"
#include "aura/windowing/windowing.h"
#include "windowing_ios/message_box.h"


void ui_application_main(int argc, char * argv[], const char * pszCommandLine);


namespace node_ios
{


node::node()
{
   
   
}


node::~node()
{
   
   
}



void node::_will_finish_launching()
{
   
   auto psystem = system()->m_paurasystem;

   if(::is_null(psystem->m_htask))
   {

      auto estatus = psystem->branch();

      if(!estatus)
      {

         //return estatus;
         return;

      }

      // release the initial allocation from platform_create_system as
      // task::begin_synch holds a reference to the running system task.
      //psystem->release();

   }
      

   //return ::success;
   
}


void node::on_start_system()
{
   
   auto psystem = system();
//   
//   auto psession = psystem->m_pacmesession->m_paurasession;
//   
//   auto puser = psession->m_puser;
//   
//   auto pwindowing = puser->windowing();
//   
//   pwindowing->defer_initialize_host_window(nullptr);
   
   psystem->defer_post_initial_request();

   
}

//   bool node::is_keyboard_hook_enabled(::user::interaction * puserinteractionEnablePrompt)
//   {
//
//      auto estatus = ::keyboard_hook::is_enabled(false);
//
//      if(::is_null(puserinteractionEnablePrompt) || estatus == ::success)
//      {
//
//         return estatus;
//
//      }
//
//      manual_reset_event ev;
//
//      puserinteractionEnablePrompt->message_box("You gonna be prompted to enable Accessibility for \""+m_psystem->m_papplicationMain->m_strAppName+"\" to enable keyboard monitoring.",
//                     "ios Click", e_message_box_ok)->then(
//                                                           [this, &ev,puserinteractionEnablePrompt](auto & sequence)
//                                                           {
//
//                        auto estatus = ::keyboard_hook::is_enabled(true);
//
//                        if(estatus.succeeded())
//                        {
//
//                           ev.set_event();
//
//                           return;
//
//                        }
//                        else
//                        {
//
//                           while(estatus == error_need_restart_application_to_activate_feature)
//                           {
//
//                              ::preempt(1_s);
//
//                              estatus = ::keyboard_hook::is_enabled(false);
//
//                              //output_debug_string("todo restart application");
//
//                              //m_psystem->m_papplicationMain->_001TryCloseApplication();
//
//                           }
//
//                        }
//
//                        output_debug_string("loop ended");
//
//                        ev.set_event();
//
//                     });
//
//      //}
//
//      ev.wait();
//
//      estatus = ::keyboard_hook::is_enabled(false);
//
//      return estatus;
//
////      auto estatus = keyboard_hook::check_system_permission(::is_set(puserinteractionEnablePrompt));
////
////      if(estatus == error_need_restart_application_to_activate_feature)
////      {
////
////         message_box(puserinteractionEnablePrompt, "Restart ios Click?\n\nIf you have just enabled Accessibility and want the setting to be effective, ios Click should be restarted.",
////                     "ios Click", e_message_box_yes_no).then(
////                                                           [](auto & sequence)
////                                                           {
////
////                        output_debug_string("todo restart application");
////
////                     });
////
////      }
//
//   }
//
//
//   ::e_status node::install_keyboard_hook(::matter * pmatterListener)
//   {
//
//      auto estatus = ::keyboard_hook::install(pmatterListener);
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;
//
//   }
//
//
//   ::e_status node::uninstall_keyboard_hook(::matter * pmatterListener)
//   {
//
//      auto estatus = ::keyboard_hook::uninstall(pmatterListener);
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;
//
//   }
//
//
//   ::e_status node::install_mouse_hook(::matter * pmatterListener)
//   {
//
//      auto estatus = ::mouse_hook::install(pmatterListener);
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;
//
//   }
//
//
//   ::e_status node::uninstall_mouse_hook(::matter * pmatterListener)
//   {
//
//      auto estatus = ::mouse_hook::uninstall(pmatterListener);
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;
//
//   }



//   void node::implement(::pointer < ::acme::node > & pnode, ::pointer < class ::acme::system > & psystem)
void node::on_system_main()
   {
      
      //auto psystem = m_psystem->m_papexsystem;
      
      auto argc = platform()->m_argc;
      
      auto argv = platform()->m_argv;
      
      //      auto papp = psystem->m_pappStartup;
      //
      //      void * papp = (void *) (::app *) papplication;
      
      ui_application_main(argc, argv, nullptr);
      
      //return psystem->m_estatus;
      
   }


::pointer < ::conversation > node::create_new_message_box_conversation()
   {

      return __create_new < class ::windowing_ios::message_box >();

   }



} // namespace node_ios




//extern class ::acme::system * get_system();
//
//void os_on_will_finish_launching()
//{
//
//auto psystem = get_system();
//
//psystem->m_pnode->_will_finish_launching();
//
//}

