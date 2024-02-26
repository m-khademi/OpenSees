/* ******************************************************************
***
**    OpenSees - Open System for Earthquake Engineering Simulation **
**          Pacific Earthquake Engineering Research Center **
** **
** **
** (C) Copyright 1999, The Regents of the University of California **
** All Rights Reserved. **
** **
** Commercial use of this program without express permission of the **
** University of California, Berkeley, is strictly prohibited.  See **
** file 'COPYRIGHT'  in main directory for information on usage and **
** redistribution,  and for a DISCLAIMER OF ALL WARRANTIES. **
** **
** Developed by: **
**   Frank McKenna (fmckenna@ce.berkeley.edu) **
**   Gregory L. Fenves (fenves@ce.berkeley.edu) **
**   Filip C. Filippou (filippou@ce.berkeley.edu) **
** **
** ******************************************************************
*/

// Minjie
#ifndef CurvedPipe_h
#define CurvedPipe_h

#include "Pipe.h"

class Node;

// CurvedPipe element
class CurvedPipe : public Pipe {
   protected:
    Vector center;
    double radius;
    double theta0;
    double tolWall;

   public:
    CurvedPipe();
    CurvedPipe(int tag, int Nd1, int Nd2, CrdTransf &theTransf,
               PipeMaterial &mat, PipeSection &sect, const Vector &c,
               double to = 0.0, double pre = 0.0, int cMass = 0,
               double tol = 0.1);

    ~CurvedPipe();

    const char *getClassType(void) const;

    void setDomain(Domain *theDomain);

    void zeroLoad(void);

   protected:
    int flexibility(Matrix &fb);
    int basicDeform(Vector &ub0);
    int getTheta0();
};

#endif
