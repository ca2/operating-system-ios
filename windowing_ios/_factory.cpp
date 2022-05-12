//
//  _factory.cpp
//  windowing_macos
//
//  Created by Camilo Sasuke on 2021-05-20 01:19 <3ThomasBS_!!
//
#include "framework.h"
#include "buffer.h"

extern "C"
void aura_ios_factory(::factory::factory * pfactory);


extern "C"
void windowing_ios_factory(::factory::factory * pfactory)
{
   

   aura_ios_factory(pfactory);

   
   pfactory->add_factory_item < windowing_ios::windowing, ::windowing::windowing > ();


   pfactory->add_factory_item < windowing_ios::window, ::windowing::window > ();

   pfactory->add_factory_item < windowing_ios::node, ::acme::node > ();
   pfactory->add_factory_item < windowing_ios::display, ::windowing::display > ();
   pfactory->add_factory_item < windowing_ios::monitor, ::windowing::monitor > ();
   pfactory->add_factory_item < windowing_ios::buffer, ::graphics::graphics > ();
//   pfactory->add_factory_item < windowing_ios::cursor, ::windowing::cursor > ();
//   pfactory->add_factory_item < windowing_ios::notify_icon, ::user::notify_icon > ();
   pfactory->add_factory_item < windowing_ios::icon, ::windowing::icon > ();

   pfactory->add_factory_item < ::imm_client, ::user::text_composition_client > ();

   pfactory->add_factory_item < windowing_ios::keyboard, ::windowing::keyboard > ();

   pfactory->add_factory_item < windowing_ios::copydesk, ::user::copydesk > ();

}



