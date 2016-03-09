// ==============================================
// 
//
//
// ==============================================
#ifndef _BETACORE_BETA_H_
#define _BETACORE_BETA_H_

namespace betacore
{
  
  class beta
  {
      public:
            // Returns classes name
            std::string getName();
            // Get Number A & B -> AB
            int getNumber( int a, int b);
        
            int majorVersion ();
            int minorVersion ();
            int patchVersion();
            
            std::string about();
  };

}

#endif