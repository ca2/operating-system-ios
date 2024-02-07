// Create on 2021-03-21 20:00 <3ThomasBS_ // for Linux(question)
// Recreated on 2021-05-16 15:05 <3ThomasBS_ // for macOS
#include "framework.h"
#include "acme_directory.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_file.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/application.h"
#include "acme/primitive/primitive/url.h"
#include "acme/primitive/time/_text_stream.h"
#include "acme_apple/file_listing_handler.h"


char * ios_app_library_folder();


char * ios_app_document_folder();

char * ios_app_document_folder(const char * pszAppCloudContainerIdentifier);

//char ** ns_app_cloud_enumerate(const char * pszPath, const char * pszAppCloudContainerIdentifier);

namespace acme_ios
{

   
   acme_directory::acme_directory()
   {
      
      m_pathLibrary = ::string_from_strdup(ios_app_library_folder());
      

      m_pplatformdir = this;

   }


   acme_directory::~acme_directory()
   {


   }


   void acme_directory::on_initialize_particle()
   {
      
      ::acme_apple::acme_directory::on_initialize_particle();
      
   //   ::string strAppIdForIdentifier;
   //
   //   strAppIdForIdentifier = application()->m_strAppId;
   //
   //   strAppIdForIdentifier.find_replace("/",".");
   //   strAppIdForIdentifier.find_replace("_","-");
   //
   //   ::string strContainerIdentifier;
   //   
   //   strContainerIdentifier = "iCloud.com." + strAppIdForIdentifier;

      //m_pathDocument = ::string_from_strdup(ios_app_document_folder(strContainerIdentifier));

      m_pathDocument = app_cloud_document();
      
      m_pathIosAppDocumentFolder = ::string_from_strdup(ios_app_document_folder());
      
   }


   ::file::path acme_directory::__ios_app_document_folder()
   {
      
      return m_pathIosAppDocumentFolder;
      
   }


bool acme_directory::has_app_cloud_document(const char * pszAppCloudContainerIdentifier)
{
   
   ::string strAppCloudContainerIdentifier;
   
   strAppCloudContainerIdentifier = acmepath()->app_cloud_container_identifier(pszAppCloudContainerIdentifier);
   
   auto p = ios_app_document_folder(strAppCloudContainerIdentifier);
   
   if(::is_set(p))
   {
      
      ::free(p);
      
      return true;
      
   }
   
   return false;
//   if(acmedirectory()->has_app_cloud_document())
//   {
//      
//      ::file::path & path = listing.insert_at(0, "icloud://");
//
//      path.m_iDir = 1;
//
//      listing.m_straTitle.insert_at(0, unitext("iCloud"));
//
//   }

   
}


bool acme_directory::defer_enumerate_protocol(::file::listing& listing)
{
   
   ::file::path pathFinal = listing.m_pathFinal;
   
   if(pathFinal.is_empty())
   {
      
      pathFinal = m_pcontext->defer_process_path(listing.m_pathUser);
      
   }
   
   if(pathFinal.begins_eat("icloud://"))
   {
      
      if(has_app_cloud_document())
      {
      
         const char * pend = nullptr;
      
         auto pathServer = pathFinal.get_word("/", &pend);
      
         if(pathServer.is_empty())
         {
            
            
            ::file::path path;
            
            path = app_cloud_document();

            listing.m_eflag = ::file::e_flag_folder;
            
            path.m_iDir = 1;
            
            listing.defer_add(path);
            
         }
         else
         {
            
            auto strPath = pathServer;
            
            if(strPath.begins_eat(pathServer))
            {
               
               strPath.trim_left("/");
               
               auto pfilelistinghandler = __allocate < ::acme_apple::file_listing_handler >(listing);
               
               pfilelistingcallback->initialize(this);
               
               ::string strFolder;
               
               strFolder = strPath;
               
               ::string strAppCloudContainerIdentifier;
               
               strAppCloudContainerIdentifier = pathServer;
               
               auto start = ::time::now();
               
               pfilelistingcallback->_start_listing(strFolder, strAppCloudContainerIdentifier);
               
               pfilelistingcallback->m_manualresetevent.wait(1_minute);
               
               information() << "Got " << listing.size() << " items!!";
               for(auto & path : listing)
               {               information() << "Got :" << path;
                  
               }
               information() << "Got after certain time: " << start.elapsed();
               //            ::string_array stra;
               //            
               //            stra.c_add(ppsza);
               //            
               //            for(auto & str:stra)
               //            {
               //             
               //               ::file::path path;
               //               
               //               path = str;
               //               listing.defer_add(path);
               //               
               //            }
               
            }
            
         }
         
      }
      
   }
   
   return false;
   
}


   string acme_directory::dir_root()
   {

      return __ios_app_document_folder() / ".config/ca2";

   }


   ::file::path acme_directory::get_memory_map_base_folder_path() 
   {

      return __ios_app_document_folder() / ".config/ca2/memory_map";

   }


//   ::file::path acme_directory::home()
//   {
//
//      return getenv("HOME");
//
//   }


   ::file::path acme_directory::program_data()
   {

      return __ios_app_document_folder() / "application";

   }


   ::file::path acme_directory::roaming()
   {

      return __ios_app_document_folder() / "Library/Application Support";

   }


   ::file::path acme_directory::appdata()
   {

      return ca2roaming() / "appdata" / application()->m_strAppId;

   }


   ::file::path acme_directory::public_system()
   {

      return public_root() / "system";

   }


   ::file::path acme_directory::system()
   {

      return ca2roaming() / "system";

   }


   ::file::path acme_directory::config()
   {

      return ca2roaming() / "config";

   }


   ::file::path acme_directory::local()
   {

      return ca2roaming() / "local";

   }


   ::file::path acme_directory::sensitive()
   {

   #ifdef LINUX

      return "C:\\sensitive\\sensitive";

   #else

      return "/sensitive/sensitive";

   #endif

   }


   string acme_directory::system_short_name()
   {

   #ifdef _UWP

      return "metro";

   #else

      ::file::path pathSystemShortName = localconfig() / "system_short_name.txt";

      return m_pacmefile->as_string(pathSystemShortName).trimmed();

   #endif

   }


   ::file::path acme_directory::relative(::file::path path)
   {

      path.find_replace(":", "");

      path.case_insensitive_ends_eat(".exe");

      return path;

   }

   #ifdef _UWP


   ::file::path acme_directory::app_relative()
   {

      return "";

   }


   #else
//
//
//   ::file::path acme_directory::app_relative()
//   {
//
//      ::file::path path = m_psystem->m_pacmefile->module();
//
//      path = relative(path);
//
//      return path;
//
//   }


   #endif



   ::file::path acme_directory::inplace_install(string strAppId, string strPlatform, string strConfiguration)
   {

   #ifdef LINUX_DESKTOP

      ::file::path path;

      string strFolder;

      strsize iFind = strAppId.find('/');

      if (strPlatform.compare_ci("win32") == 0 || strPlatform.compare_ci("x86") == 0)
      {

         path = program_files_x86();

      }
      else
      {
         path = program_files_x86();


         path = program_files();

      }

      if (iFind < 0)
      {

         path /= strAppId;

      }
      else
      {

         path /= strAppId.Left(iFind);

         path /= strAppId.Mid(iFind + 1);

      }

      return path;

   #elif defined(ANDROID)

      return pacmedirectory->roaming();

   #else

      return acmefile()->module().folder(4);

   #endif

   }


   ::file::path acme_directory::inplace_matter_install(string strAppId, string strPlatform, string strConfiguration)
   {

   #ifdef LINUX_DESKTOP

      ::file::path path;

      string strFolder;

      strsize iFind = strAppId.find('/');

      path = ca2roaming();

      path /= "_matter";

      return path;

   #elif defined(ANDROID)

      return pacmedirectory->roaming();

   #else

      return acmefile()->module().folder(4);

   #endif


   }


   ::file::path acme_directory::install()
   {

      if (m_pathInstallFolder.is_empty())
      {

         return default_install();

      }

      return m_pathInstallFolder;

   }


   ::file::path acme_directory::default_install()
   {

   #ifdef ANDROID

      return pacmedirectory->roaming();

   #elif defined(__APPLE__)

      return acmefile()->module().folder(3);

   #else

      return m_psystem->m_pacmepath->app_module().folder(4);

   #endif

   }


   ::file::path acme_directory::beforeca2()
   {

      return file_path_folder(install());

   }






   #ifdef LINUX_DESKTOP


   #include <Shlobj.h>


   ::file::path acme_directory::program_files_x86()
   {

      wstring wstrModuleFolder(get_buffer, sizeof(unichar) * 8);

      wstring wstrModuleFilePath(get_buffer, sizeof(unichar) * 8);

      wcscpy(wstrModuleFilePath, _wgetenv(L"PROGRAMFILES(X86)"));

      if (wcslen(wstrModuleFilePath) == 0)
      {

         SHGetSpecialFolderPathW(nullptr, wstrModuleFilePath, CSIDL_PROGRAM_FILES, false);

      }

      wstrModuleFilePath.trim_right(L"\\/");

      wcscpy(wstrModuleFolder, wstrModuleFilePath);

      return string(wstrModuleFolder);

   }


   ::file::path acme_directory::program_files()
   {

      wstring wstrModuleFolder(get_buffer, sizeof(unichar) * 8);

      wstring wstrModuleFilePath(get_buffer, sizeof(unichar) * 8);

      wcscpy(wstrModuleFilePath, _wgetenv(L"PROGRAMW6432"));

      if (wcslen(wstrModuleFilePath) == 0)
      {

         SHGetSpecialFolderPathW(nullptr, wstrModuleFilePath, CSIDL_PROGRAM_FILES, false);

      }

      wstrModuleFilePath.trim_right(L"\\/");

      wstrModuleFolder = wstrModuleFilePath;

      return string(wstrModuleFolder);



   }


   #else


   ::file::path acme_directory::program_files_x86()
   {

      ::file::path path("/opt/ca2");

      return path;

   }


   ::file::path acme_directory::program_files()
   {

      ::file::path path("/opt/ca2");

      return path;

   }


   #endif


   ::file::path acme_directory::stage(string strAppId, string strPlatform, string strConfiguration)
   {

      return inplace_install(strAppId, strPlatform, strConfiguration) / "time" / strPlatform / strConfiguration;

   }


//   #ifdef LINUX


   ::file::path acme_directory::home()
   {

      return m_pathDocument;

   }


//   #endif


   #if defined(_UWP) || defined(__APPLE__) || defined(LINUX) || defined(ANDROID)


//   ::file::path acme_directory::bookmark()
//   {
//
//      auto psystem = m_psystem;
//
//      auto pacmedirectory = psystem->m_pacmedirectory;
//
//      return pacmedirectory->localconfig() / "bookmark";
//
//   }


   #endif


   #ifdef _UWP


   ::file::path acme_directory::home()
   {

      return "";

   }


   #endif




   void acme_directory::set_path_install_folder(const ::string & strPath)
   {

      m_pathInstallFolder = strPath;

   }


   ::file::path acme_directory::bookmark()
   {

      return localconfig() / "bookmark";

   }





   ::file::path acme_directory::sys_temp()
   {

      return appdata() / "time";

   }


   //::string acme_directory::dir_root()
   //{

   //   return "";

   //}


   //::file::path acme_directory::home()
   //{

   //   return "";

   //}


   //::file::path acme_directory::program_data()
   //{

   //   return "";

   //}


   ::file::path acme_directory::ca2appdata()
   {

      return ca2roaming() / "appdata";

   }



   ::file::path acme_directory::public_root()
   {

      return program_data() / "ca2";

   }

   ::file::path acme_directory::ca2roaming()
   {

      return roaming() / "ca2";

   }


   ::file::path acme_directory::localconfig()
   {

      return ca2roaming() / "localconfig";

   }


   ::file::path acme_directory::module()
   {

      return ::acme_directory::module();

   }

   //
   //::file::path acme_directory::base_module()
   //{
   //
   //   return "";
   //
   //}
   //

   //::file::path acme_directory::ca2_module()
   //{
   //
   //   return "";
   //
   //}
   //
   ::file::path acme_directory::archive()
   {

      return "";

   }



   ::file::path acme_directory::tool()
   {

      return "";

   }


   //::file::path acme_directory::roaming()
   //{

   //   return "";

   //}


   ::file::path acme_directory::pathfind(const string& pszEnv, const string& pszTopic, const string& pszMode)
   {

      ::file::path_array stra;

      stra.add_tokens(pszEnv, ":", false);

      string strCandidate;

      for (i32 i = 0; i < stra.get_count(); i++)
      {

         strCandidate = stra[i] / pszTopic;

         //if (m_pcontext->m_papexcontext->file().exists(strCandidate))
         if (file_exists(strCandidate))
         {

            return strCandidate;

         }

      }

      return "";

   }


   //::file::path acme_directory::get_memory_map_base_folder_path()
   //{

   //   return "";

   //}


   ::file::path acme_directory::user_appdata_local()
   {

      //return _shell_get_special_folder_path(CSIDL_LOCAL_APPDATA);

      return home() / ".config";

   }


} // namespace acme_ios



   
