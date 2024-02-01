#pragma once


#include "acme/filesystem/filesystem/dir_context.h"


namespace acme_ios
{
   

   class dir_system;
   class file_system;

   
   class CLASS_DECL_ACME dir_context :
   virtual public ::dir_context
   {
   public:
      
      
      ::pointer < dir_system >      m_pdirsystem;
      ::pointer < file_system >     m_pfilesystem;

      
      dir_context();
      ~dir_context() override;
      
      
      virtual void initialize(::particle * pparticle) override;
      //virtual void update_module_path();
      virtual void init_context() override;

      
      // rls fetchs should set a meaningful m_iRelative value at each returned path
      //bool enumerate(::file::listing & path) override;
      
      
//      virtual bool  is(const ::file::path & path) override;
//      virtual bool  is_inside(const ::file::path & pathFolder,const ::file::path & path) override;
//      virtual bool  is_inside_time(const ::file::path & path) override;
//      //virtual bool  name_is(const ::file::path & path) override;
//      virtual bool  has_subdir(const ::file::path & path) override;
      
      virtual ::file::listing & root_ones(::file::listing & listing) override;
//      virtual bool create(const ::file::path & path) override;
//      virtual bool erase(const ::file::path & path, bool bRecursive = true) override;
      
      
      //virtual ::file::path name(const ::file::path & path);
      
      virtual ::file::path time() override;
      virtual ::file::path stage() override;
      virtual ::file::path stageapp() override;
      //virtual ::file::path netseed() override;

      
      virtual ::file::path module() override;
      //virtual ::file::path ca2module() override;
      virtual ::file::path time_square(const ::string & strPrefix = nullptr, const ::string & strSuffix = nullptr);
      virtual ::file::path time_log();
      
      
      //virtual ::file::path trash_that_is_not_trash(const ::file::path & path) override;
      
      
      
      //virtual ::file::path appdata(const ::string & strAppId = "") override;
      virtual ::file::path commonappdata_root() override;
      
//      virtual ::file::path usersystemappdata(::object * pobject, const char * lpcszPrefix);
//      virtual ::file::path userappdata(::object * pobject);
//      virtual ::file::path userdata(::object * pobject);
//      //virtual ::file::path userfolder(::object * pobject);
//      virtual ::file::path default_os_user_path_prefix(::object * pobject);
//      virtual ::file::path default_userappdata(::object * pobject,const string & lpcszPrefix,const string & lpcszLogin );
//      virtual ::file::path default_userdata(::object * pobject,const string & lpcszPrefix,const string & lpcszLogin);
//      virtual ::file::path default_userfolder(::object * pobject,const string & lpcszPrefix,const string & lpcszLogin);
      virtual ::file::path userquicklaunch() override;
      virtual ::file::path userprograms() override;
      
      virtual ::file::path commonprograms() override;
      
      //virtual bool initialize();
      
      
   };
   
   
} // namespace acme_ios



