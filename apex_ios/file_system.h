#pragma once


namespace apex_ios
{


   class CLASS_DECL_APEX file_system :
      virtual public ::file_system
   {
   public:


      ::file::path            m_strUserFolder;
      ::file::path            m_pathModule;
      //::file::path            m_pathCa2Module;
      

      file_system();
      ~file_system() override;

      
      void initialize(::object * pobject) override;
      

//      virtual void update_module_path() override;
      
      
      

   };


} // namespace apex_ios



