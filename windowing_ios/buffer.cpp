#include "framework.h"
#include "_.h"
#include "buffer.h"
//#include "operating_system/_operating_system.h"
//#include "aura/os/android/window_android.h"
//#include <native_window.h>


#define LOG_TAG "buffer(native)"


namespace windowing_ios
{


   buffer::buffer()
   {

      //m_cairoSource = nullptr;
      //m_cairosurfaceSource = nullptr;

   }


   buffer::~buffer()
   {
      
      destroy_buffer();

   }


   ::draw2d::graphics* buffer::on_begin_draw()
   {

      auto& pimage = get_buffer_image();

      auto sizeWindow = window_size();

      //LOGI("on_begin_draw");

      //if (pimage->size() != sizeWindow)
      {

         //         if(pimage->size().area() < sizeWindow.area())
         //         {
         //
         //            ::size_i32 sizeImage(1920, 1080);
         //
         //            if(sizeWindow.area() > sizeImage.area())
         //            {
         //
         //               sizeImage = sizeWindow;
         //
         //            }
         //
         //

         //         if(sizeWindow.cx == 1)
         //         {
         //
         //            printf("cx=1");
         //
         //         }
         //         else
         //         {
         //            printf("cx!=1");
         //
         //         }

         //auto sizeMonitor = ::size_i32(1920, 1080);


         //pimage->create(sizeWindow);
         // 
         pimage->create(sizeWindow);
         //if (!pimage->create(sizeWindow))
         //{

         //   return nullptr;

         //}

//         }
//
//         if(pimage->size().area() > sizeWindow.area())
//         {
//
//            pimage->map();
//
//            pimage->m_iScan = sizeWindow.width() * sizeof(::color32_t);
//
//            pimage->m_size = sizeWindow;
//
//         }
//
      }

      if (!pimage)
      {

         return nullptr;

      }

      return pimage->g();

   }



   bool buffer::update_buffer(const ::size_i32 & size, int iStrideParam)
   {

      //destroy_buffer();

      synchronous_lock synchronouslock(mutex());

      //int w;

      //int h;


      //w = ANativeWindow_getWidth(m_pimpl->m_oswindow->m_engine.app->window);

      //h = ANativeWindow_getHeight(m_pimpl->m_oswindow->m_engine.app->window);

      //ANativeWindow_setBuffersGeometry(m_pimpl->m_oswindow->m_engine.app->window, w, h, WINDOW_FORMAT_RGBA_8888);

      ::graphics::double_buffer::update_buffer(size, iStrideParam );

      return true;

   }





   void buffer::destroy_buffer()
   {

      ::graphics::double_buffer::destroy_buffer();


   }


   bool buffer::update_screen(::image * pimage)
   {

//      auto pdriver = ::operating_system_driver::get();
//
//      LOGI("m_bRedraw = true");
//
//      pdriver->m_bRedraw = true;
      
      auto pwindow = (::windowing_ios::window *) m_pimpl->m_puserinteraction->window()->m_pWindow2;
      
      pwindow->ios_window_redraw();

      //ANativeWindow_Buffer buffer;

      //ARect r;

      //rectangle.left = 0;
      //rectangle.top = 0;
      //rectangle.right = pimage->width();
      //rectangle.bottom = pimage->height();

      //__zero(buffer);

      //ANativeWindow_lock(m_pimpl->m_oswindow->m_engine.app->window, &buffer, rectangle);

      ///**
      //* Unlock the window's drawing surface after previously locking it,
      //* posting the new buffer to the display.
      //*/


      //::copy_colorref(pimage->width(), pimage->height(), (color32_t *)buffer.bits, pimage->width() * sizeof(color32_t), pimage->get_data(), pimage->scan_size());

      //ANativeWindow_unlockAndPost(m_pimpl->m_oswindow->m_engine.app->window);

      return true;

   }


} // namespace windowing_ios



