//
//  windowing.hpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 2021-05-21 01:59 <3ThomasBS_!!
//
#pragma once


#include "acme_windowing_uikit/windowing.h"
#include "aura/windowing/sandbox/windowing.h"


namespace windowing_ios
{


    class CLASS_DECL_WINDOWING_IOS windowing :
      virtual public ::sandbox_windowing::windowing,
virtual public ::uikit::acme::windowing::windowing
   {
   public:
      
      
      ::pointer < ::windowing::display >           m_pdisplay;
      
      //::pointer < class window >                   m_pwindowActive;
      
      //::pointer < class window >                   m_pwindowCapture;
      
      //::pointer < class window >                   m_pwindowApplicationHost;
      
      ///::pointer < class window >
         //m_pwindowKeyboardFocus;
      
      //::pointer < host_interaction >               m_phostinteraction;
      
      //map < void *, ::pointer < class window > >   m_nsmap;

      ::pointer < text_editor_interface >          m_ptexteditorinterface;

      
      windowing();
      ~windowing() override;
      
      
      void initialize(::particle * pparticle) override;
      
       
       void initialize_windowing() override;
      
      ::windowing::text_editor_interface * get_text_editor_interface() override;

      
     void defer_initialize_host_window(const ::int_rectangle* lpcrect) override;
     
      ::acme::windowing::window * get_application_host_window() override;
      
      void clear_active_window(::thread *, ::windowing::window *) override;
//      ::windowing::window * new_window(::user::interaction_impl *pimpl) override;

      void os_menu_item_enable(void * pitem, bool bEnable) override;
      void os_menu_item_check(void * pitem, bool bCheck) override;

      void defer_create_main_menu(const string_array & straParent, const string_array & straMenu, const string_array & straId) override;
      
      ::pointer < ::windowing::cursor > get_cursor(enum_cursor ecursor) override;
      
      //void windowing_post(const ::procedure & procedure) override;
      
      ::acme::windowing::window * window(oswindow oswindow) override;

      ::windowing::display * display() override;
      
       
       void windowing_application_main_loop() override;
       void windowing_post_quit() override;
//      ::windowing::window * get_active_window(::thread * pthread) override;

      //virtual bool post_ui_message(::message::base * pbase);
      
      //void release_mouse_capture() override;
      
      //::windowing::window * get_keyboard_focus(::thread *) override;

      
      
      void _defer_dock_application(int_bool bDock);
      
      void _user_send(const ::procedure & procedure) override;


      void _user_post(const ::procedure & procedure) override;

//      void clear_keyboard_focus(::windowing::window* pwindowGainingFocusIfAny) override;
//       
//      ::pointer < ::conversation > create_new_message_box_conversation() override;
      
      bool defer_realize(         ::pointer < ::reified < ::message_box > > & preifiedMessageBox, ::message_box * p) override;

       ::string _ns_application_delegate_class() override;

   };
      

} // namespace windowing_ios




