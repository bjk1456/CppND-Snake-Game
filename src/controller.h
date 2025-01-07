#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "garter.h"
#include "cobra.h"

class Controller {
 public:
  void HandleInput(bool &running, Garter &garter) const;
  void HandlePredatorInput(bool &running, Cobra &cobra) const;

 private:
  void ChangeDirection(Garter &garter, Garter::Direction input,
                       Garter::Direction opposite) const;

   void HandlePredatorMovement(Cobra &cobra, Cobra::Direction input,
                       Cobra::Direction opposite) const;
};

#endif