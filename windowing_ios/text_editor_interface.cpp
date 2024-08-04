//
//  text_editor_interface.cpp
//  windowing_ios
//
//  Created by Camilo Sasuke Thomas Borregaard Sørensen on 01/06/22. 21:45
//
#include "framework.h"
#include "window.h"
#include "text_editor_interface.h"
#include "aura/user/user/interaction_impl.h"


namespace windowing_ios
{


   text_editor_interface::text_editor_interface()
   {
      
      
   }


   text_editor_interface::~text_editor_interface()
   {


   }


   void text_editor_interface::set_input_method_manager_selection(strsize iBeg, strsize iEnd, strsize iCandidateStart, strsize iCandidateEnd)
   {
      

   }


//   void text_editor_interface::set_input_method_manager_candidate_position(strsize iStart, strsize iEnd)
//   {
//
//   }


   void text_editor_interface::synchronize_input_method_manager_with_selection_end()
   {


   }


   void text_editor_interface::set_editor_selection(strsize iBeg, strsize iEnd)
   {

      auto pwindow = m_pwindow;
      
      if(pwindow)
      {
         
         auto len = pwindow->ios_window_get_text_length();
         
         ::string str;
         
         auto psz = str.get_buffer(len);
         
         pwindow->ios_window_get_text(psz, len);
         
         str.release_buffer(len);
////         
////         wstring wstr(str);
         
         auto iUnicodeBeg = ansi_to_wd32_len(str, iBeg);
         
         auto iUnicodeEnd = ansi_to_wd32_len(str, iEnd);
         
         pwindow->ios_window_set_sel(iUnicodeBeg, iUnicodeEnd);
          
      }

   }


   void text_editor_interface::set_editor_text(const ::string& strText)
   {

      auto pwindow = m_pwindow;
      
      if(pwindow)
      {
         
         pwindow->ios_window_set_text(strText);
          
      }

   }


   void text_editor_interface::show_software_keyboard()
   {
       
       auto pwindow = m_pwindow;
       
       if(pwindow)
       {
           
           auto puserinteractionimpl = pwindow->m_puserinteractionimpl;
           
           if(puserinteractionimpl)
           {
               
               auto puserinteraction = puserinteractionimpl->m_puserinteractionKeyboardFocus;
               
               if(puserinteraction)
               {
                   
                   auto rectangle = puserinteraction->window_rectangle();
                   string strText;
                   
                   puserinteraction->get_text(strText);
                   
                   strsize iSelBeg = 0;
                   
                   strsize iSelEnd = 0;
                   
                   puserinteraction->get_text_selection(iSelBeg,iSelEnd);
                   
                   pwindow->ios_window_edit_on_set_focus(rectangle.left(), rectangle.top(), rectangle.right(),
                                                         rectangle.bottom(),
                          strText,       iSelBeg,
                                                         iSelEnd);
//
               }
               
           }
           
           
       }

//       m_pwindow->m_puserinteractionimpl->m_puserinteractionKeyboardFocus;
       

   }


   void text_editor_interface::hide_software_keyboard()
   {
          
       auto pwindow = m_pwindow;
       
       if(pwindow)
       {
           
           auto puserinteractionimpl = pwindow->m_puserinteractionimpl;
           
           if(puserinteractionimpl)
           {
               
               auto puserinteraction = puserinteractionimpl->m_puserinteractionKeyboardFocus;
               
               if(!puserinteraction)
               {
                   
                   pwindow->ios_window_edit_on_kill_focus();
//
               }
               
           }
           
           
       }

   //       m_pwindow->m_puserinteractionimpl->m_puserinteractionKeyboardFocus;
          



   }


} // namespace windowing_ios



