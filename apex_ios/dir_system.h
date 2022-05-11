#pragma once


namespace apex_ios
{
   
   
   class CLASS_DECL_APEX dir_system :
   virtual public ::dir_system
   {
   public:
      
      
      
      ::file::path            m_strTimeFolder;
      ::file::path            m_strNetSeedFolder;
      ::file::path            m_strCommonAppData;
      ::file::path            m_strAppData;
      ::file::path            m_strPrograms;
      ::file::path            m_strCommonPrograms;
      ::file::path            m_strCa2AppData;
      ::file::path            m_pathHome;
      
      dir_system();
      virtual ~dir_system();
      
      virtual void initialize(::object * pobject) override;
      
      //virtual void update_module_path();
      
   };
   
   
} // namespace apex_ios



