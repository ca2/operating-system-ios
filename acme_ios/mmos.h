




#include "acme/prototype/prototype/atomic.h"
#include "acme/prototype/prototype/interlocked_count.h"
//#include "acme/prototype/prototype/matter.h"


@interface mmos : NSObject
{
   
   @public  char ** m_ppszWallpaper;
   @public   long long m_llWallpaper;
   @public  int m_iIcon;
   @public  unsigned int * m_picon;
   @public   int m_cxIcon;
   @public   int m_cyIcon;
   @public   int m_iScanIcon;
   @public  const char * m_pszIcon;
   @public NSRecursiveLock *theLock;
   @public ::platform::system * m_psystem;

   
}

- (id)get;

//- (void)get_user_wallpaper:(void **)charpp forScreen:(UIScreen *) s;

//- (void)get_user_wallpaper:(void *)charppp getCount:(void *) pll;

//- (void)desktopImageChanged:(NSNotification *)notification;

- (void)applicationActivity:(NSNotification *)notification;

//- (void)monitorWallpaper;

//- (void)deferWallpaper:(NSTimer *)timer;

- (void)monitorIconForFile;

- (void)deferIconForFile:(NSTimer *)timer;

-(void)runRunnableOnMainThread:(::matter *)pobjectTask;

-(void)runRunnable:(::matter *)pobjectTask;

-(NSURL *)browse_folder : (NSURL *) directoryURL canCreateDirectories: (bool) bCanCreateDirectories;
-(NSArray < NSURL * > *)browse_file_open : (NSURL **) startDir multi: (bool) b;
@end

