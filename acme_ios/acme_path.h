// Create on 2021-03-22 09:12 <3ThomasBS_ // at Linux(Question.)
// Recreated on 2021-05-16 15:07 <3ThomasBS_ // for macOS
#pragma once


#include "acme_apple/acme_path.h"


namespace acme_ios
{


   class CLASS_DECL_ACME_MACOS acme_path :
      virtual public ::acme_apple::acme_path
   {
   public:


      acme_path();
      ~acme_path() override;


      
      void create_symbolic_link(const char * pszLink, const char * pszSource) override;

      bool is_symbolic_link(const char * pszLink) override;

      ::file::path symbolic_link_destination(const char * pszLink) override;

      bool has_custom_icon(const char * path) override;
      

   };


} // namespace acme_ios



