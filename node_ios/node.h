//
//  node.hpp
//  node_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/Oct/22 09:24
//
#pragma once


#include "aura_ios/node.h"


namespace node_ios
{


   class CLASS_DECL_NODE_IOS node :
      virtual public ::aura_ios::node
   {
   public:
   
      
      //void implement(::pointer < ::acme::node > & pnode, ::pointer < ::acme::system > & psystem) override;

      void on_system_main() override;
      
      void _will_finish_launching() override;
      
      void on_start_system() override;
      //bool is_keyboard_hook_enabled(::user::interaction * puserinteractionEnablePrompt) override;

//
//      void install_keyboard_hook(::matter * pmatterListener) override;
//      void uninstall_keyboard_hook(::matter * pmatterListener) override;
//
      
      
//      void implement(::pointer < ::acme::node > & pnode, ::pointer < ::acme::system > & psystem) override;
//
//      
//      void _will_finish_launching() override;
//      
//      void on_start_system() override;
      //bool is_keyboard_hook_enabled(::user::interaction * puserinteractionEnablePrompt) override;

//
//      void install_keyboard_hook(::matter * pmatterListener) override;
//      void uninstall_keyboard_hook(::matter * pmatterListener) override;
//
//      void install_mouse_hook(::matter * pmatterListener) override;
//      void uninstall_mouse_hook(::matter * pmatterListener) override;
//
       ::pointer < ::conversation > create_new_message_box_conversation() override;

//      void install_mouse_hook(::matter * pmatterListener) override;
//      void uninstall_mouse_hook(::matter * pmatterListener) override;
//
//       ::pointer < ::conversation > create_new_message_box_conversation() override;

   
   };


} // namespace node_ios



